#include "WordIndexerBalanced.h" //Inclou BinaryTree, BalancedTree, WordIndexer
#include "Menu.h"     //Clase auxiliar (Ex2,4)
#include <fstream>    //Files
#include <iostream>   //Consola
#include <stdexcept>  //Gestió exceptions (Menu)
#include <chrono>     //Per mesura (Ex5)
#include <functional> //Per mesura (Ex5)

void llegirDictionary(WordIndexer* wordId){ //Per Menu (Ex 2,4) i prova de temps (Ex 5)
    ifstream dades ("dictionary.txt");
    if (!dades.is_open())                    
        throw runtime_error("Error al obrir dictionary.txt");
    
    string paraula;         
    while (dades >> paraula)                        
        wordId-> contains(paraula);                    
    dades.close();
}

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
    tree2.print(); //Extra
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
            user = opcions.demanar("Gestió de paraules amb -BinaryTree-"); //Llança exception si la consola es out of range
            
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
                    llegirDictionary(wordId);
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
    BalancedTree<int, int> tree2(tree1);
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
    tree2.print(); //Extra
}
void mainEx4(){
    Menu opcions = {"Crea l'arbre", //1
                    "Mostra arbre 40 en 40", //2
                    "Llegir dictionary",//3
                    "Mostra index de paraules",//4
                    "Consultar profunditat del arbre",//5
                    "Sortir"//6
                    };
    int user;
    WordIndexerBalanced* wordId = nullptr;
    do{
        try{
            user = opcions.demanar("Gestió de paraule amb -BalancedTree-"); //Llança exception si la consola es out of range
            
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
                        wordId = new WordIndexerBalanced("shortText.txt");
                    else
                        wordId = new WordIndexerBalanced("longText.txt");
                
                    break;
                }
                case 2:{
                    wordId->print40();
                    break;
                }
                case 3:{
                    llegirDictionary(wordId);
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

void mesurar(string nombre, function<void()> func) { //Amb l'ajuda de Gemini
    auto inicio = std::chrono::high_resolution_clock::now();
    
    func(); 
    
    auto fin = std::chrono::high_resolution_clock::now();
    
    auto duracion_total = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    cout << nombre << ": " << duracion_total << " μs" << endl;
}
void mainEx5(){
    cout << " --- BinaryTree --- " << endl;
    WordIndexer* normal;
    cout << " - Cas Petit: " << endl;
    mesurar(" · Insersió", [&]() { normal = new WordIndexer("shortText.txt");});
    mesurar(" · Cerca",    [&]() { llegirDictionary(normal);});

    delete normal; normal = nullptr;

    cout << endl << " - Cas Large: " << endl;
    mesurar(" · Insersió", [&]() { normal = new WordIndexer("longText.txt");});
    mesurar(" · Cerca",    [&]() { llegirDictionary(normal);});

    delete normal; normal = nullptr;

    cout << endl << " - Cas Unbalanced: " << endl;
    mesurar(" · Insersió", [&]() { normal = new WordIndexer("unbalancedText.txt");});
    mesurar(" · Cerca",    [&]() { llegirDictionary(normal);});

    cout << endl << endl << " --- BalancedTree --- " << endl;
    WordIndexerBalanced* balanced;
    cout  << " - Cas Petit: " << endl;
    mesurar(" · Insersió", [&]() { balanced = new WordIndexerBalanced("shortText.txt");});
    mesurar(" · Cerca",    [&]() { llegirDictionary(balanced);});

    delete balanced; balanced = nullptr;

    cout << endl << " - Cas Large: " << endl;
    mesurar(" · Insersió", [&]() { balanced = new WordIndexerBalanced("longText.txt");});
    mesurar(" · Cerca",    [&]() { llegirDictionary(balanced);});

    delete balanced; balanced = nullptr;

    cout << endl << " - Cas Unbalanced: " << endl;
    mesurar(" · Insersió", [&]() { balanced = new WordIndexerBalanced("unbalancedText.txt");});
    mesurar(" · Cerca",    [&]() { llegirDictionary(balanced);});
    
}


//Mètodes Personalitzats
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
    mainEx4();
    mainEx5();
    provaMetodesArbre();
    interactiuNormal(); //8 9 10 2 1 5 3 6 4
    interactiuBalanced();
    */
   mainEx1();
    mainEx2();
    mainEx3();
    mainEx4();
    mainEx5();
   interactiuBalanced();
    
}