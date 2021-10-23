#ifndef ED21_02_ARAVENA_GALLEGUILLOS_NODE_H
#define ED21_02_ARAVENA_GALLEGUILLOS_NODE_H
#include "Identidad.h"

using std::vector;

class Node {
private:
    Identidad identidad;
    Node* next;
public:
    Node();
    Node(Identidad identidad);
    Node* getNext();
    void setNext(Node* node);
    Identidad getIdentidad();
};

#endif //ED21_02_ARAVENA_GALLEGUILLOS_NODE_H