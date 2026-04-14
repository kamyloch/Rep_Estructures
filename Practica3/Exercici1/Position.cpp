#include "Position.h"

/*  --------   Definició de Mètodes  --------   */

/* Constructor */
template <class Key, class Value>
Position<Key, Value>::Position(const Key key):
    key(k),
    right(nullptr),
    left(nullptr),
    pare(nullptr)
{}
template <class Key, class Value>
Position<Key, Value>::Position(const Position<Key, Value>& orig):
    Position(orig.getKey()),
    values(orig.getValues()),

{}

/* Modificadors */
template <class Key, class Value>
void Position<Key, Value>::setLeft(Position<Key,Value>* p){ left = p;}
template <class Key, class Value>
void Position<Key, Value>::setRight(Position<Key,Value>* p){ right = p;}
template <class Key, class Value>
void Position<Key, Value>::setParent(Position<Key,Value>* p){ pare = p;}
template <class Key, class Value>
void Position<Key, Value>::addValue(Value v){ values.push_back(v);}

/* Consultors */
template <class Key, class Value>
const Key&  Position<class Key, class Value>:: getKey() const { return key;}
template <class Key, class Value>
const vector<Value>& Position<class Key, class Value>:: getValues() const { return values;}
template <class Key, class Value>
Position<Key,Value>* Position<class Key, class Value>::getLeft() const{ return left;}
template <class Key, class Value>
Position<Key,Value>* Position<class Key, class Value>::getRight() const{ return right;}
template <class Key, class Value>
Position<Key,Value>* Position<class Key, class Value>::getParent() const{ return pare;}

/* Operacions */
template <class Key, class Value>
bool Position<Key, Value>:: isRoot() const{ return pare == nullptr;}
template <class Key, class Value>
bool Position<Key, Value>:: isLeaf() const{ return left == nullptr && right == nullptr;}
template <class Key, class Value>
int Position<Key, Value>:: depth() const{
    Position<Key,Value>* itr = this;
    int depth = 0;
    while(!(itr->isRoot())){
        itr = itr->getParent();
        depth ++;
    }
    return depth;
}
template <class Key, class Value>
int Position<Key, Value>:: height() const{
    return height_rec(this);
}
template <class Key, class Value>
int Position<Key, Value>:: height_rec(const Position<Key, Value>* node) const{
    if (node->isLeaf()) return 1;
    int izq = height_rec(node->getLeft(),izq)+1;
    int der = height_rec(node->getRigth(),der)+1;
    
    if (izq < der)
        return der;
    return izq;
}
    
template <class Key, class Value>
void Position<Key, Value>:: addValue(const Value& v){ values.push_back(v)}
template <class Key, class Value>
bool Position<Key, Value>:: operator==(const Position<Key, Value>& other) const{
    return other->getKey() == this->key;
}