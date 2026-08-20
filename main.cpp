#include <iostream>
#include <string>
int main(int argc,char ** argv){
std::string version = "V0.0.1";
std::string arg1 = argv[1];
if (argc > 1){
    if (arg1 == "add"){
        if (argc < 3){
            std::cout << "usage: taskman add <task>\n";
        }
        std::string arg2 = argv[2];
        std::cout << arg2;
    }
    else if (arg1 == "--version"){
        std::cout << version << "\n";
    }
}
else{
    std::cout << "usage: taskman <command>\n";
}
}
