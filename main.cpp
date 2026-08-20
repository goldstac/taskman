#include <iostream>
#include <string>
int main(int argc,char ** argv){
int real_argc = argc - 1;
std::string arg1 = argv[1];
std::string arg2 = argv[2];
if (arg1 == "add"){
    std::cout << arg2;
}
    return 0;
}
