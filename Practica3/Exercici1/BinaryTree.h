#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <stdexcept>
#include "Position.h"
using namespace std;

template <class Key, class Value>
class BinaryTree {
    public:
        BinaryTree();
        BinaryTree(const BinaryTree<Key, Value>& orig);
        virtual ~BinaryTree();

        /* Modificadors */
        virtual Position<Key, Value>* insert(const Key& key, const Value& value);

        /* Consultors */
        Position<Key, Value>* getRoot() const;
        const vector<Value>& getValues(const Key& key) const;
        int size() const;

        /* Operacions */
        bool isEmpty() const;
        int height() const;
        bool contains(const Key& key) const;
        
        /* Prints */
        void printPreOrder(const Position<Key, Value> *node = nullptr) const;
        void printPostOrder(const Position<Key, Value> *node = nullptr) const;
        bool identicalTree(const BinaryTree<Key, Value>& other) const;
    
    protected:
        Position<Key, Value>* root;

    private:
        int _size;
        Position<Key, Value>* search (Key) const;
        Position<Key, Value>* search_rec (Position<Key, Value>*, Key) const;

        /* Mètodes auxiliars definiu aquí els que necessiteu */
};
#endif