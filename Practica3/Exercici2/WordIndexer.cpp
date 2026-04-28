#include "WordIndexer.h"
#include <iostream>
#include<vector>
#include <string>

/* Constructors */
WordIndexer::WordIndexer(){
    this->tree = new BinaryTree<string, Tuple<int>>();
}
WordIndexer:: WordIndexer (string path): WordIndexer(){
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
    if (tree != nullptr)
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
        cout << "No hi ha ocurrencies" << endl;
    else
        print(trobat->getValues());
}
void WordIndexer::printDictionary(Position<string, Tuple<int> > *node = nullptr) const{
    if (node == nullptr)
        node = tree->getRoot();

    if (node -> left() != nullptr)
        printDictionary(node->left());
    
    cout << node->getKey() << ": ";
    print(node->getValues());
    cout << endl;

    if (node->right() != nullptr)
        printDictionary(node->right());
}


/* Modificadors */
void WordIndexer::addText(std::string path){}

void WordIndexer::insertWord(const std::string &word, const int &line, const int &position){
    tree->insert(word, Tuple(line, position));
}
/* Metodes auxiliars, definiu-los aquí sota */

void WordIndexer:: print (const vector<Tuple<int>>& llista)const{
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
