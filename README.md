# SSARI

This build depends on the lingeling executable in order to perform SAT solving. As such it will automatically build and install lingeling into the /usr/bin path, unless otherwise specified. If you do not have sudo permissions please see build options.

Build Options:  
-DLINGELING_INSTALL_DIR:string=<Lingeling Install Dir>

To Build:  
sudo apt-get install libxml++2.6-dev  
mkdir ./build  
cd ./build  
cmake ..  
make all  

To Install in Library Path:  
sudo make install  

To Generate Documentation:  
Ensure doxygen is installed along with graphviz  
doxygen ./dox.config  


# Boolean Manipulation  
Library allows for creation and manipulation of boolean expressions. It also integrates with the Lingeling SAT Solver in order to determine if a boolean expression is satisfiable.  

Using Boolean Manipulation Library  

##Generate Boolean Expression
```
BoolFunc a("a");
BoolFunc b("b");
BoolFunc func = (a & b) | !a;
cout << func.toString() << endl;
```
Produces: ((a & b) | (!a))

##Determining Satisfiablity
```
BoolFunc a("a");
BoolFunc func = a & !a;
cout << func.isSat() << endl;
```
Produces: 0

##Support for Constants
Constructor, Assignment and Operators support constant true/false
```
BoolFunc a("a");
BoolFunc t(true);
BoolFunc expr = a | t;
cout << expr.toString() << endl;  // "T"
expr = a & t;
cout << expr.toString() << endl;  // "a"
expr = a & false;
cout << expr.toString() << endl;  // "F"
```

Expression can also be queried for constant True/False
```
BoolFunc a("a");
BoolFunc expr = a & false;
cout << expr.isZero() << endl; // "1"
expr = a | true;
cout << expr.isOne() << endl;  // "1"
```


#Generate Arithmetic Expression
```
CFunc a("a");
CFunc b("b");
CFunc c("c");
CFunc expr = a * b + c;
cout << expr.toString() << endl;
```
Produces: ((a*b)+c)
