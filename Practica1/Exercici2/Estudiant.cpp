//Autor: Camilo Chicaiza Toapanta   

#include <iostream>
#include "Estudiant.h"

using namespace std;

Estudiant::Estudiant(string nom_ , int any_ , int assignatures_ ){
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

//Aquest metode throws un invalid_argument si l'any no es un 1 < int < 2026
//o be si  assignatures es > 1 o tampoc es int
void Estudiant :: omple (){
    string nom;
    int any;
    int assignatures;

    cout << "Nom: ";
    cin >> nom;
    
    cout << "Any de Naixement: ";
    cin >> any;
    if (any < 1 || 2026 < any) {
        cin.clear();
        cin.ignore(1000, '\n');
        throw invalid_argument("Any de naixement incorrecte");
        }


    cout << "Assignatures: ";
    cin >> assignatures;
        if (assignatures < 1) {
            cin.clear();
            cin.ignore(1000,'\n');
            throw invalid_argument("Nombre d'assignatures incorrecte");
        }

    //Si tot surt be, assignem
    setNom(nom);
    setAny(any);
    setAssignatures(assignatures);
}