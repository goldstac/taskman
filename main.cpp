#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
std::string read_file(const std::string& filepath) {
    std::ifstream file(filepath);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}
void write_file(const std::string& filepath, const std::string& content) {
    std::ofstream file(filepath, std::ios::app);
    file << content << '\n';
}
int main(int argc,char ** argv){
std::string version = "V0.0.1";
if (argc > 1){
    std::string arg1 = argv[1];
    if (arg1 == "add"){
        if (argc < 3){
            std::cout << "usage: taskman add <task>\n";
            return 1;
        }
        std::string arg2 = argv[2];
        write_file("blob/storage/taskman.storage",arg2);
        std::cout << "Task : " << arg2 << " Added\n";
    }
    else if (arg1 == "--version"){
        std::cout << version << "\n";
    }
}
else{
    std::cout << "usage: taskman <command>\n";
}
}
