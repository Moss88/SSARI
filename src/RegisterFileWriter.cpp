#include <RegisterFileWriter.h>
#include <libxml++/document.h>
#include <string>
using std::to_string;
using namespace xmlpp;
namespace SSARI {

RegisterFileWriter::RegisterFileWriter() {

}

bool RegisterFileWriter::writeFile(string path, RegisterFile &rf) {

    try
    {
        Document document;
        document.set_internal_subset("Register_File", "", "regFile.dtd");
        document.set_entity_declaration("xml", xmlpp::XML_INTERNAL_GENERAL_ENTITY,
          "", "example.dtd", "Extensible Markup Language");

        xmlpp::Element* nodeRoot = document.create_root_node("RegisterFile");

        nodeRoot->add_child_text("\n");
        for(auto iter = rf.cbegin(); iter != rf.cend(); iter++)
        {
            Element* e = nodeRoot->add_child("Register");
            e->add_child_text("\n");
            e->add_child_text("\t");
            iter->second.getCValue()->writeXml(e, "\t");
            e->set_attribute("name", iter->first.getName());
            e->set_attribute("funcName", iter->first.getFuncName());
            e->set_attribute("idx", to_string(iter->first.getIndex()));
            e->add_child_text("\n");
            nodeRoot->add_child_text("\n");
        }
        document.write_to_file(path);
      }
      catch(const std::exception& ex)
      {
        std::cout << "Exception caught: " << ex.what() << std::endl;
        return 1;
      }



    return true;
}



RegisterFileWriter::~RegisterFileWriter() {}

}
