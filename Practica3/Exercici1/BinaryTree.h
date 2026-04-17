#ifndef BINARY_TREE_H
#define BINARY_TREE_H
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
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
        //Extra
        //Completa a un arbre perfecte llavors la complexitat es O(2^n) si es una arbre lineal
        //Sino llavors es O(n) si ja es un arbre perfecte
        //Si es true imprime l'abre completat a perfecte amb nodes buits
        void print(bool b =  false) const;
    protected:
        Position<Key, Value>* root;

    private:
        int _size;
        Position<Key, Value>* search (Key) const;
        Position<Key, Value>* search_rec (Position<Key, Value>*, Key) const;
        void copy_rec (const Position<Key, Value>&, Position<Key, Value>*);
        bool identical_rec (const Position<Key, Value>*,const Position<Key, Value>*) const;

        //Per imprimir l'abre
        string center(string cad,  int n) const;
};
#include "BinaryTree.cpp"
#endif