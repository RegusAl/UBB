#include <iostream>

#include "TestScurt.h"
#include "TestExtins.h"

int main() {
    testAll();
    std::cout<<"Test scurt - passed"<<std::endl;
    testAllExtins();
    std::cout<<"Test extins - passed"<<std::endl;
}
