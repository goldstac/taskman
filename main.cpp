#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <filesystem>
#include <cstdlib>
namespace fs = std::filesystem;
const char* home_env = std::getenv("HOME");
const std::string storage_dir = home_env ? std::string(home_env) + "/.local/share/taskman" : "blob/storage";
const std::string storage_path = storage_dir + "/taskman.storage";
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
void create_file(const std::string& filepath) {
    std::ofstream file(filepath);
}
int main(int argc,char ** argv){
std::string version = "V0.0.1 Alpha";
if (!fs::exists(storage_path)){
   std::cout << "taskman : " << storage_path << " not found\n";
   fs::create_directories(storage_dir);
   create_file(storage_path);
   std::cout << "taskman : Created " << storage_path << "\n";
}
else {
    // all good
}
if (argc > 1){
    std::string arg1 = argv[1];
    if (arg1 == "add"){
        if (argc < 3){
            std::cout << "usage: taskman add <task>\n";
            return 1;
        }
        std::string task;
         for (int i = 2; i < argc;i++){
             if (i != 2) task += " ";
             task += argv[i];
         }
         std::cout << "Task : " << task << "\n";
         write_file(storage_path,task);
    }
    else if (arg1 == "--version"){
        std::cout << version << "\n";
    }
    else if (arg1 == "list"){
     if (argc > 2 && std::string(argv[2]) == "--clear"){
        std::string cache_clear_cmd = "rm " + storage_path;
        std::system(cache_clear_cmd.c_str());
        std::cout << "Nuked --> " << storage_path << "\n";
     }
     else if (argc > 2){
         std::cout << "taskman: unknown option " << argv[2] << "\n";
         std::cout << "usage: taskman list\n";
         std::cout << "usage: taskman list --clear\n";

     }
     else{
         std::string load_list = read_file(storage_path);
         std::cout << load_list << "\n";

     }
    }

}
else{
    std::cout << "usage: taskman <command>\n";
}
}
