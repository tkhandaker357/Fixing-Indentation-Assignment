// sdfsfsfsfds
// sdfsfsfsfds
// sdfsfsfsfds
// sdfsfsfsfds


#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>

auto removeLeadingSpace(std::string string) -> std::string {
    std::string newString{};

    size_t i{ 0 };
    for (i; i < string.length(); ++i) {
        if (isspace(string[i]) == false) {
            newString += string.substr(i, std::string::npos);
            break;
        }
    }

    return newString;
}

auto fixCode(std::string fileName) -> void {
    std::ifstream file;
    file.open(fileName, std::ios::in);

    std::vector<std::string> allLines{};
    if (file.is_open()) {
        std::string line{};
        
        while (std::getline(file, line)) {
            allLines.push_back(removeLeadingSpace(line));
        }

        file.close();
    }

    std::ofstream newCode{"good-code.cpp"};

    int neededIndents{ 0 };
    for (size_t i{ 0 }; i < allLines.size(); ++i) {
        if (allLines[i].find('{') != std::string::npos && i + 1 < allLines.size()) {
            ++neededIndents;
            size_t j{ 1 };
            while (allLines[i + j].find('}') == std::string::npos && i + j < allLines.size()) {
                allLines[i + j] = '\t' + allLines[i + j];
                ++j;    
            }
        }

        if (allLines[i].find('}') != std::string::npos && neededIndents > 1) {
            std::string tabs{};
            for (size_t j{ 0 }; j < neededIndents - 1; ++j) {
                tabs += '\t';
            }

            allLines[i] = tabs + allLines[i];
            --neededIndents;
        }
    }

    for (size_t i{ 0 }; i < allLines.size(); ++i) {
        newCode << allLines[i] << std::endl;
    }

    newCode.close();

    std::cout << "Created file: good-code.cpp!" << std::endl;
}


