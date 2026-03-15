//Autor: Camilo Chicaiza Toapanta
#ifndef POSITION_H
#define POSITION_H
#include "NodeList.h"
#include "LinkedList.h"

template <class Element>
class Position{
    // Permite que LinkedList acceda a _node directamente
    friend class LinkedList<Element>;
    public:
        //Constuctores
        Position(NodeList<Element>* node); //inicialitza la classe Position amb el node que rep com a paràmetre.
        Position(const Position& origen); //copia
        virtual ~Position();

        //Consultores
        Position<Element> next() const; //retorna la següent posició a l’actual.
        // No es modifica el contingut de l’actual posició.
        // Si no hi ha següent posició, aquest mètode ha de llençar una excepció.
        Position<Element> previous() const; // retorna l’anterior posició
        const Element& element() const; // retorna el contingut de l’actual posició

        //Modificadires
        NodeList<Element>* deletePosition();
        void setPrevious(NodeList<Element>* node); // assigna l’adreça de l’anterior node
        void setNext(NodeList<Element>* node); // assigna l’adreça del següent node

        //Operadores
        Position<Element> operator++() const; // sobrecarrega operador ++
        Position<Element> operator--() const; // sobrecarrega operador --
        bool operator==(const Position<Element> & other) const; // sobrecarrega operador ==
        bool operator!=(const Position<Element> & other) const; // sobrecarrega operador !=
        const Element & operator*() const; // sobrecarrega operador contingut
    private:
        NodeList<Element> * _node;
};
/*******    Definició de mètodes    *******/
//Constructores
template <class Element> 
Position<Element> :: Position (NodeList<Element>* node):_node(node){}
template <class Element> 
Position<Element> :: Position (const Position& origen):_node(origen._node){}
template <class Element>
Position<Element>::~Position() {
}
//Consultores
template <class Element> 
Position<Element> Position<Element>::next()const{
    if(_node ->accessNext() == nullptr)
        throw out_of_range("El seguent punter está buid");
    NodeList<Element>* nextNode = this->_node ->accessNext();
    return Position<Element>(nextNode);
}
template <class Element> 
Position<Element> Position<Element>::previous()const{
    if(_node ->accessPrevious() == nullptr)
        throw out_of_range("L'anterior punter está buid");
    NodeList<Element>* prevNode = this->_node ->accessPrevious();
    return Position<Element>(prevNode);
}
template <class Element> 
const Element& Position<Element>::element()const{
    if (_node->accessPrevious() == nullptr || _node->accessNext() == nullptr)
        throw runtime_error("El node fantasma no té element");
    return this->_node ->accessElement();
}

//Modificadores
template <class Element> 
NodeList<Element>* Position<Element>::deletePosition(){
    NodeList<Element>* ant = this-> _node -> accessPrevious();
    NodeList<Element>* seg = this-> _node -> accessNext();

    //Lo borramos de la cadena
    if (ant != nullptr)
        this->_node->accessNext()->setPrevious(ant);
    if (seg != nullptr)
        this->_node->accessPrevious()->setNext(seg);

    //Lo aislamos
    this->_node->setNext(nullptr);
    this->_node->setPrevious(nullptr);
    return this->_node;
}
template <class Element> 
void Position<Element>::setPrevious(NodeList<Element>* node){
    this->_node->setPrevious(node);
}
template <class Element> 
void Position<Element>::setNext(NodeList<Element>* node){
    this->_node->setNext(node);
}
template <class Element> 

//Operadores
Position<Element> Position<Element>::operator++() const{
    return this-> next();
}
template <class Element> 
Position<Element> Position<Element>::operator--() const{
    return this-> previous();
}
template <class Element>
bool Position<Element>:: operator==(const Position<Element> & other) const{
    return this->_node == (other._node);
}
template <class Element>
bool Position<Element>::operator!= (const Position<Element> & other) const{
    return !(*this == other);
}
template <class Element>
const Element &  Position<Element>:: operator*() const{
    return element();
} 
 
#endif