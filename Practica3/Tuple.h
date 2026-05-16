#ifndef TUPLE_H
#define TUPLE_H
#include <string>
#include <sstream>
using namespace std;


template <class E>
class Tuple {

    public://Clarament totes els que son O(1) ho son perque nomes assigna/retorna un punter o valor respecte a una possible estrutura com pot ser un arbre, llista,...
        /* Constructors */
        Tuple();//O(1)
        Tuple(E,E);//O(1)
        Tuple(const Tuple<E>&);//O(1)

        /* Consultors */
        E getX() const;//O(1)
        E getY() const;//O(1)
        string str() const;//O(1)

        /* Modificadors */
        void setX(E);//O(1)
        void setY(E);//O(1)

        /* Operadors */
        bool operator<(const Tuple<E>&) const;//O(1)
        bool operator==(const Tuple<E>&) const;//O(1)

    private:
        string convert_str(E)const;//O(1)
        E x;
        E y;
};
/*  --------   Definició de Mètodes  --------   */

/* Constructors */
template <class E>
Tuple <E>:: Tuple(){
    setX(0);
    setY(0);
}
template <class E>
Tuple <E>:: Tuple(E x_, E y_){
    setX(x_);
    setY(y_);
}
template <class E>
Tuple <E>:: Tuple(const Tuple& orig){
    setX(orig.getX());
    setY(orig.getY());
}

/* Consultors */
template <class E>
E Tuple <E>:: getX() const{
    return this->x;
}
template <class E>
E Tuple <E>:: getY() const{
    return this->y;
    
}
template <class E>
string Tuple<E>:: str() const{
    return "(" + convert_str(getX())  + ", " + convert_str(getY()) +  ")";
}

/* Modificadors */
template <class E>
void Tuple<E>:: setX(E x_){
    this->x = x_;
}
template <class E>
void Tuple<E>:: setY(E y_){
    this->y =  y_;
    
}
/* Operadors */
template <class E>
bool Tuple<E>:: operator<(const Tuple&) const{ //ni idea para que usarlo
    return true;
}
template <class E>
bool Tuple<E>::  operator==(const Tuple& org) const{
    return getX() == org.getX() && getY() == org.getY();
}
template <class E>
string Tuple<E>:: convert_str(E cordenada)const{
    stringstream ss;
    ss << cordenada;
    return ss.str();
}
#endif