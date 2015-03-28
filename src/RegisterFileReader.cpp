#include <RegisterFileReader.h>
#include <CConstant.h>

using std::cout;
using std::endl;
namespace SSARI {

RegisterFileReader::RegisterFileReader()
{

}



string RegisterFileReader::getError() const {
    return this->error;
}

shared_ptr<CValue> RegisterFileReader::processNode(const Element* e)
{
    string logicType = e->get_name();
    if(logicType == "Constraint")
    {
        // Fetch Operator
        const Element* opNd = dynamic_cast<const Element*>(e->get_first_child("COperator"));
        if(!opNd)
        {
            error += "No operator found for constraint. ";
            return nullptr;
        }
        Attribute *opType = opNd->get_attribute("operator");
        if(!opType)
        {
            error += "No attribute operator found. ";
            return nullptr;
        }

        // Create Constraint
        shared_ptr<Constraint> c = shared_ptr<Constraint>(new Constraint(COperator(opType->get_value())));


        // Fetch Operands
        const Node* child = e->get_first_child();
        while(child)
        {
            const Element *cElement = dynamic_cast<const Element*>(child);
            if(cElement && cElement->get_name() != "COperator")
            {
                shared_ptr<CValue> operand = this->processNode(cElement);
                if(operand)
                    c->addOperand(operand);
            }
            child = child->get_next_sibling();
        }
        return c;
    }
    else if(logicType == "CConstant")
    {
        shared_ptr<CConstant> constant;
        string value = e->get_attribute_value("value");
        if(value.empty()) {
            error += "Constant has no value. ";
            return nullptr;
        }
        constant = shared_ptr<CConstant>(new CConstant(value));
        return constant;
    }
    else if(logicType == "COperand")
    {
        error += "Unexpected COperand. ";
        return nullptr;
    }
    else if(logicType == "CVar")
    {
        string name = e->get_attribute_value("name");
        if(name.empty())
        {
            error += "CVar contains no name. ";
            return nullptr;
        }
        string funcName = e->get_attribute_value("funcName");
        string index = e->get_attribute_value("idx");
        shared_ptr<CVar> cVar = shared_ptr<CVar>(new CVar(name, funcName, stoi(index)));
        return cVar;
    }
    else
    {
        error += "Unexpected Type.";
        return nullptr;
    }
}

bool RegisterFileReader::readFile(string filepath, RegisterFile &rf)
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
    cout << "Root Element Name:" << element->get_name() << endl;
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
            CVar cVar("");
            shared_ptr<Constraint> constraint;

            // Get Name and set CVar
            string name = var->get_attribute_value("name");
            cVar = CVar(name);

            // Process All Sub-Nodes
            const Node* childNd = var->get_first_child();
            while(childNd)
            {
                const Element *childConstraint = dynamic_cast<const Element*>(childNd);
                if(childConstraint && childConstraint->get_name() == "Constraint")
                {
                    shared_ptr<CValue> cVal = this->processNode(childConstraint);
                    if(constraint = dynamic_pointer_cast<Constraint>(cVal))
                        break;
                }
                childNd = childNd->get_next_sibling();
            }

            // Add Variable
            if(!cVar.getName().empty() && constraint)
                rf.setVar(cVar, constraint);
            else if(cVar.getName().empty())
                error += "Empty CVar Name. ";
            else
                error += "Null Constraint. ";

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
