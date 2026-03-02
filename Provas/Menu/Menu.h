#ifndef MENU_H
#define MENU_H

#include <vector>
#include <iostream>
#include "Menu.h"

using namespace std;

class Menu{
    private:
        vector<string> opcions;
        bool isZero;
    public:
        //Zero es para que la ultima opcion la marque como 0
        Menu::Menu (const vector<string> llista, bool isZero = false);
        void mostra(const string titol = "*****  Menú  ****") const;
        int demana () const;
};

#endif