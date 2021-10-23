#ifndef ED21_02_ARAVENA_GALLEGUILLOS_LINKEDLIST_H
#define ED21_02_ARAVENA_GALLEGUILLOS_LINKEDLIST_H
#include "Node.h"

class LinkedList {
private:
    Node* first = nullptr;
    int cant = 0;

public:
    void add(Identidad identidad);
    int size();
    bool isEmpty();
    Identidad get(int i);
};


#endif //ED21_02_ARAVENA_GALLEGUILLOS_LINKEDLIST_H