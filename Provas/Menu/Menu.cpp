#include "Menu.h"
#include <iostream>
using namespace std;

//Constructor
Menu::Menu(const vector<string> opcions_, const bool isZero_){
    isZero = isZero_;
    opcions = opcions_;
}

//Metodes
void Menu::mostra(const string titol) const{
    int n = opcions.size();
    //Si no hay opciones, lo dice
    if (n == 0){
        cout << "--- Menu Buid ---\n";
        return;
    }

    cout << titol << endl;

    //Mostramos las opciones
    int i = 1; //Lleva la cuenta para el menú
    vector<string>::const_iterator it = opcions.begin();
    while (it != opcions.end()){
        cout << (i == n && isZero?: 0, i) << ". " << *it << endl;
        ++it;
        i++;
    }
}

int Menu::demana() const{ //throw si el cin no rep un nombre valid
    int n = opcions.size();
}
