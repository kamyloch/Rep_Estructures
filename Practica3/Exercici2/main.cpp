#include "WordIndexer.h"
#include "Menu.h"
#include "Position.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>


void  printVector (const vector<Tuple<int>>& llista){
    if (llista.empty()){
        cout << "[]";
        return;
    }
    
    cout << "[";
    auto itr = llista.begin();
    for(; itr != llista.end()-1; ++itr)
        cout << itr->str() << ", ";
    
    itr = llista.end()-1;

    cout << itr->str() << "]";
}
void print4040(const Position<string, Tuple<int>> *node, int& fets){

    //Inordre
    if (node -> left() != nullptr)
        print4040(node->left(), fets);

    if (fets !=0 && fets%40 == 0){
        char eleccio = Menu::demanaSN("Fets " + to_string(fets) + ", vols continuar?");
        if (eleccio == 'n')
            throw string("Recursividad lista!");
    }
    cout << node->getKey() << ": "; //Key
    printVector(node->getValues()); // Ocurrencies
    cout << endl;
    fets++;

    if (node->right() != nullptr)
        print4040(node->right(), fets);
       
}

int main(){
    Menu opcions = {"Crea l'arbre", //1
                    "Mostra arbre 40 en 40", //2
                    "Llegir dictionary",//3
                    "Mostra index de paraules",//4
                    "Consultar profunditat del arbre",//5
                    "Sortir"//6
                    };
    int user;
    WordIndexer* wordId = nullptr;
    do{
        try{
            user = opcions.demanar("Gestió de paraules"); //Llança exception si la consola es out of range
            
            if(wordId == nullptr && user != 1 && user != 6)
                throw runtime_error("Encara está buit"); // Només 1 o 6 son válidas si wordId es null
            
            auto begin = chrono::steady_clock::now(); //Inici del relotge
            switch (user){

                case 1:{
                    char triada = Menu::demanaSN("Quin fitxer vols", 'P', 'G');

                    begin = chrono::steady_clock::now(); // Reinici del relotge
                    if( wordId  != nullptr) 
                        delete wordId;

                    if (triada == 'P')
                        wordId = new WordIndexer("shortText.txt");
                    else
                        wordId = new WordIndexer("longText.txt");
                
                    break;
                }
                case 2:{
                    int fets = 0;
                    print4040(wordId->getRoot(),fets);
                    cout << "Fets: " << fets<< endl;
                    break;
                }
                case 3:{
                    ifstream dades ("dictionary.txt");
                    if (!dades.is_open()) 
                        throw runtime_error("Error al obrir dictionary.txt");
                
                    string paraula;
                    while (dades >> paraula)
                        wordId-> contains(paraula);
                    dades.close();

                    break;
                }
                case 4:{              
                    wordId->printDictionary();
                    break;
                }
                case 5:{
                    cout <<"Profunditat: " << wordId->height() << endl;
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

        }
        catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
        }
        catch (const string& s){
            cout << s << endl;
        }
    } while (user != 6);
}