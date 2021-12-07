//
// Created by z on 07-12-2021.
//

#include "header/BinaryTree.h"

#include <iostream>

using namespace std;

void BinaryTree::insert(Mat image) {
    root = insert(root, image);
}
void BinaryTree::preOrder() {
    preOrder(root);
}

double BinaryTree::euclideanDistance(Mat img1, Mat img2){
    return norm(img1, img2,NORM_L2);
}

BinaryTreeNode* BinaryTree::getRoot() {
    return this->root;
}

BinaryTreeNode* BinaryTree::insert(BinaryTreeNode* node, Mat image) {
    // Tolerancia para considerar una imagen igual
    //Si el árbol no tiene hijos
    if (node == nullptr){
        node = new BinaryTreeNode();
        node->key = ++counter;
        node->timesAppeared++;
        node->image = image;
        node->left = nullptr;
        node->right = nullptr;

        cout << "ID: " << node->key << endl;
        return node;
    } else if ( SIMILAR < euclideanDistance(node->image, image)
                && DIFFERENT > euclideanDistance(node->image, image)){
        node->left = insert(node->left, image);
    } else if (DIFFERENT <= euclideanDistance(node->image, image)){
        node->right = insert(node->right, image);
    } else { //La cara es igual (menor a la distancia exigida para similar)
        cout << "Distancia euclidea (Igual): " << euclideanDistance(node->image, image) << endl;
        node->image = image; //Cambio la imagen por la nueva
        node->timesAppeared++;
        cout << "Cara igual" << endl;
    }
    cout << "Distancia euclidea: " << euclideanDistance(node->image, image) << endl;
    return node;
}

void BinaryTree::preOrder(BinaryTreeNode *node) {
    if (node == nullptr)
        return;
    cout << "Llave: " <<  node->key << " Cantidad de veces que aparecio: " << node->timesAppeared << endl;
    preOrder(node->left);
    preOrder(node->right);
}

BinaryTree::~BinaryTree() {

}