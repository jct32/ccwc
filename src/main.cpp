#include <iostream>

int main(int argc, char*argv[]) {
    bool printBytes = false;
    std::string fileName;
    if(argc > 1) {
        for(int i = 1; i < argc; i++) {
            std::string arg = argv[i];
            if(arg.rfind("-", 0) == 0) {
                std::cout << "argument" << std::endl;
            }
            else {
                std::cout << "file" << std::endl;
            }
        }
    }
    
    return 0;
}
