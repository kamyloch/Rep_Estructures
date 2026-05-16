/*
Expliqueu a BalancedTree.h les similituds i
diferències en la implementació d’aquest TAD BalancedTree respecte al TAD BinaryTree. Detalleu quin
és el cost computacional teòric de cadascuna de les operacions del TAD.

Tots els métodes son els mateixos, peró l'únic que canvïa és "insert" que ara fa rotación sobre la branca
on s'ha fet la cerca binaria, aixo fa que l'arbre estigui equilibrat i la inserció dels nodes futurs sigui
óptima

El nou cost del insert ara es de O(logn) + O(logn) ja que fem cerca binària en un arbre perfecte (o quasi-perfecte)
i desprès hem de pujar per la branca fin a fer una rotació que equilibri l'arbre

Nota: Al codi optim hauriem de aturarnos quan fem una rotació al pujar per la branca, ja que aquesta fa que tots
els pares estiguin equilibrats, peró he fet que el codi pugi fins l'arrer per tenir l'alçada de tots el nodes sempre
correcta al fet getHeight();
*/
#ifndef BALANCED_TREE_H
#define BALANCED_TREE_H
#include "Position.h"
#include "BinaryTree.h"
#include <stdexcept>

using namespace std;

template <class Key, class Value>
class BalancedTree : public BinaryTree<Key, Value> {
    public:
        BalancedTree();//O(1) assina valors inicials
        BalancedTree(const BalancedTree<Key, Value>& orig);//O(n) copia cada node
        virtual ~BalancedTree();//O(n) destrueix cada node
        Position<Key, Value>* insert(const Key& key, const Value& value); //O(logn), la cerca binària sempre es óptima

    private://Tots són O(1) perquè nomes fan canvis entre els punters de com a molt 3 nodes
        void rotar_left(Position<Key, Value>*); //O(1)
        void rotar_right(Position<Key, Value>*);//O(1)
        void rotar_leftRight(Position<Key, Value>*);//O(1)
        void rotar_rightLeft(Position<Key, Value>*);//O(1)
        void upd_height(Position<Key, Value>*);//O(1)
        void balancejar(Position<Key, Value>*); //O(1)
        
};
/*  --------   Definició de Mètodes  --------   */
template <class Key, class Value>
BalancedTree<Key, Value>::BalancedTree() : 
    BinaryTree<Key, Value>()
{}
template <class Key, class Value>
BalancedTree<Key, Value>::BalancedTree(const BalancedTree<Key, Value>& orig) :
    BinaryTree<Key, Value>(orig)
{}
template <class Key, class Value>
BalancedTree<Key, Value>:: ~BalancedTree(){} //BSTree ja destrueix l'abre

template <class Key, class Value>
void BalancedTree<Key, Value>::upd_height(Position<Key, Value>* node){
    if(node == nullptr) return;

    int hLeft  = node->left()  == nullptr? 0 : node->left()-> getHeight();
    int hRight = node->right() == nullptr? 0 : node->right()->getHeight();

    node->setHeight((hLeft < hRight)? hRight+1: hLeft+1);
}

template <class Key, class Value>
Position<Key, Value>* BalancedTree<Key, Value>:: insert(const Key& key, const Value& value){
    Position<Key, Value>* nou = BinaryTree<Key, Value>::insert(key, value);
    if ((nou -> getValues()).size() != 1) return nou; // No cal balancejar si no hi ha nou node

    Position<Key, Value>* itr = nou;
    
    //Balancejem
    while(itr != nullptr){
        upd_height(itr->parent());
        balancejar(itr);
        itr = itr->parent();
    }
    return nou;
}

