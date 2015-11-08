#ifndef REGISTERFILEREADER_H
#define REGISTERFILEREADER_H

#include "RegisterFile.h"
#include <string>
#include <iostream>

using namespace std;

namespace xmlpp {
	class Node;
	class Element;
}


namespace SSARI {

class RegisterFileReader
{
public:
    RegisterFileReader();
    bool readFile(string filepath, RegisterFile<CFunc> &rf);
    void print_node(const xmlpp::Node* node, unsigned int indentation = 0);
    void print_indentation(unsigned int indentation);
    string getError() const;
    bool fail() const;
    ~RegisterFileReader();
private:
    // Data
    string error;

    // Methods
    CFunc processNode(const xmlpp::Element *child);
};

}
#endif // REGISTERFILEREADER_H


