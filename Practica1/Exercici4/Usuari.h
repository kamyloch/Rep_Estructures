//Autor: Camilo Chicaiza Toapanta

#ifndef USUARI_H
#define USUARI_H

#include <vector>
#include <iostream>
#include "Llibre.h"

using namespace std;

class Usuari{
    private:
        string nom;
        string adreca;
        string poblacio;
        string telefon;
        string dni;
        int edat;
        vector <Llibre> llibres;

    public:
        Usuari(string n, string a, string p, string t, string d, int e);
        
        // Getters
        string getNom() const;
        string getAdreca() const;
        string getPoblacio() const;
        string getTelefon() const;
        string getDni() const;
        int getEdat() const;

        //Metodes
        void print() const;
        void afegeixLlibre(string nom, string autor, string isbn, int any);
        void eliminaLlibre(string nom);
        void mostraLlibres() const;
};
#endif