#include "Usuari.h"
#include <iostream>
using namespace std;


Usuari::Usuari(string n, string a, string p, string t, string d, int e) {
    nom = n;
    adreca = a;
    poblacio = p;
    telefon = t;
    dni = d;
    edat = e;
};

void Usuari::mostrarInfo() const {
    cout << "Nom: " << nom << endl;
    cout << "Adreça: " << adreca << endl;
    cout << "Població: " << poblacio << endl;
    cout << "Telèfon: " << telefon << endl;
    cout << "DNI: " << dni << endl;
    cout << "Edat: " << edat << endl;
};

// Getters
string Usuari::getNom() const {
    return nom;
};
string Usuari::getAdreca() const {
    return adreca;
};
string Usuari::getPoblacio() const {
    return poblacio;
};
string Usuari::getTelefon() const {
    return telefon;
};
string Usuari::getDni() const {
    return dni;
};
int Usuari::getEdat() const {
    return edat;
};

//Metodes
void Usuari::print() {
    mostrarInfo();
};
void Usuari::afegeixLlibre(string nom, string autor, string isbn, int any) {
    llibres.push_back(Llibre(nom, autor, isbn, any));
};
void Usuari::eliminaLlibre(string nom) {
    int i;
    for (i = 0; i < llibres.size(); i++){
        if (llibres[i].getTitol() == nom){
            llibres.erase(llibres.begin() + i);
            cout << "Llibre eliminat" << endl;
            return;
        }
    }
    if (i == llibres.size())
        cout << "No s'ha trobat el llibre amb el nom proporcionat" << endl;
};
void Usuari::mostraLlibres() const{
    if (llibres.size() == 0){
        cout << "L'usuari no té llibres associats" << endl;
        return;
    }
    for (int i = 0; i < llibres.size(); i++){
        cout << "Llibre " << i + 1 << ":" << endl;
        llibres[i].mostrarInfo();
        cout << "------------------------" << endl;
    }
};