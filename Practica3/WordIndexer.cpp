#include "WordIndexer.h" //Se incluye "BinaryTree.h", "Tuple.h", <vector>,  <string>
#include <iostream>
#include <fstream> 
#include <stdexcept> 
#include <cctype> 
using namespace std;

/* Constructors */
WordIndexer::WordIndexer(){
    this->tree = new BinaryTree<string, Tuple<int>>;
}
WordIndexer:: WordIndexer (string path){
    this->tree = new BinaryTree<string, Tuple<int>>;
    addText(path);
}
WordIndexer:: WordIndexer (const WordIndexer& orig){
    BinaryTree<string, Tuple<int>>* treeOrig = orig.tree;
    if (treeOrig == nullptr)
        this->tree = new BinaryTree<string, Tuple<int>>();
    else
        this->tree = new BinaryTree<string, Tuple<int>>(*treeOrig);
}
WordIndexer:: ~WordIndexer(){
    if (this->tree != nullptr)
        delete tree;
}

/* Consultors */
int WordIndexer::size() const{
    return tree->size();
}
int WordIndexer::height() const{
    return tree->height();
}
bool WordIndexer::contains(const std::string &word) const{
    return tree->contains(word);
}

/* Prints */
void WordIndexer::printOccurrences(const std::string &word) const{
    Position<string, Tuple<int>>* trobat = tree->search(word);

    if (trobat == nullptr)
        throw out_of_range("No hi ha ocurrencies");

    printVector(trobat->getValues());
}
void WordIndexer::printDictionary(Position<string, Tuple<int> > *node) const{
    if (size() == 0)
        throw out_of_range("Arbre buit");

    if (node == nullptr) 
        node = tree->getRoot(); // Cas inicial


    //InOrdre
    if (node -> left() != nullptr)
        printDictionary(node->left());
    
    cout << node->getKey() << ": "; //Key
    printVector(node->getValues()); // Ocurrencies
    cout << endl;

    if (node->right() != nullptr)
        printDictionary(node->right());
}
void WordIndexer::print40() const{
    if (this->tree == nullptr)
        throw runtime_error("Arbre no inicialitzat");
    int fets = 0;
    try{
        print40_rec(fets,this->tree->getRoot());
    }catch(string& e){
        //Recursivitat llista
    }

}
void WordIndexer::print40_rec(int& fets,const Position<string, Tuple<int>> *node) const{
    
    //Inordre
    if (node -> left() != nullptr)
        print40_rec(fets, node->left());

    //Pregunta
    if (fets !=0 && fets%40 == 0){
        //Demana
        string eleccio = "";
        while (eleccio != "n" && eleccio != "s"){
            cout << "Fets " + to_string(fets) + ", vols continuar? (s/n): ";
            cin >> eleccio;
        }
        //Tanca
        if (eleccio == "n")
            throw string("Recursivitat Llista");
    }
    //Print
    cout << node->getKey() << ": "; //Key
    printVector(node->getValues()); // Ocurrencies
    cout << endl;
    fets++;

    if (node->right() != nullptr)
        print40_rec(fets, node->right());
}


/* Modificadors */
void WordIndexer::addText(string path){
    ifstream dades (path);
    if (!dades.is_open())
        throw runtime_error("Error al obrir " + path);


    string linea;
    int fila = 1;
    while (getline(dades,linea)){
        stringstream ss(linea);
        string paraula;
        int col = 1;
        while (ss >> paraula) 
            insertWord(paraula,fila,col++);
        fila++;
    }
    
    dades.close();
}

void WordIndexer::insertWord(const std::string &word, const int &line, const int &position){
    Tuple<int> t(line, position);
    tree->insert(trim(word),t);
}

/* Metodes auxiliars*/
void WordIndexer:: printVector (const vector<Tuple<int>>& llista){
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
string WordIndexer:: trim(const string& cad){
    string sortida = "";
    for (char c : cad)
        if (isalpha(c))
            sortida += tolower(c);
    return sortida;
}
