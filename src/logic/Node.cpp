#include "Node.h"

Node::Node() {
    this->next = nullptr;
}
Node::Node(Identidad identidad) {
    this->identidad= identidad;
    this->next = nullptr;
}

Node* Node::getNext() {
    return next;
}

void Node::setNext(Node *node) {
    this->next = node;
}

Identidad Node::getIdentidad() {
    return this->identidad;
}