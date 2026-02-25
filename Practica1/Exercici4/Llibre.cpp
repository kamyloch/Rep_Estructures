#include "Llibre.h"
#include <iostream>

using namespace std;

Llibre::Llibre(string t, string a, string i, int any) {
    titol = t;
    autor = a;
    isbn = i;
    anyPublicacio = any;
};

// Getters
string Llibre::getTitol() {
    return titol;
};
string Llibre::getAutor() {
    return autor;
};
string Llibre::getIsbn() {
    return isbn;
};
int Llibre::getAnyPublicacio() {
    return anyPublicacio;
};


//Metodes
void Llibre::print() const{
    cout << "Titol: " << titol << endl;
    cout << "Autor: " << autor << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Any de publicacio: " << anyPublicacio << endl;
};
