#ifndef NODE_H
#define NODE_H

using namespace std;
template <class E>

class Node{
    public:
        //Constructors
        Node(Node<E>*, E, Node<E>*);
        ~Node();
    
        //Getters
        const Node<E>* getPrev() const;
        const E& get() const;
        const Node<E>* getNext() const;

        //Setters
        void setPrev(const Node<E>*);
        void set(const E&);
        void setNext(const Node<E>*);

        //Print
        void print() const;
        void println() const;

    private:
        Node<E>* _prev;
        E _element;
        Node<E>* _next;
    
};
/*******    Definició de mètodes    *******/
//Constructor
template <class E> Node<E>::Node(Node<E>* prev, E element, Node<E>*next){
    this -> _prev = prev;
    this-> _element = element;
    this ->_next = next;
}

//Getters
template <class E> const Node<E>* Node<E>::getPrev()const{
    return _element;
}
template <class E> const E& Node<E>::get()const{
    return _element;
}
template <class E> const Node<E>* Node<E>::getNext()const{
    return _element;
}

//Setters
template <class E> void Node<E>:: setPrev(const Node<E>* nouPrev){
    this->_prev = prev;
}
template <class E> void Node<E>:: set(const E& nouE){
    this->_element = nouE;
}
template <class E> void Node<E>:: setPrev(const Node<E>* nouNext){
    this->_next = nouNext;
}
//Print
template <class E> void Node<E>:: print()const{
    cout << "[" << _prev << ", " << _element << ", " << _next;

}
template <class E> void Node<E>:: println()const{
    print()
    cout << endl;
}



#endif