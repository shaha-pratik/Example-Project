#include <iostream>
#include "src/calculator.h"

int main(int argc, char* argv[]) {
    std::cout << "Hello World" << std::endl;
    Calculator calc;
    std::cout << "4 + 5 = " << calc.add(4, 5) << std::endl;
    return 1;
}
