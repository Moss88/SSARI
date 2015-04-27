# SSARI

To Build:  
sudo apt-get install libxml++2.6-dev  
mkdir ./build  
cd ./build  
cmake ..  
make all  

To Install in Library Path:  
sudo make install  

For SAT Support:  
install lingeling into the system path

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

# Boolean Manipulation  
Library allows for creation and manipulation of boolean expressions. It also integrates with the Lingeling SAT Solver in order to determine if a boolean expression is satisfiable.  

Using Boolean Manipulation Library  

##Generate Arithmetic Expression
```
CFunc a("a");
CFunc b("b");
CFunc c("c");
CFunc expr = a * b + c;
cout << expr.toString() << endl;
```
Produces: ((a*b)+c)
