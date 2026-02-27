//Autor: Camilo Chicaiza Toapanta

#include <iostream>
#include <stdexcept>
#include "Estudiant.h"
using namespace std;

//He fet el metode "demana" no falla mai en tenir un do...while i cin.clear/ignore que nomes deixa triar numeros 1-3
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
                //Fem el try del metode omple de Estudiant y guardem la compte en una variable
                cout << "Estudiant #" << (estudiats+1)<< endl;
                Estudiant nouEstudint = Estudiant();
                try{
                nouEstudint.omple();
                estudiats++; //Si s'ha omples, afegim a la variable
                }
                catch (invalid_argument e){
                    cout << "Error: " << e.what() << endl;
                    break;
                }
                nouEstudint.print();
                break;
        }
        
    }while (option != 1);

    return 0;
}
