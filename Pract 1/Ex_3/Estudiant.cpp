#include <iostream>
#include <string>
#include <fstream>
#include "Estudiant.h"
using namespace std;

//Constructor
Estudiant::Estudiant() {
    cout << "Nom: ";
    cin >> nom;
    cout << "Any de Naixement: ";
    cin >> any;
    cout << "Assignatures: ";
    cin >> assignatures;
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


//Mètodes
void Estudiant::print() {
    cout << "Nom → " << nom
         << " ,Edat → " << getedat()
         << " ,Assignatures → " << assignatures
         << endl;
}

void Estudiant::desar() {
    ofstream dades("fitxer.txt",ios::app);
    dades << nom << " " << any << " " << assignatures << endl;
    dades.close();
}
