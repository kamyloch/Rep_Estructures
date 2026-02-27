//Autor: Camilo Chicaiza Toapanta

#ifndef LLIBRE_H
#define LLIBRE_H


#include <iostream>
using namespace std;

class Llibre{
    private:
        string titol;
        string autor;
        string isbn;
        int anyPublicacio;

    public:
        Llibre(string t, string a, string i, int any);

        // Getters
        string getTitol();
        string getAutor();
        string getIsbn();
        int getAnyPublicacio();

        //Printers
        void print() const;
};

#endif