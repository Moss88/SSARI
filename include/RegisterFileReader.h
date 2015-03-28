#ifndef REGISTERFILEREADER_H
#define REGISTERFILEREADER_H


#include <libxml++/libxml++.h>
#include <libxml++/attribute.h>
#include <IRNav/RegisterFile.h>
#include <string>
#include <iostream>
using xmlpp::Attribute;
using xmlpp::Element;
using xmlpp::Node;
using namespace std;

namespace BFAST {

class RegisterFileReader
{
public:
    RegisterFileReader();
    bool readFile(string filepath, RegisterFile &rf);
    void print_node(const Node* node, unsigned int indentation = 0);
    void print_indentation(unsigned int indentation);
    string getError() const;
    bool fail() const;
    ~RegisterFileReader();
private:
    // Data
    string error;

    // Methods
    shared_ptr<CValue> processNode(const Element *child);
};

}
#endif // REGISTERFILEREADER_H


