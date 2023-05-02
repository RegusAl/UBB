#include <iostream>
#include "MDO.h"
#include "IteratorMDO.h"
#include "TestScurt.h"
#include "TestExtins.h"

int main(){
    testAll();
    testAllExtins();
    std::cout<<"Finished Tests!"<<std::endl;
    return 0;
}
