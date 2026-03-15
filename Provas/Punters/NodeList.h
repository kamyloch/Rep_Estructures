#ifndef NODELIST_H
#define NODELIST_H

using namespace std;
template <class E>

class NodeList{
    public:
        //Constructors
        NodeList();
        NodeList(E);
        virtual ~Node();
    
        //Getters
        const NodeList<E>* accessPrevious() const;
        const E& accessElement() const;
        const NodeList<E>* accessNext() const;

        //Setters
        void setPrevious(const NodeList<E>*);
        void setNext(const NodeList<E>*);

        //Print
        void print() const;
        void println() const;

    private:
        NodeList<E>* _previous;
        E _element;
        NodeList<E>* _next;
    
};
/*******    Definició de mètodes    *******/
//Constructor
template <class E> NodeList<E>::NodeList(){
    this -> _previous = nullptr;
    this ->_next = nullptr;
}
template <class E> NodeList<E>::NodeList(E element){
    this -> _previous = nullptr;
    this-> _element = element;
    this ->_next = nullptr;
}

//Getters
template <class E> const NodeList<E>* NodeList<E>::accessPrevious()const{
    return _previous;
}
template <class E> const E& NodeList<E>::accessElement()const{
    return _element;
}
template <class E> const NodeList<E>* NodeList<E>::accessNext()const{
    return _next;
}

//Setters
template <class E> 
void NodeList<E>:: setPrevious(const NodeList<E>* nouPrev){
    this->_prev = prev;
}
template <class E> 
void NodeList<E>:: setNext(const NodeList<E>* nouNext){
    this->_next = nouNext;
}
//Print
template <class E> void NodeList<E>:: print()const{
    cout << "[" << _prev << ", " << _element << ", " << _next;

}
template <class E> void NodeList<E>:: println()const{
    print()
    cout << endl;
}
#endif