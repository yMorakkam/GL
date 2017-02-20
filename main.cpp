#include "LexicalAnalyser.h"
#include "SyntaxAnalyser.h"

#include <iostream>
#include <iterator>
#include <sstream>
#include <fstream>

using namespace std;

int main(int argc, char* argv[]) {

    // === PART 1 : Read the Data ===//

    std::string results("");
    ifstream ifs("test.txt", ios::in);
    if (ifs.is_open())
            {
                std::stringstream buffer;
                buffer << ifs.rdbuf();
                results = buffer.str();
                std::cout << "Opened file " << std::endl;
            }
    else{
                std::cout << "Error, couldn't open file " << argv[2] << std::endl;
         }


    SyntaxAnalyser analyser;

    analyser.analyse(results);

    // Wait for input before closing
    getchar();
    return 0;
}
