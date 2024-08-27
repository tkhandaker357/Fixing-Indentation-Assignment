#include "unindent.hpp"

auto main(int argc, char** argv) -> int {
    for (int i{ 1 }; i < argc; ++i) {
        fixCode(argv[i]);
    }
    
    return 0;
}