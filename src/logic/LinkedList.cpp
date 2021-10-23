#include "LinkedList.h"

void LinkedList::add(Identidad identidad) {
    Node* newNodo = new Node(identidad);
    newNodo->setNext(first);
    first = newNodo;
    this->cant++;
}
int LinkedList::size() {
    return cant;
}

bool LinkedList::isEmpty() {
    return cant == 0;
}

Identidad LinkedList::get(int i) {
    Node* current = first;
    while (current) {
        if (i == 0)
            return current->getIdentidad();
        i -= 1;
        current = current->getNext();
    }
}