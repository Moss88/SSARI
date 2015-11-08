#include <RegisterFileReader.h>
#include "./Numeric/CConstant.h"
#include "./Numeric/Constraint.h"
#include <libxml++/libxml++.h>
#include <libxml++/attribute.h>
using xmlpp::Attribute;
using xmlpp::Element;
using xmlpp::Node;

using std::to_string;
using std::cout;
using std::endl;
namespace SSARI {

RegisterFileReader::RegisterFileReader()
{

}



string RegisterFileReader::getError() const {
    return this->error;
}

CFunc RegisterFileReader::processNode(const Element* e)
{
    string logicType = e->get_name();
    if(logicType == "CBinary")
    {
        // Fetch Operator
        const Element* opNd = dynamic_cast<const Element*>(e->get_first_child("COperator"));
        if(!opNd)
        {
            error += "No operator found for constraint. ";
            return CFunc();
        }
        Attribute *opType = opNd->get_attribute("operator");
        if(!opType)
        {
            error += "No attribute operator found. ";
            return CFunc();
        }

        // Create Constraint
        COperator op(opType->get_value());

        // Fetch Operands
        const Node* child = e->get_first_child();
        vector<CFunc> operands;

        while(child)
        {
            const Element *cElement = dynamic_cast<const Element*>(child);
            if(cElement && cElement->get_name() != "COperator")
                operands.push_back(this->processNode(cElement));
            child = child->get_next_sibling();
        }

        if(operands.size() != 2)
        {
            error += "CBinary does not contain two operands, instead has " + to_string(operands.size()) + " operands. ";
            return CFunc();
        }

        return CFunc(op, operands[0].getCValue(), operands[1].getCValue());
    }
    else if(logicType == "CConstant")
    {
        shared_ptr<CConstant> constant;
        string value = e->get_attribute_value("value");
        if(value.empty()) {
            error += "Constant has no value. ";
            return CFunc();
        }
        return CFunc(shared_ptr<CConstant>(new CConstant(value)));
    }
    else if(logicType == "COperand")
    {
        error += "Unexpected COperand. ";
        return CFunc();
    }
    else if(logicType == "CVar")
    {
        string name = e->get_attribute_value("name");
        if(name.empty())
        {
            error += "CVar contains no name. ";
            return CFunc();
        }
        string funcName = e->get_attribute_value("funcName");
        string index = e->get_attribute_value("idx");
        return CFunc(name, stoi(index));
    }
    else
    {
        error += "Unexpected Type.";
        return CFunc();
    }
    return CFunc();
}

bool RegisterFileReader::readFile(string filepath, RegisterFile<CFunc> &rf)
{
    xmlpp::DomParser parser;
    //parser.set_validate();
    parser.set_substitute_entities(); //We just want the text to be resolved/unescaped automatically.
    parser.parse_file(filepath);

    if(!parser)
    {
        error += "Failed to load file at " + filepath + ". ";
        return false;
    }

    //Walk the tree:
    const xmlpp::Element* element = parser.get_document()->get_root_node();
    if(element->get_name() != "RegisterFile" )
    {
        error += "File is not a register file. ";
        return false;
    }

    // Iterate through variables
    const Node* nd = element->get_first_child();
    if(!nd)
    {
        error += "Unable to fetch child. ";
        return false;
    }

    while(nd)
    {

        const Element *var = dynamic_cast<const Element*>(nd);
        if(var)
        {

            // Get Name and set CVar
            string name = var->get_attribute_value("name");
            string idx = var->get_attribute_value("idx");
            CVar cVar = CVar(name, stoi(idx));


            // Process All Sub-Nodes
            const Node* childNd = var->get_first_child();
            while(childNd)
            {
                const Element *childConstraint = dynamic_cast<const Element*>(childNd);
                if(childConstraint)
                {
                    CFunc expr = this->processNode(childConstraint);
                    if(expr.isValid())
                    {
                        // Add Variable
                        if(!cVar.getName().empty())
                            rf.setVar(cVar, expr);
                        else if(cVar.getName().empty())
                            error += "Empty CVar Name. ";
                        else
                            error += "Null Constraint. ";
                    }
                }
                childNd = childNd->get_next_sibling();
            }
        }
        nd = nd->get_next_sibling();
    }
    return true;
}
bool RegisterFileReader::fail() const {
    return !this->error.empty();
}

RegisterFileReader::~RegisterFileReader()
{

}

}
