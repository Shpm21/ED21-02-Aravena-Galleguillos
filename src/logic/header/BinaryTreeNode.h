//
// Created by z on 07-12-2021.
//

#ifndef ED21_02_ARAVENA_GALLEGUILLOS_BINARYTREENODE_H
#define ED21_02_ARAVENA_GALLEGUILLOS_BINARYTREENODE_H


#include <opencv2/core/mat.hpp>

class BinaryTreeNode {
public:
    int key;
    cv::Mat image;
    int timesAppeared;
    BinaryTreeNode *left;
    BinaryTreeNode *right;
    std::vector<int> appearances;
};


#endif //ED21_02_ARAVENA_GALLEGUILLOS_BINARYTREENODE_H
