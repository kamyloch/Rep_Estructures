#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class Element>
class LinkedList
{
public:
 LinkedList();
 LinkedList(initializer_list<Element> elements);
 LinkedList(const LinkedList& origen);
 virtual ~LinkedList();
 int size() const;
 bool isEmpty() const;
 Position<Element> beginning() const; // return first position
 Position<Element> end() const; // return last position
 void insertAfter(Position<Element> & position, const Element& element);
 void insertBefore(Position<Element>& position, const Element& element);
    void insertBeginning(const Element& element);
    void insertEnd(const Element& element);
    void deletePosition(Position<Element>& position);
    void print() const;
    private:
        NodeList<Element>* _head;
        NodeList<Element>* _tail;
        int _size;
};