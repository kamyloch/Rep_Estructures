#ifndef TUPLE_H
#define TUPLE_H
#include <string>
#include <sstream>
using namespace std;


template <class E>
class Tuple {

    public:
        /* Constructors */
        Tuple();
        Tuple(E,E);
        Tuple(const Tuple<E>&);

        /* Consultors */
        E getX() const;
        E getY() const;
        string str() const;

        /* Modificadors */
        void setX(E);
        void setY(E);

        /* Operadors */
        bool operator<(const Tuple<E>&) const;
        bool operator==(const Tuple<E>&) const;

    private:
        string convert_str(E)const;
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
bool Tuple<E>:: operator<(const Tuple&) const{
    return false; //TODO
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