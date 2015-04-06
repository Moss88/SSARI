#include "BoolTseitin.h"
#include "BoolVar.h"
#include <string>
#include <fstream>
using std::string;
using std::ofstream;
using std::to_string;

namespace SSARI {

BoolTseitin::BoolTseitin() {}


void BoolTseitin::addOperand(shared_ptr<BoolVar> op) {
        operands.push_back(op);
}



string BoolTseitin::toString() const {
    string equation = "";
    for(auto iter = this->operands.begin(); iter != this->operands.end(); iter++)
        equation += (*iter)->toString();
    return equation;
}

void BoolTseitin::writeXml(xmlpp::Node *parent, string indentation) const {}


bool BoolTseitin::writeToDimacs(string filePath) {

    int refCnt = 0;
    int lineCnt = 1;
    string dimacs;

    for(auto iter  = this->operands.begin(); iter != this->operands.end(); iter++)
    {
        string line;
        line += (*iter)->toDimacs(line, refCnt);
        dimacs += to_string(lineCnt++) + " " + line + "\n";
    }
    // Add Header
    string header = "c Autogen output\np " + to_string(refCnt) + " " + to_string(lineCnt - 1) + "\n";
    string file = header + dimacs;

    // Write to File
    ofstream outFile(filePath);
    if(!outFile.is_open())
        return false;
    outFile << file;
    outFile.close();

    return true;
}


}





