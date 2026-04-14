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
        root = new Position<Key, Value> (key)
        root -> addValue(value); 
        _size ++; 
        return;
    }

    Position<Key, Value>* itr = root;






}

/* Consultors */
template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>::getRoot() const {return this->root;}
template <class Key, class Value>
int BinaryTree<Key, Value>::size() const {return _size;}
template <class Key, class Value>
const vector<Value>& BinaryTree<Key, Value>:: getValues(const Key& key) const {}

/* Operacions */template <class Key, class Value>
bool BinaryTree<Key, Value>::isEmpty() const{size() == 0;}
template <class Key, class Value>
int BinaryTree<Key, Value>::height() const {return getRoot()->height();}
template <class Key, class Value>
bool BinaryTree<Key, Value>::contains(const Key& key) const{}



/* Prints */
template <class Key, class Value>
void BinaryTree<Key, Value>::printPreOrder(const Position<Key, Value> *node = nullptr) const;
template <class Key, class Value>
void BinaryTree<Key, Value>::printPostOrder(const Position<Key, Value> *node = nullptr) const;
template <class Key, class Value>
bool BinaryTree<Key, Value>::identicalTree(const BinaryTree<Key, Value>& other) const;