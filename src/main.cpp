#include <iostream>
#include <fstream>
#include <sstream>
#include <unistd.h>

int main(int argc, char*argv[]) {
    bool printBytes = false;
    bool printLines = false;
	bool printWords = false;
    std::string fileName;
	int c = 0;
    //TODO: Allow for multiple arguments and still work
    if(argc > 1) {
		while((c = getopt(argc, argv, "l:c:w:")) != -1) {
			switch(c) {
				case 'c':
					if(*optarg == 'c') {
						std::cout << "-c requires an argument" << std::endl;
						return -1;
					}
					fileName = optarg;
					printBytes = true;
					break;
                case 'l':
                    if(*optarg == 'l') {
                        std::cout << "-l requires an argument" << std::endl;
                        return -1;
                    }
                    fileName = optarg;
                    printLines = true;
                    break;
				case 'w':
					if(*optarg == 'w') {
						std::cout << "-w requires an argument" << std::endl;
					}
					fileName = optarg;
					printWords = true;
					break;
				default:
					std::cout << "Invalid arguments" << std::endl;
			}
		}
    }

	if(printBytes) {
		std::ifstream in(fileName, std::ios::binary | std::ios::ate);
		if(!in.is_open()) {
			std::cout << "Unable to open " << fileName << std::endl;
			return -1;
		}
		auto size = in.tellg();
		std::cout << size << " " << fileName << std::endl;
	}
    if(printLines) {
        std::ifstream in(fileName);
        if(!in.is_open()) {
            std::cout << "Unable to open " << fileName << std::endl;
            return -1;
        }
        int lines = 0;
        std::string line;
        while(std::getline(in, line)) {
            lines++;
        }
        std::cout  << lines << " " << fileName << std::endl;
    }
	if(printWords) {
		std::ifstream in(fileName);
		if(!in.is_open()) {
			std::cout << "Unable to open " << fileName << std::endl;
		}
		std::string line;
		unsigned int words = 0;
		while(std::getline(in, line)) {
			std::stringstream ss(line);
			std::string word;
			while(ss >> word) {
				words++;
			}
		}
		std::cout << words << " " << fileName << std::endl;
	}
    
    return 0;
}
