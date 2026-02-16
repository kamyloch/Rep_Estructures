#include <iostream>
#include <string>
#include "Estudiant.h"

int Estudiant::edat() {
    return 2026 - any;
}

void Estudiant::print() {
    std::cout << "nom → " << nom
              << ",any → " << edat()
              << ",assignatures → " << assignatures
              << std::endl;
}