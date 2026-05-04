#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include "Position.h"
template <class Key, class Value>
class BalancedTree : public BinaryTree<Key, Value> {
    
    public:
        BalancedTree();
        BalancedTree(const BalancedTree<Key, Value>& orig);
        virtual ~BalancedTree();
        Position<Key, Value>* insert(const Key& key, const Value& value);
    private:
        enum Rotations {LEFT, RIGHT, LEFTRIGHT, RIGHTLEFT};
        void r_left(Position<Key, Value>*);
        void r_right(Position<Key, Value>*);
        void r_leftRight(Position<Key, Value>*);
        void r_RightLeft(Position<Key, Value>*);
        /* Les rotacions, definiu-les aquí sota */
};
/*  --------   Definició de Mètodes  --------   */
template <class Key, class Value>
void BalancedTree <class Key, class Value> :: r_left(Position<Key, Value>* node){
    node->()
}
template <class Key, class Value>
void  BalancedTree <class Key, class Value> :: r_right(Position<Key, Value>* node){}
template <class Key, class Value>
void  BalancedTree <class Key, class Value> :: r_leftRight(Position<Key, Value>* node){}
template <class Key, class Value>
void BalancedTree <class Key, class Value> ::  r_RightLeft(Position<Key, Value>* node){}
#endif