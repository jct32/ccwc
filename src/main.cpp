#include <iostream>
#include <fstream>
#include <unistd.h>

int main(int argc, char*argv[]) {
    bool printBytes = false;
    std::string fileName;
	int c = 0;
    if(argc > 1) {
		while((c = getopt(argc, argv, "c:")) != -1) {
			switch(c) {
				case 'c':
					printBytes = true;
					if(*optarg == 'c') {
						std::cout << "-c requires an argument" << std::endl;
						return -1;
					}
					fileName = optarg;
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
		std::cout << "  " << size << " " << fileName << std::endl;
	}
    
    return 0;
}
