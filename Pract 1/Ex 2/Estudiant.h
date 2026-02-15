#pragma once
#include <string>

class Estudiant {
public:
    std::string nom;
    int any;
    int assignatures;

    int edat();
    void print();
};