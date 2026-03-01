//Autor: Camilo Chicaiza Toapanta


#include "Usuari.h"
#include <iostream>
using namespace std;

//Constructor
Usuari::Usuari(string n, string a, string p, string t, string d, int e) {
    nom = n;
    adreca = a;
    poblacio = p;
    telefon = t;
    dni = d;
    edat = e;
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
vector<Llibre> Usuari::getLlibres() const {
    return llibres;
};

//Metodes
void Usuari::print() const{
    cout << "Nom: " << nom << endl;
    cout << "Adreça: " << adreca << endl;
    cout << "Població: " << poblacio << endl;
    cout << "Telèfon: " << telefon << endl;
    cout << "DNI: " << dni << endl;
    cout << "Edat: " << edat << endl;
};
void Usuari::afegeixLlibre(string nom, string autor, string isbn, int any) {
    llibres.push_back(Llibre(nom, autor, isbn, any));
};
//Provem amb iteradors
void Usuari::eliminaLlibre(string nom) {
    vector<Llibre>::iterator it;
    for (it = llibres.begin(); it != llibres.end(); ++it){
        if (it->getTitol() == nom){
            llibres.erase(it);
            cout << "Llibre eliminat" << endl;
            return;
        }
    }
    cout << "No s'ha trobat el llibre amb l'ISBN proporcionat" << endl;
};
//Provem amb iterador tradicional
void Usuari::mostraLlibres() const{
    if (llibres.size() == 0)
        cout << "--- "<< nom << " no té llibres ---" << endl;
    else
        cout << "---- Libres de " << nom << " ----" << endl;
    for (int i = 0; i < llibres.size(); i++){
        cout << "Llibre " << i + 1 << ":" << endl;
        llibres[i].print();
        cout << "------------------------" << endl;
    }
};