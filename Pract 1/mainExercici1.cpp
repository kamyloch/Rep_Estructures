#include <iostream>
#include <string>
using namespace std;

int demana(string nom, string arr_options[]){
    int option;
    cout << "Hola " + nom + " que vols fer?" << endl;
    do{
    
        //Mostra menú
        for (int i = 1; i <= 3; i++)
            cout << i << ". " << (arr_options[i-1])<< endl;

        //Demana petició
        cout << "Digues: ";
        cin >> option;
        if (option < 1 || 3 < option){
            option  = -1;
            cout << "No vàlid, torna a triar-ne..." << endl;
        }

    }while(option == -1);

    return option;
}

int main() {
    string nom;
    int option;
    string arr_options[] = {"Sortir", "Benvinguda", "Redefinir el nom"};

    cout << "Com et dius? ";
    cin >> nom;

    do{
        option = demana(nom,arr_options);

        switch (option){
            case 1:
                cout << "adeu!" << endl;
                break;
            case 2: 
                cout << "Benvingut/da a l'assignatura d'estructura de dades, " << nom << endl; 
                break;
            case 3: 
                cout << "Digues el nou nom: ";

                cin >> nom; 
                break;
        }
        
    }while (option != 1);

    return 0;
}


