#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <initializer_list>

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
template <class Element> LinkedList<Element> :: LinkedList(){
    this->_size = 0;
    this->_head = nullptr;
    this->_tail = nullptr;
}
template <class Element> LinkedList<Element> :: LinkedList(initializer_list<Element> elements){
    LinkedList::LinkedList();
    //Queda por hacer
}

//Modificadores
template <class Element> void LinkedList<Element> :: insertBeginning(const Element& element){

}

#endif