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
        const Position<string, Tuple<int>>* getRoot() const;

        /* Prints */
        void printOccurrences(const std::string &word) const;
        void printDictionary(Position<string, Tuple<int>> *node = nullptr) const;
    protected:
        BinaryTree<string, Tuple<int>> *tree;

        /* Modificadors */
        void addText(std::string path);

    private:
        void insertWord(const std::string &word, const int &line, const int &position);
        static void print (const vector<Tuple<int>>&);

        /* Metodes auxiliars */
        static string trim(const string& cad);
};
#endif