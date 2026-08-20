#include <iostream>
#include <string>
int main(int argc,char ** argv){
int real_argc = argc - 1;
std::string arg1 = argv[1];
std::cout << arg1;
    return 0;
}
