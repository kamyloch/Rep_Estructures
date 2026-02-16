#include <iostream>
#include "Estudiant.h"
#include <fstream>
using namespace std;

void desar (Estudiant &e){
    ofstream dades("fitxer.txt");
    dades << e.nom << " " << e.any << " " << e.assignatures << endl;
    dades.close();
}

int demana(string arr_options[]){
    int option;
    cout << "Hola que vols fer?" << endl;
    do{
    
        //Mostra menú
        for (int i = 1; i <= 4; i++)
            cout << i << ". " << (arr_options[i-1])<< endl;

        //Demana petició
        cout << "Digues: ";
        cin >> option;
        if (option < 1 || 2 < option){
            option  = -1;
            cout << "No vàlid, torna a triar-ne..." << endl;
        }

    }while(option == -1);

    return option;
}

void omple (Estudiant &e){
    cout << "Nom: ";
    cin >> e.nom;
    cout << "Any de Naixement: ";
    cin >> e.any;
    cout << "Assignatures: ";
    cin >> e.assignatures;
}

int main() {
    int option;
    string arr_options[] = {"Sortir", "Informar Estudiant","Llegir fitxer","Resum estudiants"};
    int estudiats = 0;


    do{
        option = demana(arr_options);
        
        switch (option){
            case 1:
                cout << "adeu!" << endl;
                break;
            case 2: {
                Estudiant e1;
                estudiats++;
                cout << "Estudiant " << estudiats<< endl;
                omple(e1);
                e1.print();
                desar(e1);
                break;
            }
        }
        
    }while (option != 1);

    return 0;
}
