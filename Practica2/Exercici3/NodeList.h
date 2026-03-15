//Autor: Camilo Chicaiza Toapanta
#ifndef NODELIST_H
#define NODELIST_H

using namespace std;
template <class E>

class NodeList{
    public:
        //Constructors
        NodeList();
        NodeList(const E&);
        NodeList(const NodeList<E>&);
        virtual ~NodeList();
    
        //Getters
        NodeList<E>* accessPrevious() const;
        const E& accessElement() const;
        NodeList<E>* accessNext() const;

        //Setters
        void setPrevious(NodeList<E>*);
        void setNext(NodeList<E>*);

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
template <class E> 
NodeList<E>::NodeList():
    _previous (nullptr) , 
    _next(nullptr)  
{}
template <class E> 
NodeList<E>::NodeList(const E& element): NodeList(){
    _element = element;
}
template <class E> 
NodeList<E>::NodeList(const NodeList<E>& original):NodeList() {
    _element  = original.accessElement();
}
template <class E> 
NodeList<E>::~NodeList(){}

//Getters
template <class E> 
NodeList<E>* NodeList<E>::accessPrevious()const{
    return _previous;
}
template <class E>
const E& NodeList<E>::accessElement()const{
    return _element;
}
template <class E>
NodeList<E>* NodeList<E>::accessNext()const{
    return _next;
}

//Setters
template <class E> 
void NodeList<E>:: setPrevious(NodeList<E>* nouPrev){
    this->_previous = nouPrev;
}
template <class E> 
void NodeList<E>:: setNext(NodeList<E>* nouNext){
    this->_next = nouNext;
}
//Prints
template <class E> 
void NodeList<E>:: print()const{
    cout << "[" << _previous << ", " << _element << ", " << _next << "]\n";

}
template <class E> 
void NodeList<E>:: println()const{
    print();
    cout << endl;
}
#endif