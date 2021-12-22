//
// Created by z on 07-12-2021.
//

#ifndef ED21_02_ARAVENA_GALLEGUILLOS_BINARYTREE_H
#define ED21_02_ARAVENA_GALLEGUILLOS_BINARYTREE_H

#include "opencv2/core.hpp"
#include "BinaryTreeNode.h"
#include <fstream>
using namespace cv;
class BinaryTree {
private:
    int DIFFERENT = 1700;
    int SIMILAR = 1300;
    int counter;
    int sequence;
    struct BinaryTreeNode* root;
    BinaryTreeNode* insert(BinaryTreeNode* node, Mat);
    void preOrder(BinaryTreeNode* node);
    double euclideanDistance(Mat, Mat);
    void writeAppearances(BinaryTreeNode* node, std::ofstream* file);
    void writeTotalTime(BinaryTreeNode* node, std::ofstream* file);
    void writeImages(BinaryTreeNode* node);
    void observeFiveIdentities(BinaryTreeNode* node, int cant);

public:
    BinaryTree() {
        counter = 0;
        root = nullptr;
        sequence = 1;
    }
    void insert(Mat);
    void preOrder();
    void writeAppearances();
    void writeTotalTime();
    void writeImages();
    void observeFiveIdentities();


    BinaryTreeNode* getRoot();


    ~BinaryTree();
};


#endif //ED21_02_ARAVENA_GALLEGUILLOS_BINARYTREE_H
