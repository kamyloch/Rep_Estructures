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
        WordIndexer();
        WordIndexer(std::string path);
        WordIndexer(const WordIndexer& orig);
        virtual ~WordIndexer();

        /* Consultors */
        int size() const;
        int height() const;
        bool contains(const std::string &word) const;

        /* Prints */
        void printOccurrences(const std::string &word) const;
        void printDictionary(Position<string, Tuple<int>> *node = nullptr) const;
        void print40() const;
    protected:
        BinaryTree<string, Tuple<int>> *tree;

        /* Modificadors */
        void addText(std::string path);

    private:
        void insertWord(const std::string &word, const int &line, const int &position);
        static void printVector (const vector<Tuple<int>>&);
        void print40_rec(int&,const Position<string, Tuple<int>> *node) const;

        /* Metodes auxiliars */
        static string trim(const string& cad);
};
#endif