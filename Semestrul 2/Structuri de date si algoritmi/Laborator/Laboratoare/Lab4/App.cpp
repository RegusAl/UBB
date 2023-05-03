#include <iostream>
#include "MDO.h"
#include "IteratorMDO.h"
#include "TestScurt.h"
#include "TestExtins.h"

int main(){
    testAll();
    cout<<"Test Scurt - passed!"<<endl;
    testAllExtins();
    cout<<"Test Extins - passed!"<<endl;
    std::cout<<""<<std::endl;
    return 0;
}
