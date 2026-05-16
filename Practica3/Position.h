#ifndef POSITION_H
#define POSITION_H
#include <vector>

template <class Key, class Value>
class Position {
    public:
        Position(const Key key);//O(1) assina valors inicials
        Position(const Position<Key, Value>& orig);//O(1) la key i alçada del node però no els enllaços
        virtual ~Position();//O(n) Destrueix el node i tots els seus fills

        //Clarament totes els que son O(1) ho son perque nomes assigna/retorna un punter o valor

        /* Modificadors */
        void setLeft(Position<Key,Value>*);//O(1)
        void setRight(Position<Key,Value>*);//O(1)
        void setParent(Position<Key,Value>*);//O(1)
        void setHeight(int);//O(1)

        /* Consultors */
        const Key& getKey() const;//O(1)
        const std:: vector<Value>& getValues() const;//O(1)
        int getHeight() const;//O(1)
        Position<Key,Value>* left() const;//O(1)
        Position<Key,Value>* right() const;//O(1)
        Position<Key,Value>* parent() const;//O(1)

        /* Operacions */
        bool isRoot() const;//O(1)
        bool isLeaf() const;//O(1)
        int height() const; // O(n) on n = # de fills (si n = nodes d'un arbe llavors es O(n))
        int depth() const;//O(n) on n = # de pares (si n = nodes d'un arbe llavors es O(log(n)) en el millor y O(n) en el pitjor (arbre lineal))
        void addValue(const Value& value);//O(1)
        bool operator==(const Position<Key, Value>& other) const;//O(1)

        /* Extra (Com repte) */
        void mirror(); // O(n) on n = # de fills sota el node
        int countLeaves() const; // O(n) on n = #fills sota le node, es visita cada branca fin les fulles
    private:
        int alcada;
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
    pare(nullptr),
    alcada(1)
{}
template <class Key, class Value>
Position<Key, Value>::Position(const Position<Key, Value>& orig):
    Position(orig.getKey()){
    values = orig.getValues();
    alcada = orig.alcada;
}
template <class Key, class Value>
Position<Key, Value>::~Position(){
    //Destruim els fills abans de destruitme 
    if (this->left() != nullptr){
        delete this->left();
    }
    if (this->right() != nullptr){
        delete this->right();
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
void Position<Key, Value>::setHeight(int h){ alcada = h;}
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
template <class Key, class Value>
int Position<Key, Value>:: getHeight() const{return alcada;}

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
    if (isLeaf())
        return 1;
    int hIzq = left()  == nullptr? 0 : left() ->height();
    int hDer = right() == nullptr? 0 : right()->height();
    if (hIzq < hDer)
        return hDer+1;
    return hIzq+1;

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