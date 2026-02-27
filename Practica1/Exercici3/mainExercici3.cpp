#include <iostream>
#include "Estudiant.h"
#include <fstream>
#include <vector>
using namespace std;

int demana(vector<string> arr_options){
    int option;
    int n = arr_options.size();
    cout << "\nHola que vols fer?" << endl;
    
    //Mostra menú
    for (int i = 1; i <= n; i++)
        cout << (i == n ? 0 : i) << ". " << (arr_options[i-1])<< endl;

    //Demana petició, ara el metode fa throw en comptes de fer servir el do...while
    //Gestionem el error al main
    cout << "Digues: ";
    if (!(cin >> option)||(option < 0 || n < option)){
        cin.clear();
        cin.ignore(1000, '\n');
        throw invalid_argument("Opció incorrecta");
    }
    cout << endl;
    return option;
}

//Compta la quantitat de estudiants al fitxer
int compteEstudiants (string ruta){
    int c = 0;
    ifstream dades(ruta);
    string nom,line;
    int any, assig;

    while (dades >> nom >> any >> assig){
        c ++;
    }
    if (!dades.eof()){
        dades.close();
        throw invalid_argument("Fitxer corrupte");
    }
    dades.close();
    return c;
}

void llegir(string filename){
    //Fem servir el in-file-stream
    ifstream dades(filename);
    string nom;
    int any, assignatures;
    cout << "Ruta fitxer: " << filename << endl;
    cout << "----------------\n"; 
    //mentre hi hagin valors correctes sense errors, assignem
    while (dades >> nom >> any >> assignatures){
        Estudiant e(nom,any,assignatures);
        e.print();
        cout << "----------------\n";
    }
    dades.close();
    //Tanquem
}


int main() {
    int option;
    vector<string> arr_options = {"Informar Estudiant","Llegir fitxer","Resum estudiants","Sortir"};
    string ruta = "fitxer.txt";
    int estudiants = 0;


    do{
        //Fem el catch i hi posem -1 per tornar a demanar
        try{option = demana(arr_options);}
        catch(invalid_argument e){
            cerr << "Error: " << e.what() << '\n';
            option = -1;
        }
        //Si no es pot comptar correctamen → reset!
        //Faig aixo per si el algu canvia el fitxer externament
        try{estudiants = compteEstudiants(ruta);}
        catch (invalid_argument e){
        
            cout << "Error: " << e.what()<<endl;
            cout << "Reniciant fitxer\n";
            estudiants = 0;
            option -1;
            ofstream file(ruta);
            file.close();
    }
        
        switch (option){
            case 0:{
                cout << "Adeu!" << endl;
                break;}
            case 1:{ 
                Estudiant e1;
                cout << "Estudiant #" << (estudiants+1)<< endl;
                try{
                    e1.omple();
                    e1.desar();
                    estudiants++;
                }
                catch (invalid_argument e){
                    cerr << "Error: " << e.what() << endl;
                    option  = -1;
                }
                break;}
            case 2:{
                llegir(ruta);
                break;}

            case 3:{
                //Nomes mostra la compte
                cout << "Estudiants creats: " << estudiants << endl;
                break;}
        }
        
    }while (option != 0);

    return 0;
}
