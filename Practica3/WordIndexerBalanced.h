#ifndef WORD_INDEXER_BALANCED_H
#define WORD_INDEXER_BALANCED_H
#include "WordIndexer.h"
#include "BalancedTree.h"
#include <string>
class WordIndexerBalanced : public WordIndexer {
    public:
        WordIndexerBalanced(std::string path); //O(nlogn) perquè sempre está balancejat, llavors fa n cops cercar el lloc (logn) i afegir
        WordIndexerBalanced(const WordIndexerBalanced& orig);//Amb n = #nodes_nous O(nlogn) perquè sempre está balancejat, llavors fa n cops cercar el lloc (logn) i afegir
        virtual ~WordIndexerBalanced();//O(n) cada node es destrueix
};
#endif