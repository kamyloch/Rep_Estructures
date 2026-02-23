#include <iostream>
#include <string>
#include <stdexcept>
#include "Estudiant.h"

Estudiant:: Estudiant(){}


int Estudiant::getEdat() const{
    return 2026 - any;
}

void Estudiant::print(){
    std::cout << "Nom → " << nom
              << ",Any → " << any
              << ",Assignatures → " << assignatures
              << std::endl;
}