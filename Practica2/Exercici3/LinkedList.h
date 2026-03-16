//Autor: Camilo Chicaiza Toapanta
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <initializer_list>
#include <stdexcept>
#include "Position.h"
#include "NodeList.h"

using namespace std;

template <class Element>
class LinkedList{
    public:
        //Constructores
        LinkedList();
        LinkedList(initializer_list<Element> elements);
        LinkedList(const LinkedList& origen);
        virtual ~LinkedList();

        //Consultures
        int size() const;
        bool isEmpty() const;
        Position<Element> beginning() const; // return first position
        Position<Element> end() const; // return last position

        //Modificadores (In- Out)
        void insertAfter(Position<Element> & position, const Element& element);
        void insertBefore(Position<Element>& position, const Element& element);
        void insertBeginning(const Element& element);
        void insertEnd(const Element& element);
        void deletePosition(Position<Element>& position);

        //print
        void print() const;
    private:
        NodeList<Element>* _head;
        NodeList<Element>* _tail;
        int _size;
};

/*******    Definició de mètodes    *******/
//Constructores
template <class Element> 
LinkedList<Element> :: LinkedList(){
    this->_size = 0;
    this->_head = new NodeList<Element>();//Element()???
    this->_tail = new NodeList<Element>();

    this->_head->setNext(_tail);
    this->_tail->setPrevious(_head);
}
template <class Element> 
LinkedList<Element> :: LinkedList(initializer_list<Element> elements): LinkedList(){
    for (Element x : elements)
        this->insertEnd(x);
}
template <class Element> 
LinkedList<Element> :: LinkedList(const LinkedList& origen): LinkedList(){
    Position<Element> it = origen.beginning();
    for (it; it != origen.end(); it = ++it)
        this->insertEnd(*it);
}
template <class Element> 
LinkedList<Element>::~LinkedList() {
    while (!isEmpty()) {
    Position<Element> p = beginning();
    deletePosition(p);
    }
    delete _head;
    delete _tail;
}

//Consultores
template <class Element> 
int LinkedList<Element> :: size() const{
    return this->_size;
}
template <class Element> 
bool LinkedList<Element> :: isEmpty() const{
    return size() == 0;
}
template <class Element> 
Position<Element> LinkedList<Element>::beginning() const{
    return Position<Element>(_head->accessNext());
}
template <class Element> 
Position<Element> LinkedList<Element> :: end() const{
    return Position<Element>(_tail);
}

//Modificadores
template <class Element> 
void LinkedList<Element> :: insertAfter(Position<Element> & position, const Element& element){
    if (position == end())
        throw out_of_range("No es pot afegir després de end()");

    //Fem el node
    NodeList<Element>* nouNode = new NodeList<Element>(element);
    Position<Element> seguent = ++position;
    //Conectem
    position.setNext(nouNode);
    seguent.setPrevious(nouNode);

    this->_size++;
}
template <class Element> 
void LinkedList<Element> :: insertBefore(Position<Element>& position, const Element& element){
    if (position == --beginning())
        throw out_of_range("No es pot afegir abands de --beggining()");
    
    //Fem el node i el d'abans
    NodeList<Element>* nouNode = new NodeList<Element>(element);
    Position<Element> anterior = --position;

    //Conectem
    position.setPrevious(nouNode);
    anterior.setNext(nouNode);

    this->_size++;
}
template <class Element> 
void LinkedList<Element> :: insertBeginning(const Element& element){
    //Fem posició fantasma
    Position<Element> fantasma = Position<Element>(_head);
    insertAfter(fantasma,element);
}
template <class Element> 
void LinkedList<Element> :: insertEnd(const Element& element){
    Position<Element> fantasma = end();
    insertBefore(fantasma, element);
}

template <class Element> 
void LinkedList<Element> ::  deletePosition(Position<Element>& position){
    if (position == --beginning())
        throw runtime_error("No es pot esborrar --beginning()");
    if(position == end())
        throw runtime_error("No es pot esborrar end()");
    delete position.deletePosition();
    this->_size--;
}

//Print
template <class Element> 
void LinkedList<Element> ::  print() const{
    if (isEmpty())
        cout << "[]" << endl;
    else{
        cout << "[";
        Position <Element> pos = beginning();
        for (pos; pos != end().previous(); pos = ++pos)
            cout << pos.element() << ", ";
        cout << pos.element() << "]"<< endl;
    }
}
#endif