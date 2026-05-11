#include "WordIndexerBalanced.h"
#include "BalancedTree.h"
#include <string>

/* Constructors */
WordIndexerBalanced:: WordIndexerBalanced (std::string path){
    this->tree = new BalancedTree<string, Tuple<int>>;
    addText(path);
}
WordIndexerBalanced:: WordIndexerBalanced (const WordIndexerBalanced& orig){
    BalancedTree<string, Tuple<int>>* treeOrig = dynamic_cast<BalancedTree<string, Tuple<int>>*>(orig.tree);
    if (treeOrig == nullptr)
        this->tree = new BalancedTree<string, Tuple<int>>();
    else
        this->tree = new BalancedTree<string, Tuple<int>>(*treeOrig);
}
WordIndexerBalanced:: ~WordIndexerBalanced(){
}