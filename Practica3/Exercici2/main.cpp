#include "WordIndexer.h"
#include "Menu.h"
#include <chrono>
#include <fstream>
#include <iostream>

int main(){
    Menu opcions = {"Crea l'arbre",
                    "Mostra arbre",
                    "Llegir dictionary",
                    "Mostra index de paraules",
                    "Consultar profunditat del arbre",
                    "Sortir"};
    int user;
    WordIndexer* wordId = nullptr;
    do{

        user = opcions.demanar("Gestió de paraules");

        auto begin = chrono::steady_clock::now();
        switch (user){

            case 1:{
                char x = Menu::demanaSN("Quin fitxer vols", 'P', 'G');

                begin = chrono::steady_clock::now();
                if( wordId  != nullptr) 
                    delete wordId;

                if (x == 'P')
                    wordId = new WordIndexer("shortText.txt");
                else
                    wordId = new WordIndexer("longText.txt");
                
                break;
            }
            case 2:{
                if (wordId == nullptr)
                    cout << "Encara está buid"<<endl;
                else
                    wordId->printDictionary();
                break;
            }
            case 3:{
                if(wordId  == nullptr)
                    cout << "No inicialitzat" << endl;
                else{
                    ifstream dades ("dictionary.txt");
                    if (!dades.is_open()) 
                    cout << "ERROR: No s'ha trobat el fitxer dictionary.txt en la ruta actual!" << endl;
                    string paraula;
                    while (dades >> paraula)
                        wordId-> contains(paraula);
                    dades.close();
                }
                break;
            }
            case 4:{break;}
            case 5:{
                if(wordId  == nullptr)
                    cout << "No inicialitzat" << endl;
                else
                    cout << "Profunditat: " << wordId->height() << endl;
                break;
            }
            case 6:{
                cout << "Adeu" << endl;
                if(wordId  != nullptr) 
                    delete wordId;
                break;
            }
        }
        auto end = chrono::steady_clock::now();
        cout << "Temps transcorregut: " << chrono::duration_cast<chrono:: microseconds>(end -begin).count() << " μs" << endl;
        cout << endl;
    } while (user != 6);

}