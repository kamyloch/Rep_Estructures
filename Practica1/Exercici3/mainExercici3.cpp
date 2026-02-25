#include <iostream>
#include "Estudiant.h"
#include <fstream>
#include <vector>
using namespace std;

int demana(vector<string> arr_options){
    int option;
    int n = arr_options.size();
    cout << "\nHola que vols fer?" << endl;
    do{
        //Mostra menú
        for (int i = 1; i <= n; i++)
            cout << (i == n ? 0 : i) << ". " << (arr_options[i-1])<< endl;

        //Demana petició
        cout << "Digues: ";
        if (!(cin >> option)||(option < 0 || n < option)){
            option  = -1;
            cin.clear();
            cin.ignore(1000, '\n');
            throw invalid_argument("Opció incorrecta");
        }

    }while(option == -1);
    cout << endl;
    return option;
}

void llegir(string filename){

    ifstream dades(filename);
    string nom;
    int any, assignatures;
    cout << "Ruta fitxer: " << filename << endl;

    while (dades >> nom >> any >> assignatures){
        cout << "Nom → " << nom
             << ", Edat → " << 2026 - any
             << ", Assignatures → " << assignatures
             << endl;
    }
    dades.close();
}


int main() {
    int option;
    vector<string> arr_options = {"Informar Estudiant","Llegir fitxer","Resum estudiants","Sortir"};
    int estudiats = 0;

    do{
        try{option = demana(arr_options);}
        catch(invalid_argument e){
            cerr << "Error: " << e.what() << '\n';
        }
        
        
        
        switch (option){
            case 0:{
                cout << "Adeu!" << endl;
                break;}
            case 1:{ 
                Estudiant e1;
                cout << "Estudiant #" << (estudiats+1)<< endl;
                try{
                    e1.omple();
                    e1.print();
                    e1.desar();
                    estudiats++;
                }
                catch (invalid_argument e){
                    cerr << "Error: " << e.what() << endl;
                }
                break;}
            case 2:{
                llegir("fitxer.txt");
                break;}

            case 3:{
                cout << "Estudiants creats: " << estudiats << endl;
                break;}
        }
        
    }while (option != 0);

    return 0;
}
