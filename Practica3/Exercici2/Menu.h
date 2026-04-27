#ifndef MENU_H
#define MENU_H
#include "Menu.h"
#include <initializer_list>
#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

class Menu{
    public:
        //Constructor
        Menu(initializer_list<string>); //Lista inicializadora

        //Metodes
        int demanar(string missatge = "") const; //Retorna un numero [1-size] des de consola
        void print() const; //Mostra el menu per consola
        int size() const;


    private:
        string rang()const;// Mostra interval de la forma [min-max] per informar
        vector<string> opcions;
};

//****  Definició de Mètodes  ****//

Menu :: Menu(initializer_list<string> elementos){
    this->opcions.reserve(elementos.size()); 
    initializer_list<string>::iterator it = elementos.begin();
    
    for (it; it != elementos.end();++it)
        this->opcions.push_back(*it);
}
string Menu :: rang()const{
    return "[1-" + to_string(size()) + "]";
}
int Menu :: demanar(string missatge) const{
    if (missatge != "")
        cout << missatge << endl;
    
    //Mostrem el menu
    print();
    cout << "Digues " << rang() <<": ";

    int usuari;
    cin >> usuari;
    if (cin.fail()){
        cin.clear();
        cin.ignore(1000,'\n');
        throw invalid_argument("No s'hi poden fer ficar lletres, cal " + rang());
    }
    if (usuari < 1 || size() < usuari)
        throw out_of_range("S'ha de triar entre " + rang());
    
    return usuari;

}
void Menu::print()const{
    vector<string>::const_iterator it = this->opcions.begin();

    for (int i = 1; it != opcions.end(); it++,i++)
        cout << i << ". " << *it<< endl;

}
int Menu:: size()const{
    return opcions.size();
}

#endif