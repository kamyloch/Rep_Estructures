//Autor: Camilo Chicaiza Toapanta

#include <iostream>
#include <vector>
#include <stdexcept>
#include "Usuari.h"
using namespace std;
//Ens assegura que las dades de Agfegir llibre siguin minuscules
string tolower(string str){
    for (int i = 0; i < str.size(); i++)
        str[i] = tolower(str[i]);
    return str;
}
//Demana un nombre del rang al usuari
int demana(vector<string> arr_options){
    int option;
    int n = arr_options.size();
    cout << "\nHola que vols fer?" << endl;
    do{
    
        //Mostra menú
        for (int i = 1; i <= n; i++)
            cout << (i==n?0:i) << ". " << (arr_options[i-1])<< endl;

        //Demana petició
        cout << "Digues: ";
        if (!(cin >> option)||(option < 0 || n < option)){
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Opció no vàlida");
        }

    }while(option == -1);

    return option;
}
//throw si el any no es valid...
void afegeixLlibre(vector<Usuari>& usuaris, string dni_ = ""){

    string dni = dni_ , nom, autor, isbn;
    int any;

    if (dni == ""){
        cout << "DNI de l'usuari: ";
        cin >> dni;
    }

    //Busquem al usuari
    vector<Usuari>::iterator it = usuaris.begin();
    while (it != usuaris.end() && it -> getDni() != dni){++it;}
    if (it == usuaris.end())
        throw invalid_argument("No s'ha trobat l'usuari amb el DNI proporcionat");

    
    cout << "Nom del llibre: ";
    cin >> nom;
    //El nom del llibre ha de ser unic!
    vector<Llibre> lista = it->getLlibres();
    vector<Llibre>::iterator it2 = lista.begin();
    while (it2 != lista.end() && it2 -> getTitol() != nom){++it2;}
    if (it2 != lista.end())
        throw invalid_argument("El llibre ja existeix");

    cout << "Autor del llibre: ";
    cin >> autor;
    cout << "ISBN del llibre: ";
    cin >> isbn;
    cout << "Any de publicació del llibre: ";
    if (!(cin >> any)){
        cin.clear();
        cin.ignore(1000, '\n');
        throw invalid_argument("Any no vàlid");
    }
    //Afegim el llibre si tot correcte
    it->afegeixLlibre(tolower(nom), tolower(autor), tolower(isbn), tolower(any));
    cout << nom << " afegit a l'usuari!" << endl;

    //Preguntem si es vol afegir un altre llibre...
    vector<string>opcions = {"Si, vull afegir un altre llibre", "No, anar al menú"};
    int op = -1;
    do{try{op = demana(opcions);
        }catch(invalid_argument &e){
            cout << e.what()<< endl;}
    }while(op == -1);

    if (op == 1)
        afegeixLlibre(usuaris,dni);

}

