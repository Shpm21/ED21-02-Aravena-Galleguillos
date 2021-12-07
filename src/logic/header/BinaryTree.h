//
// Created by z on 07-12-2021.
//

#ifndef ED21_02_ARAVENA_GALLEGUILLOS_BINARYTREE_H
#define ED21_02_ARAVENA_GALLEGUILLOS_BINARYTREE_H

#include "opencv2/core.hpp"
#include "BinaryTreeNode.h"

using namespace cv;
class BinaryTree {
private:
    int DIFFERENT = 1700;
    int SIMILAR = 1300;
    /**
     * Contador para asignar identificadores a las caras
     */
    int counter;
    struct BinaryTreeNode* root;
    BinaryTreeNode* insert(BinaryTreeNode* node, Mat);
    void preOrder(BinaryTreeNode* node);
    double euclideanDistance(Mat, Mat);

public:
    BinaryTree() {
        counter = 0;
        root = nullptr;
    }
    void insert(Mat);
    void preOrder();


    BinaryTreeNode* getRoot();


    ~BinaryTree();
};


#endif //ED21_02_ARAVENA_GALLEGUILLOS_BINARYTREE_H
