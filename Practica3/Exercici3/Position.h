#ifndef POSITION_H
#define POSITION_H
#include <vector>

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
        const std:: vector<Value>& getValues() const;
        Position<Key,Value>* left() const;
        Position<Key,Value>* right() const;
        Position<Key,Value>* parent() const;

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

        /* Extra */
        /* n = numero de nodes a l'abre
        El cost es linieal sempre O(n)*/
        void mirror();
        int countLeaves() const;

    private:
        Key key;
        std:: vector<Value> values;        
        Position<Key,Value>* dreta;
        Position<Key,Value>* esquerra;
        Position<Key,Value>* pare;
};

/*  --------   Definició de Mètodes  --------   */

/* Constructor */
template <class Key, class Value>
Position<Key, Value>::Position(const Key key):
    key(key),
    dreta(nullptr),
    esquerra(nullptr),
    pare(nullptr)
{}
template <class Key, class Value>
Position<Key, Value>::Position(const Position<Key, Value>& orig):
    Position(orig.getKey()){
    values = orig.getValues();
}
template <class Key, class Value>
Position<Key, Value>::~Position(){
    //Destruim els fills abans de destruitme 
    Position<Key, Value>* izq = this->left();
    Position<Key, Value>* der = this->right();
    if (izq != nullptr){
        izq ->setParent(nullptr);
        delete izq;
    }
    if (der != nullptr){
        der ->setParent(nullptr);
        delete der;
    }
}

/* Modificadors */
template <class Key, class Value>
void Position<Key, Value>::setLeft(Position<Key,Value>* p){ esquerra = p;}
template <class Key, class Value>
void Position<Key, Value>::setRight(Position<Key,Value>* p){ dreta = p;}
template <class Key, class Value>
void Position<Key, Value>::setParent(Position<Key,Value>* p){ pare = p;}
template <class Key, class Value>
void Position<Key, Value>::addValue(const Value& v){ values.push_back(v);}

/* Consultors */
template <class Key, class Value>
const Key&  Position<Key, Value>:: getKey() const { return key;}
template <class Key, class Value>
const std:: vector<Value>& Position<Key, Value>:: getValues() const { return values;}
template <class Key, class Value>
Position<Key,Value>* Position<Key, Value>::left() const{ return esquerra;}
template <class Key, class Value>
Position<Key,Value>* Position<Key, Value>::right() const{ return dreta;}
template <class Key, class Value>
Position<Key,Value>* Position<Key, Value>::parent() const{ return pare;}

/* Operacions */
template <class Key, class Value>
bool Position<Key, Value>:: isRoot() const{ return pare == nullptr;}
template <class Key, class Value>
bool Position<Key, Value>:: isLeaf() const{ return esquerra == nullptr && dreta == nullptr;}
template <class Key, class Value>
int Position<Key, Value>:: depth() const{
    if (isRoot()) return 0;

    return parent() -> depth()+1;
}
template <class Key, class Value>
int Position<Key, Value>:: height() const{   
    //return height_rec(this);
    if(isLeaf()) return 1;

    int izq=0, der=0;
    
    if (left() != nullptr)
        izq = left()->height()+1;

    if (right() != nullptr)
        der = right()->height()+1;
    
    if (izq > der)
        return izq;
    return der;
}
template <class Key, class Value>
bool Position<Key, Value>:: operator==(const Position<Key, Value>& other) const{
    return other.getKey() == this->key;    
}

/* Extra */
template <class Key, class Value>
void Position<Key, Value>::mirror(){
    Position<Key, Value>* aux = left();
    setLeft(right());
    setRight(aux);
    if(left() != nullptr)
        left()->mirror();
    if(right() != nullptr)
        right()->mirror();
}
template <class Key, class Value>
int Position<Key, Value>::countLeaves() const{
    if (isLeaf())
        return 1;
    int izq = 0;
    int der = 0;
    
    if(left() != nullptr)
        izq = left()-> countLeaves();
    if(right() != nullptr)
        der = right()->countLeaves();
    
    return izq + der;
}
#endif