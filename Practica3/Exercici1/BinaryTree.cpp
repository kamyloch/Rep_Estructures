#include "BinaryTree.h"
#include "Position.h"

/*  --------   Definició de Mètodes  --------   */
/* Constructor */
template <class Key, class Value>
BinaryTree<Key, Value>::BinaryTree():
    _size(0),
{}

/* Modificadors */
template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>:: insert(const Key& key, const Value& value){
    if (isEmpty()){
        root = new Position<Key, Value> (key);
        root -> addValue(value); 
        _size = 1; 
        return;
    }


    Position<Key, Value>* itr = root;
    Position<Key, Value>* itrPare = nullptr;
    
    bool trobat = false;
    while (itr != nullptr && !trobat){
        itrPare = itr;
        if (itr->getKey()< key)
            itr = itr->getRight();
        else if (itr->getKey()> key)
            itr = itr->getLeft();
        else 
            trobat = true;
    }

    if (trobat)
        itr->addValue(value);
    else{
        Position<Key, Value>* nou = new Position<Key, Value>(key);
        nou->setParent(itrPare);
        nou->addValue(value);
    }
}

/* Consultors */
template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>::getRoot() const {return this->root;}
template <class Key, class Value>
int BinaryTree<Key, Value>::size() const {return _size;}
template <class Key, class Value>
const vector<Value>& BinaryTree<Key, Value>:: getValues(const Key& key) const { 
    Position<Key, Value>* pos = search(key);
    if (key == nullptr);
        throw run_time_exception("No hi es aquesta clau");
}
template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>:: search_rec (Position<Key, Value>* node, Key key) const{
    if (node == nullptr) 
        return nullptr;
    if (node->getKey()< key)
        return search_rec(node->getRight(),key);
    if (node->getKey()> key)
        return search_rec(node->getLeft(),key);
    return node;
}
template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>:: search (Key key) const{ return search_rec(this->root, key);}

/* Operacions */template <class Key, class Value>
bool BinaryTree<Key, Value>::isEmpty() const{size() == 0;}
template <class Key, class Value>
int BinaryTree<Key, Value>::height() const {return getRoot()->height();}
template <class Key, class Value>
bool BinaryTree<Key, Value>::contains(const Key& key) const{}



/* Prints */
template <class Key, class Value>
void BinaryTree<Key, Value>::printPreOrder(const Position<Key, Value> *node = nullptr) const{}
template <class Key, class Value>
void BinaryTree<Key, Value>::printPostOrder(const Position<Key, Value> *node = nullptr) const{}
template <class Key, class Value>
bool BinaryTree<Key, Value>::identicalTree(const BinaryTree<Key, Value>& other) const{}