//Fem throw  en demana i afegir si no la dades no son valides
void afegeixUsuari(vector<Usuari>& usuaris){
    string nom, adreca, poblacio, telefon, dni;
    int edat;

    cout << "DNI: ";
    cin >> dni;

    //Comprovem que dni sigui unic!
    vector<Usuari>::const_iterator it = usuaris.begin();
    while (it != usuaris.end() && it->getDni() != dni){++it;}
    if (it != usuaris.end())
        throw invalid_argument ("El dni " + dni + " ja existeix!");

    cout << "Nom: ";
    cin >> nom;

    cout << "Adreça: ";
    cin >> adreca;

    cout << "Població: ";
    cin >> poblacio;

    cout << "Telèfon: ";
    cin >> telefon;

    //Comprovem que la edat sigui válida
    cout << "Edat: ";
    if(!(cin >> edat) || edat < 1){
        cin.clear();
        cin.ignore(1000, '\n');
        throw invalid_argument("Edat no vàlida");
    }
    
    //Agegim a l'usuari
    usuaris.push_back(Usuari(nom, adreca, poblacio, telefon, dni, edat));

    //Preguntem si es vol afegir un llibre...
    vector<string>opcions = {"Si, vull afegir un llibre", "No, anar al menú"};
    int op = -1;
    do{try{op = demana(opcions);
        }catch(invalid_argument &e){
            cout << e.what()<< endl;}
    }while(op == -1);

    if (op == 1)
        afegeixLlibre(usuaris,dni);
}
//Elimina un usuari, no fa throw
void eliminaUsuari(vector<Usuari>& usuaris){
    string dni;
    cout << "DNI de l'usuari a eliminar: ";
    cin >> dni;
    int i;
    for (i = 0; i < usuaris.size(); i++){
        if (usuaris[i].getDni() == dni){
            usuaris.erase(usuaris.begin() + i);
            cout << "Usuari " << usuaris[i].getNom() << " eliminat" << endl;
        }
    }
    if (i == usuaris.size())
        cout << "No s'ha trobat l'usuari amb el DNI proporcionat" << endl;
}
//Fem servir iterators per trobar el usuari donat
void eliminaLlibre(vector<Usuari>& usuaris){
    string dni, titol;
    cout << "DNI de l'usuari: ";
    cin >> dni;
    bool trobat = false;

    vector<Usuari>::iterator it = usuaris.begin();
    while (it != usuaris.end()){
        if (it->getDni() == dni)
            trobat = true;
        ++it;
    }
    if (!trobat)
        cout << "Usuari no existent\n";
    else{
        --it;
        cout << "Titol del llibre a eliminar: ";
        cin >> titol;
        it->eliminaLlibre(titol);
    }
}
//Fem un print amb iterators
void imprimirUsuaris(const vector<Usuari>& usuaris){
    cout << "-------- Usuaris --------" << endl;
    vector<Usuari>::const_iterator i= usuaris.begin();
    while (i != usuaris.end()){
        i->print();
        cout << "------------------------" << endl;
        ++i;
    }
    if (--i == usuaris.end())
        cout << "No hi ha usuaris a la biblioteca" << endl;
}

//Imprimeix llibres sense iterators (per provar)
void imprimirLlibres (const vector<Usuari>& usuaris){
    string dni;
    cout << "DNI de l'usuari: ";
    cin >> dni;
    int i;
    bool found = false;
    for (i = 0; i < usuaris.size() && !found; i++)
        if (usuaris[i].getDni() == dni){
            usuaris[i].mostraLlibres();
            found = true;
        }
    
    if (!found)
        cout << "No s'ha trobat l'usuari amb el DNI proporcionat" << endl;
    }

int main (){
    vector<string> arr_options = {"Afegir Usuari","Eliminar Usuari","Afegir Llibre a un usuari","Eliminar Llibre d'un usuari","Imprimir usuaris de la biblioteca municipal","Imprimir els libres d'un usuari","Sortir"};
    vector<Usuari> usuaris;
    int option = -1;

    do{
        try{
            option = demana(arr_options);
        }
        catch(invalid_argument& e){
            cerr << "Error: " << e.what() << endl;
            option = -1;
        }
        //Tractem totes les opcion i exepcions0
        switch(option){
            case 1:
                cout << "Afegir Usuari"<< endl;
                try{
                    afegeixUsuari(usuaris);
                }
                catch(invalid_argument& e){
                    cerr << "Error: " << e.what() << endl;
                }
                break;
            case 2:
                cout << "Eliminar Usuari" << endl;
                eliminaUsuari(usuaris);
                break;
            case 3:
                cout << "Afegir Llibre a un usuari" << endl;
                try{
                    afegeixLlibre(usuaris);}
                catch(invalid_argument& e){
                    cerr << "Error: " << e.what() << endl;
                }
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
            case 0:
                cout << "Adeu!" << endl;
                break;

        }
    }while(option != 0);

    return 0;
}