#include "WordIndexer.h"

WordIndexer::WordIndexer(){
    this->tree = new BinaryTree<string, Tuple<int>>();
}
WordIndexer WordIndexer::(std::string path){}
WordIndexer WordIndexer::(const WordIndexer& orig){}
WordIndexer:: ~WordIndexer(){}

/* Consultors */
int WordIndexer::size() const{}
int WordIndexer::height() const{}
bool WordIndexer::contains(const std::string &word) const{}

/* Prints */
void WordIndexer::printOccurrences(const std::string &word) const{}
void WordIndexer::printDictionary(Position<string, Tuple<int> > *node = nullptr) const{}


/* Modificadors */
void WordIndexer::addText(std::string path){}

void WordIndexer::insertWord(const std::string &word, const int &line, const int &position){}
/* Metodes auxiliars, definiu-los aquí sota */
