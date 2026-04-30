/*
He reciclat el menu fet a la practica anterior
com TAD auxiliar per tindre el main mes net!
així ens podem centrar en la implementació del BST
*/


#ifndef MENU_H
#define MENU_H
#include <initializer_list>
#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <stdexcept>

using namespace std;

class Menu{
    public:
        //Constructor
        Menu(initializer_list<string>); //Lista inicializadora

        //Metodes
        int demanar(string titol = "Menú") const; //Retorna un numero [1-size] des de consola (Throws out_of_range)
        void print() const; //Mostra el menu per consola
        int size() const; //Llargada del menú

        //Solucituts per consola robustas
        static int demanaInt(string missatge = "Digues n ∈ ℤ");// Fa while
        static char demanaSN(string missatge = "Digues" , char s = 's',char n = 'n') ; //Fa while
        static string demanaStr(string missatge = "Digues"); //Mai falla

    private:
        string rang;// Mostra interval de la forma [min-max] per informar
        vector<string> opcions;
};

//****  Definició de Mètodes  ****//

Menu :: Menu(initializer_list<string> elementos){
    this->opcions.reserve(elementos.size()); 
    initializer_list<string>::iterator it = elementos.begin();

    for (; it != elementos.end();++it)
        this->opcions.push_back(*it);

    this-> rang = "[1-" + to_string(size()) + "]"; 
}

int Menu :: demanar(string missatge) const{
    if (missatge != "")
        cout << "   ---  " << missatge << "  ---" << endl;
    
    //Mostrem el menu
    print();
    int usuari = demanaInt("Digues " + rang);

    if (usuari < 1 || size() < usuari)
        throw out_of_range("S'ha de triar entre " + rang);
    
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
    
    //Posibilitats
    char sMin = tolower(s), sMaj = toupper(s);
    char nMin = tolower(n), nMaj = toupper(n);

    //La entrada ha de ser {s,S,n,N}
    string usuari = "";
    while ((usuari.length() != 1) || !(usuari[0] == sMin || usuari[0] == nMin || usuari[0] == sMaj || usuari[0] == nMaj)){
        cout << missatge << " ("<< s <<"/" << n <<"): " ;
        cin >> usuari;
    }

    //Si ha dit que si
    if (usuari[0] == sMin || usuari[0]== sMaj)
        return s;

    //Si ha dit que no
    return n;
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
    getline(cin,usuari);
    return usuari;
}
#endif