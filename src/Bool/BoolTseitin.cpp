#include "Bool/BoolTseitin.h"
#include "Bool/BoolVar.h"
#include <string>
#include <fstream>
using std::string;
using std::ofstream;
using std::to_string;
using std::runtime_error;

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

    int refCnt = 1;
    int lineCnt = 1;
    string dimacs;

    for(auto iter  = this->operands.begin(); iter != this->operands.end(); iter++)
    {
        string line;
        lineCnt++;
        line += (*iter)->toDimacs(line, refCnt);
        dimacs += line + "0\n";
    }
    // Add Header
    string header = "c Autogen output\np cnf " + to_string(refCnt + 1) + " " + to_string(lineCnt - 1) + "\n";
    string file = header + dimacs;

    // Write to File
    ofstream outFile(filePath);
    if(!outFile.is_open())
        return false;
    outFile << file;
    outFile.close();

    return true;
}

bool BoolTseitin::isSat() {
    if(!this->writeToDimacs("outDimacs.cnf"))
        throw runtime_error("Failed to write Dimacs file");

    // Fork Subprocess
    int status;
    char buffer[256];
    FILE *fp =  popen("lingeling ./outDimacs.cnf", "r");
    while (fgets(buffer, 256, fp) != NULL)
        printf("%s", buffer);
    status = pclose(fp);
    return true;
}


}





