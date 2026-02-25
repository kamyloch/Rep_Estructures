#include <iostream>
#include <stdexcept>
#include "Estudiant.h"
using namespace std;

int demana(string arr_options[]){
    int option;
    cout << "Hola que vols fer?" << endl;
    do{
    
        //Mostra menú
       for (int i = 1; i <= 2; i++)
            cout << i << ". " << (arr_options[i-1])<< endl;

        //Demana petició
        cout << "Digues: ";
        if(cin >> option){
            if (option < 1 || 2 < option){
                option  = -1;
                cout << "No vàlid, torna a triar-ne..." << endl;
            }
        }
        else {
            cout << "No vàlid, torna a triar-ne..." << endl;
            option  = -1;
            cin.clear();
            cin.ignore(1000, '\n');
        }

    }while(option == -1);

    return option;
}

Estudiant omple (){
    string nom;
    int any;
    int assignatures;

    cout << "Nom: ";
    cin >> nom;
    
    do {
        cout << "Any de Naixement: ";
        cin >> any;
        if (any < 1 || 2026 < any) {
            cout << "Error al introduir el any de naixement" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
        }
    } while (any < 1 || 2026 < any);


    do{
        cout << "Assignatures: ";
        cin >> assignatures;
        if (assignatures < 1) {
            cout << "Error al introduir el nombre d'assignatures" << endl;
            cin.clear();
            cin.ignore(1000,'\n');
        }
    } while (assignatures < 1);

    return Estudiant(nom, any, assignatures);
}

int main() {
    int option;
    string arr_options[] = {"Sortir", "Informar Estudiant"};
    int estudiats = 0;


    do{
        option = demana(arr_options);
        
        switch (option){
            case 1:
                cout << "adeu!" << endl;
                break;
            case 2: 
                estudiats++;
                cout << "Estudiant " << estudiats<< endl;
                omple();
                break;
        }
        
    }while (option != 1);

    return 0;
}
