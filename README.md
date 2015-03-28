# SSARI

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
