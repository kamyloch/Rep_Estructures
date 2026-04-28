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
        int demanar(string titol = "Menú") const; //Retorna un numero [1-size] des de consola
        void print() const; //Mostra el menu per consola
        int size() const;

        //Solucituts per consola robustas
        static int demanaInt(string missatge = "Digues n ∈ ℤ");
        static char demanaSN(string missatge = "Digues" , char s = 's',char n = 'n') ;
        static string demanaStr(string missatge = "Digues");
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
        cout << "   ---  " << missatge << "  ---" << endl;
    
    //Mostrem el menu
    print();
    int usuari = demanaInt("Digues " + rang());

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

//Demana [s/n] a l'usuari de manera robusta
char Menu:: demanaSN(string missatge, char s, char n ){
    string usuari = "";
    string sStr(1, s);
    string nStr(1, n);
    while (usuari != sStr && usuari != nStr){
        cout << missatge << " ("<< s <<"/" << n <<"): " ;
        cin >> usuari;
    }
    return usuari[0];
}

//Demana de manera robusta un integer
int Menu:: demanaInt(string missatge){
    bool correcte = false;
    int usuari;
    while (!correcte){
        cout << missatge<< ": ";
        cin >> usuari;
        correcte = !cin.fail();
        if (!correcte){
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
    return usuari;
}

//Demana un string
string Menu:: demanaStr(string missatge){
    cout << missatge << ": ";
    string usuari;
    cin >> usuari;
    return usuari;
}

#endif