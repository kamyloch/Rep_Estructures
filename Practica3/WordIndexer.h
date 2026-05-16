#ifndef WORD_INDEXER_H
#define WORD_INDEXER_H
#include "BinaryTree.h"
#include "Position.h"
#include "Tuple.h"  
#include <vector>
#include <string>


class WordIndexer {
    public:
        /* Constructors */
        WordIndexer(); //O(1)
        WordIndexer(std::string path);//O(nlogn) millor, O(n²) pitjor (si arbre lineal) (fa n cops InsertWord)
        WordIndexer(const WordIndexer& orig);//O(nlogn) millor, O(n²) pitjor (si arbre lineal) (fa n cops InsertWord)
        virtual ~WordIndexer();//O(n)

        /* Consultors */
        int size() const;//O(1)
        int height() const;//O(n)
        bool contains(const std::string &word) const; //O(n) pitjor, O(logn) millor 

        /* Prints */ //O(n) Obviament
        void printOccurrences(const std::string &word) const;
        void printDictionary(Position<string, Tuple<int>> *node = nullptr) const;
        void print40() const;
    protected:
        BinaryTree<string, Tuple<int>> *tree;

        /* Modificadors */
        void addText(std::string path);//O(nlogn) millor, O(n²) pitjor (si arbre lineal) (fa n cops InsertWord on n = #paraulas noves)

    private:
        void insertWord(const std::string &word, const int &line, const int &position);//O(n) pitjor, O(logn) millor
        void print40_rec(int&,const Position<string, Tuple<int>> *node,bool& ) const;

        /* Metodes auxiliars */
        static string trim(const string& cad);
        static void printVector (const vector<Tuple<int>>&);
};
#endif