template <class Key, class Value>
void BalancedTree<Key, Value>:: balancejar(Position<Key, Value>* node){
    if(node->parent() == nullptr || node->parent()->parent() == nullptr)
        return;
    
    Position<Key, Value>* pare = node->parent();
    Position<Key, Value>* avi = pare->parent();

    int hLeft = 0, hRight = 0;

    if(avi->left() != 0)
        hLeft = avi->left()->getHeight();
    if(avi->right() != 0)
        hRight = avi->right()->getHeight();
    
    int diferencia = hRight - hLeft;

    switch (diferencia){
        case 2:{// Hi ha mes a la dreta
            if (pare->left() == node) //Doble
                rotar_rightLeft(avi);
            else
                rotar_left(avi);
            break;
            }
       
        case -2:{// Hi ha més a la esquerra
            if (pare->left() == node) 
                rotar_right(avi);
            else
                rotar_leftRight(avi); //Doble
            break;
            }
        
    }
}

template <class Key, class Value>
void BalancedTree <Key, Value> :: rotar_left(Position<Key, Value>* a){
    /*  Esquerra
        a      
         \                  b     
          b     --->      /  \
         / \             a    c
            c             \
    */
    if (a == nullptr || a ->right() == nullptr)
        throw runtime_error("No es pot rotar esquerra");

    Position<Key,Value>* b = a->right();

    //cout<< " --- Abans de rotar_left sobre :" << a->getKey() << " --- " << endl;
    //this->print();
    // a.parent <-> b
    if (!a->isRoot()){
        if (a->parent()->right() == a) //Si a es fill dret
            a->parent()->setRight(b);
        else
            a->parent()->setLeft(b);
    }
    else
        this->root = b; // Si no hi ha pare upd root
    b->setParent(a->parent());

    //Guardem la esquerra de b a la dreta d'a si hi ha
    a->setRight(b->left());
    if(b->left() != nullptr)
        b->left()->setParent(a);

    // b <-> a
    a->setParent(b);
    b->setLeft(a);

    //Uptade height
    upd_height(a);
    upd_height(b);
}
template <class Key, class Value>
void  BalancedTree <Key, Value> :: rotar_right(Position<Key, Value>* c){
    /*  Dreta
            c      
           /                b     
          b     --->      /  \
         / \             a    c
        a                    /
    */
    if (c == nullptr || c ->left() == nullptr)
        throw runtime_error("No es pot rotar dreta");

   Position<Key,Value>* b = c->left();

    //cout<< " --- Abans de rotar_right sobre :" << c->getKey() << " --- " << endl;
    //this->print();

    // c.parent <-> b
    if (!c->isRoot()){
        if (c->parent()->right() == c) //Si c es fill dret
            c->parent()->setRight(b);
        else
            c->parent()->setLeft(b);
    }
    else
        this->root = b; // Si no hi ha pare upd root
    b->setParent(c->parent());

    //Guardem la dreta de b a la esquerra de c si hi ha
    c->setLeft(b->right());
    if(b->right() != nullptr)
        b->right()->setParent(c);

    // b <-> c
    c->setParent(b);
    b->setRight(c);

    //Uptade height
    upd_height(c);
    upd_height(b);
}
template <class Key, class Value>
void  BalancedTree <Key, Value> :: rotar_leftRight(Position<Key, Value>* c){
    /*  Esquerra-Dreta
         c               c  
       /                /                  b     
      a        --->    b       --->      /  \
       \              / \               a    c
        b            a                      /
         \
    */
    if (c == nullptr || c ->left() == nullptr || c->left()->right() == nullptr)
        throw runtime_error("No es pot rotar esquerra-dreta");
    rotar_left(c->left());
    rotar_right(c);
}
template <class Key, class Value>
void BalancedTree <Key, Value> :: rotar_rightLeft(Position<Key, Value>* a){    
    /*  Dreta-Esquerra
        a              a 
         \              \                   b     
          c     --->    b       --->      /  \
         /             / \               a    c
        b                 c               \
       /              
    */
   if (a == nullptr || a ->right() == nullptr || a->right()->left() == nullptr)
        throw runtime_error("No es pot rotar dreta-esquerra");
    rotar_right(a->right());
    rotar_left(a);
   }
   
#endif