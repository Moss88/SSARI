#include "Bool/BoolTseitin.h"
#include "Bool/BoolValue.h"
#include <string>
#include <fstream>
#include <stdio.h>
#include <unistd.h>

using std::string;
using std::ofstream;
using std::to_string;
using std::runtime_error;

namespace SSARI {

BoolTseitin::BoolTseitin() {}


void BoolTseitin::addOperand(shared_ptr<BoolValue> op) {
        operands.push_back(op);
}



string BoolTseitin::toString() const {
    string equation = "";
    for(auto iter = this->operands.begin(); iter != this->operands.end(); iter++)
        equation += (*iter)->toString();
    return equation;
}

string BoolTseitin::writeToDimacs() {

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

    return file;
}

bool BoolTseitin::isSat() {
    // Clear Refs
    for(auto iter = this->operands.begin(); iter != this->operands.end(); iter++)
        (*iter)->clearRef();

    string file = writeToDimacs();
	
    int p2cFD[2];
    int c2pFD[2];

    pipe(p2cFD);
    pipe(c2pFD);

    FILE *fp = popen("which lingeling", "r");

    char path[256];
    fgets(path, 256, fp);
    pclose(fp);
    string filePath = path;


    // Fork
    if(!fork())
    {
        dup2(c2pFD[1], 1);
        close(c2pFD[0]);
        close(c2pFD[1]);
        dup2(p2cFD[0], 0);
        close(p2cFD[0]);
        close(p2cFD[1]);

        int error = execl((filePath.substr(0,filePath.length() - 1)).c_str(), (filePath.substr(0,filePath.length() - 1)).c_str(), NULL);

        printf("Error: %d", error);
    }
    else
    {
        char buffer[256];

        close(p2cFD[0]);
        close(c2pFD[1]);

        write(p2cFD[1], file.c_str(), file.size());
        close(p2cFD[1]);

        FILE *in = fdopen(c2pFD[0], "r");

        while (fgets(buffer, 256, in))
        {
            if(buffer[0] == 's')
            {
                string str(buffer);
                int idx = str.find("UNSATISFIABLE");
                if(idx == string::npos)
                    return true;
                else
                    return false;
            }
        }
        close(c2pFD[0]);
    }


    return true;
}


}
