#include "../include/USMS.h"
#include <iostream>

int main() {
    try {
        USMS system;
        system.run();
    } catch (const std::exception& e) {
        std::cerr << "Fatal error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}