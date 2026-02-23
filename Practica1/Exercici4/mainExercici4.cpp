#include <iostream>
#include <vector>
#include "Usuari.h"
using namespace std;

int demana(vector<string> arr_options){
    int option;
    int n = arr_options.size();
    cout << "Hola que vols fer?" << endl;
    do{
    
        //Mostra menú
        for (int i = 1; i <= n; i++)
            cout << i << ". " << (arr_options[i-1])<< endl;

        //Demana petició
        cout << "Digues: ";
        if (!(cin >> option)||(option < 1 || n < option)){
            option  = -1;
            cout << "No vàlid, torna a triar-ne..." << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    }while(option == -1);

    return option;
}
void afegeixUsuari(vector<Usuari>& usuaris){
    string nom, adreca, poblacio, telefon, dni;
    int edat;

    cout << "Nom: ";
    cin >> nom;
    cout << "Adreça: ";
    cin >> adreca;
    cout << "Població: ";
    cin >> poblacio;
    cout << "Telèfon: ";
    cin >> telefon;
    cout << "DNI: ";
    cin >> dni;
    cout << "Edat: ";
    cin >> edat;

    usuaris.push_back(Usuari(nom, adreca, poblacio, telefon, dni, edat));
}
void eliminaUsuari(vector<Usuari>& usuaris){
    string dni;
    cout << "DNI de l'usuari a eliminar: ";
    cin >> dni;
    int i;
    for (i = 0; i < usuaris.size(); i++){
        if (usuaris[i].getDni() == dni){
            usuaris.erase(usuaris.begin() + i);
            cout << "Usuari eliminat" << endl;
        }
    }
    if (i == usuaris.size())
        cout << "No s'ha trobat l'usuari amb el DNI proporcionat" << endl;
}
void afegeixLlibre(vector<Usuari>& usuaris){

    string dni, nom, autor, isbn;
    int any;

    cout << "DNI de l'usuari: ";
    cin >> dni;

    int i = 0;
    while (i < usuaris.size() && usuaris[i].getDni() != dni){i++;}

    if (usuaris[i].getDni() == dni){
    cout << "Nom del llibre: ";
    cin >> nom;
    cout << "Autor del llibre: ";
    cin >> autor;
    cout << "ISBN del llibre: ";
    cin >> isbn;
    cout << "Any de publicació del llibre: ";
    cin >> any;

    usuaris[i].afegeixLlibre(nom, autor, isbn, any);
    cout << nom << " afegit a l'usuari!" << endl;
}
else
    cout << "No s'ha trobat l'usuari amb el DNI proporcionat" << endl;
}
void eliminaLlibre(vector<Usuari>& usuaris){
    string dni, nom;
    cout << "DNI de l'usuari: ";
    cin >> dni;
    cout << "Nom del llibre a eliminar: ";
    cin >> nom;

    for (int i = 0; i < usuaris.size(); i++){
        if (usuaris[i].getDni() == dni){
            usuaris[i].eliminaLlibre(nom);
            cout << "Llibre eliminat de l'usuari" << endl;
            return;
        }
    }
    cout << "No s'ha trobat l'usuari amb el DNI proporcionat" << endl;
}
void imprimirUsuaris(const vector<Usuari>& usuaris){
    for (int i = 0; i < usuaris.size(); i++){
        usuaris[i].mostrarInfo();
        cout << "------------------------" << endl;
    }
}
void imprimirLlibres (const vector<Usuari>& usuaris){
    string dni;
    cout << "DNI de l'usuari: ";
    cin >> dni;
    for (int i = 0; i < usuaris.size(); i++)
        if (usuaris[i].getDni() == dni)
            usuaris[i].mostraLlibres();
}

int main (){
    vector<string> arr_options = {"Afegir Usuari","Eliminar Usuari","Afegir Llibre a un usuari","Eliminar Llibre d'un usuari","Imprimir usuaris de la biblioteca municipal","Imprimir els libres d’un usuari","Sortir"};
    vector<Usuari> usuaris;

    int option = demana(arr_options);

    do{
        option = demana(arr_options);
        switch(option){
            case 1:
                cout << "Afegir Usuari"<< endl;
                afegeixUsuari(usuaris);
                break;
            case 2:
                cout << "Eliminar Usuari" << endl;
                eliminaUsuari(usuaris);
                break;
            case 3:
                cout << "Afegir Llibre a un usuari" << endl;
                afegeixLlibre(usuaris);
                break;
            case 4:
                cout << "Eliminar Llibre d'un usuari" << endl;
                eliminaLlibre(usuaris);
                break;
            case 5:
                cout << "Imprimir usuaris de la biblioteca municipal" << endl;
                imprimirUsuaris(usuaris);
                break;
            case 6:
                cout << "Imprimir els libres d'un usuari" << endl;
                imprimirLlibres(usuaris);
                break;
            case 7:
                cout << "Sortir" << endl;
                break;

        }
    }while(option != 7);

    return 0;
}