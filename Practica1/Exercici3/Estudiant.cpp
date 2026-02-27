//Author: Camilo Chicaiza Toapanta

#include <iostream>
#include <string>
#include <fstream>
#include "Estudiant.h"
using namespace std;

//Constructor
Estudiant::Estudiant(string nom, int any, int assignatures) {
    this->nom = nom;
    this->any = any;
    this->assignatures = assignatures;
}

//Getters
int Estudiant::getedat() {
    return 2026 - any;
}
int Estudiant::getAny() {
    return any;
}
int Estudiant::getAssignatures() {
    return assignatures;
}
string Estudiant::getNom() {
    return nom;
}

//Setters
void Estudiant::setNom(string nom) {
    this->nom = nom;
}
void Estudiant::setAny(int any) {
    this->any = any;
}
void Estudiant::setAssignatures(int assignatures) {
    this->assignatures = assignatures;
}

//Mètodes
void Estudiant::print() {
    cout << "Nom: " << getNom()
         << "\nEdat: " << getedat()
         << "\nAssignatures: " << getAssignatures()
         << endl;
}

//Fem servir el out-file-stream de fstream
//amb el parametre ios::app (append) per acomular estudiants
void Estudiant::desar() {
    ofstream dades("fitxer.txt",ios::app);
    dades << getNom() << " " << getAny() << " " << getAssignatures() << endl;
    dades.close();
    
    cout << "Estudiant " << getNom() << " afegit!\n";
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

    //Si tot surt be, afegim els valors al nou estudian
    setNom(nom);
    setAny(any);
    setAssignatures(assignatures);
}
