#include <iostream>
#include "Estudiant.h"
#include <fstream>
#include <vector>
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

void llegir(string filename){
    ifstream dades(filename);
    string nom;
    int any, assignatures;
    while (dades >> nom >> any >> assignatures){
        cout << "Nom → " << nom
             << " ,Edat → " << 2026 - any
             << " ,Assignatures → " << assignatures
             << endl;
    }
    dades.close();
}


int main() {
    int option;
    vector<string> arr_options = {"Sortir", "Informar Estudiant","Llegir fitxer","Resum estudiants"};
    int estudiats = 0;
    ofstream dades("fitxer.txt",ios::trunc);
    dades.close();


    do{
        option = demana(arr_options);
        
        switch (option){
            case 1:{
                cout << "adeu!" << endl;
                break;}
            case 2: {
                Estudiant e1;
                estudiats++;
                cout << "Estudiant " << estudiats<< endl;
                e1.print();
                e1.desar();
                break;}
            case 3: {
                llegir("fitxer.txt");
                break;}

            case 4: {
                cout << "Total estudiants: " << estudiats << endl;
                break;}
            default: {
                cout << "No vàlid, torna a triar-ne..." << endl;
                break;}
        }
        
    }while (option != 1);

    return 0;
}
