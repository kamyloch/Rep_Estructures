#ifndef WORD_INDEXER_BALANCED_H
#define WORD_INDEXER_BALANCED_H
#include "WordIndexer.h"
#include "BalancedTree.h"
#include <string>
class WordIndexerBalanced : public WordIndexer {
    public:
        WordIndexerBalanced(std::string path);
        WordIndexerBalanced(const WordIndexerBalanced& orig);
        virtual ~WordIndexerBalanced();
};
#endif