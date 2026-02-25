#include <iostream>
#include "Estudiant.h"

using namespace std;

Estudiant::Estudiant(string nom_, int any_, int assignatures_){
    nom = nom_;
    any = any_;
    assignatures = assignatures_;
}

//Setters
void Estudiant::setAny(int any_){
    any = any_;
}
void Estudiant::setAssignatures(int ass_){
    assignatures = ass_;
}
void Estudiant::setNom(string nom_){
    nom = nom_;
}

//Geters
int Estudiant::getEdat() const{
    return 2026 - any;
}

//Métodes
void Estudiant::print(){
    std::cout << "Nom → " << nom
              << ",Any → " << any
              << ",Assignatures → " << assignatures
              << std::endl;
}