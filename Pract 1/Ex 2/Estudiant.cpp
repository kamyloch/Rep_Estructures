#include <iostream>
#include <string>
#include "Estudiant.h"

int Estudiant::edat() {
    return 2026 - any;
}

void Estudiant::print() {
    std::cout << "nom → " << nom
              << ",any → " << any
              << ",assignatures → " << assignatures
              << std::endl;
}