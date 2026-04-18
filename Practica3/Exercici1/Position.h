#ifndef POSITION_H
#define POSITION_H
#include <stdexcept>
#include <vector>
using namespace std;

template <class Key, class Value>
class Position {
    public:
        Position(const Key key);
        Position(const Position<Key, Value>& orig);
        virtual ~Position();

        /* Modificadors */
        void setLeft(Position<Key,Value>*);
        void setRight(Position<Key,Value>*);
        void setParent(Position<Key,Value>*);

        /* Consultors */
        const Key& getKey() const;
        const vector<Value>& getValues() const;
        Position<Key,Value>* getLeft() const;
        Position<Key,Value>* getRight() const;
        Position<Key,Value>* getParent() const;

        /* Operacions */
        bool isRoot() const;
        bool isLeaf() const;

        /* n = numero de nodes a l'abre
        El cost es en el pijor dels casos O(n) si l'abre es lineal i el node actual es fulla
        Però donat un arbre aleatori si es suposa que es perfecte llavoros es O(logn) */
        int depth() const;
    
        /* n = numero de nodes a l'abre
        El cost es en el pijor dels casos O(n) si l'abre es lineal i el node actual es arrel,
        tot i que no sigui un node aleatori en un arbre perfecte haurem de recorrer tot el que es a soa del node*/
        int height() const;
        void addValue(const Value& value);
        bool operator==(const Position<Key, Value>& other) const;

    private:
        Key key;
        vector<Value> values;        
        Position<Key,Value>* right;
        Position<Key,Value>* left;
        Position<Key,Value>* pare;
};
#include "Position.cpp"
#endif