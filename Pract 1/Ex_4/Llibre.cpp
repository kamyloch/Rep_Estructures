#include "Llibre.h"
#include <iostream>

using namespace std;

Llibre::Llibre(string t, string a, string i, int any) {
    titol = t;
    autor = a;
    isbn = i;
    anyPublicacio = any;
};

void Llibre::mostrarInfo() {
    cout << "Titol: " << titol << endl;
    cout << "Autor: " << autor << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Any de publicacio: " << anyPublicacio << endl;
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


//Printers
void Llibre::printTitol() {
    cout << "Titol: " << titol << endl;
};

void Llibre::printAutor() {
    cout << "Autor: " << autor << endl;
};

void Llibre::printIsbn() {
    cout << "ISBN: " << isbn << endl;
};

void Llibre::printAnyPublicacio() {
    cout << "Any de publicacio: " << anyPublicacio << endl;
};
