#include "WordIndexerBalanced.h"
#include "BalancedTree.h"
#include "BinaryTree.h"
#include "Menu.h"
#include "Position.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>

//8 9 10 2 1 5 3 6 4
void mainEx1(){
    BinaryTree<int, int> tree1;
    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < 8 ; i++) {
        cout << "Inserta a l'arbre la key " << testKeys[i] << " amb valor " << testValues[i] << endl;
        tree1.insert(testKeys[i], testValues[i]);
    }
    cout << "Preorder = [";
    tree1.printPreOrder();
    cout << "]" << endl;
    cout << "Postorder = [";
    tree1.printPostOrder();
    cout << "]" << endl;
    BinaryTree<int, int> tree2(tree1);
    cout << " identics " << tree1.identicalTree(tree2) << endl;
    cout << "Preorder = [";
    tree1.printPreOrder();
    cout << "]" << endl;
    tree2.insert(4, 4);
    cout << " identics " << tree2.identicalTree(tree1) << endl;
    cout << "Preorder = [";
    tree2.printPreOrder();
    cout << "]" << endl;
    vector<int> result = tree2.getLeaves();
    cout << "fulles arbres = " ;
    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
    cout << *it << " ";
    }
    cout << endl;
    tree1.print(); //Extra
}
void mainEx2(){
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
                    wordId->print40();
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
void mainEx3(){
    BalancedTree<int, int> tree1;
    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < 8 ; i++) {
        cout << "Inserta a l'arbre la key " << testKeys[i] << " amb valor " << testValues[i] << endl;
        tree1.insert(testKeys[i], testValues[i]);
    }
    cout << "Preorder = [";
    tree1.printPreOrder();
    cout << "]" << endl;
    cout << "Postorder = [";
    tree1.printPostOrder();
    cout << "]" << endl;
    BinaryTree<int, int> tree2(tree1);
    cout << " identics " << tree1.identicalTree(tree2) << endl;
    cout << "Preorder = [";
    tree1.printPreOrder();
    cout << "]" << endl;
    tree2.insert(4, 4);
    cout << " identics " << tree2.identicalTree(tree1) << endl;
    cout << "Preorder = [";
    tree2.printPreOrder();
    cout << "]" << endl;
    vector<int> result = tree2.getLeaves();
    cout << "fulles arbres = " ;
    for (vector<int>::iterator it = result.begin(); it != result.end(); ++it) {
    cout << *it << " ";
    }
    cout << endl;
    tree1.print(); //Extra
}

void randomProva(int elements = 10){
    cout << "Prova del metode print amb " << elements << " valors random";
    for (int i = 0; i < 5; i++){
        cout<< endl<< "Abre #"<< i << endl;
        BinaryTree<int,int> t;
        for (int i = 0; i < elements; i++)
            t.insert(rand() % 101,1);
        t.print();
    }
}

void interactiuBalanced (){
    cout << "   ---  Arbre buit ---" << endl;
    cout << "---  Type '-1' per tancar --- " << endl;
    BalancedTree<int,int> arbre;
    int nou = 0;
    while (nou != -1){
        cout << "Nou element: ";
        cin >> nou;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Només Integers! (-1 per tancar)"<< endl;
        }
        else if (nou != -1)
            arbre.insert(nou,1);
        arbre.print();
    }
}
void interactiuNormal (){
    cout << "   ---  Arbre buit ---" << endl;
    cout << "---  Type '-1' per tancar --- " << endl;
    BinaryTree<int,int> arbre;
    int nou = 0;
    while (nou != -1){
        cout << "Nou element: ";
        cin >> nou;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Només Integers! (-1 per tancar)"<< endl;
        }
        else if (nou != -1)
            arbre.insert(nou,1);
        arbre.print();
    }
}

void provaMetodesArbre(){
    BinaryTree<int, int> tree;
    int testKeys[] =   {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < 8 ; i++)
        tree.insert(testKeys[i], testValues[i]);
    /* Hauriem de tindre aquest arbre
                   2                
        /              \        
       0               8        
                    /      \    
                   5       45   
                  /       /  \  
                 3       40  76 
    */
    
    cout << "Root "     << ((tree.getRoot()->getKey() == 2)?         "be" : "malament") << endl; 
    cout << "Search "   << ((tree.search(76)->getValues()[0] == 99)? "be" : "malament") << endl;
    cout << "Size "     << ((tree.size() == 8)?                      "be" : "malament") << endl;
    cout << "Empty "    << ((tree.isEmpty() == false)?               "be" : "malament") << endl;
    cout << "Height "   << ((tree.height() == 4)?                    "be" : "malament") << endl;
    cout << "Contains " << ((tree.contains(100) == false)?           "be" : "malament") << endl;
    cout << "Fulles:  "; Menu::printVector(tree.getLeaves()); cout << endl;

}


int main(){
    /*
    mainEx1();
    mainEx2();
    mainEx3();
    */
    interactiuNormal();
    interactiuBalanced();
}