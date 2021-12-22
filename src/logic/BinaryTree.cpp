//
// Created by z on 07-12-2021.
//
#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include "header/BinaryTree.h"
#include <iostream>

using namespace std;
using namespace cv;

void BinaryTree::insert(Mat image) {
    root = insert(root, image);
}
void BinaryTree::preOrder() {
    preOrder(root);
}
void BinaryTree::writeAppearances() {
    ofstream* file = new ofstream();
    file -> open("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/docs/results/information/appearances.txt");
    writeAppearances(root, file);
    file -> close();
    delete file;
}

void BinaryTree::writeImages() {
    writeImages(root);
}
void BinaryTree::writeTotalTime() {
    ofstream* file = new ofstream();
    file -> open("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/docs/results/information/information.txt");
    writeTotalTime(root, file);
    file -> close();
    delete file;
}

void BinaryTree::observeFiveIdentities() {
    int cant = 0;
    observeFiveIdentities(root, cant);
    destroyAllWindows();
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
        node->appearances.push_back(sequence);
        sequence++;
        return node;
    } else if ( SIMILAR < euclideanDistance(node->image, image)
                && DIFFERENT > euclideanDistance(node->image, image)) {
        node->left = insert(node->left, image);
    } else if (DIFFERENT <= euclideanDistance(node->image, image)) {
        node->right = insert(node->right, image);
    } else { //La cara es igual (menor a la distancia exigida para similar)
        node->image = image; //Cambio la imagen por la nueva
        node->timesAppeared++;
        node->appearances.push_back(sequence);
        sequence++;
    }
    return node;
}
void BinaryTree::preOrder(BinaryTreeNode *node) {
    if (node == nullptr)
        return;
    cout << "Llave: " <<  node->key << " Cantidad de veces que aparecio: " << node->timesAppeared << endl;
    preOrder(node->left);
    preOrder(node->right);
}
void BinaryTree::writeAppearances(BinaryTreeNode *node, ofstream* file) {
    if (node == nullptr) {
        return;
    }
    //Mostramos la informacion en la consola
    cout << "Key: " << node->key << " Apariciones:\n";
    for (int v : node->appearances) {
        cout << "Aparecio en la posicion " << v << " de la secuencia de imagenes\n";
    }
    //guardamos la informacion en el txt
    *file << "Key: " << to_string(node->key)  << " Apariciones:\n";
    for (int v : node->appearances) {
        *file << "Apareció en la posición " << to_string(v) << " de la secuencia de imágenes\n";
    }
    writeAppearances(node->left, file);
    writeAppearances(node->right, file);
}
void BinaryTree::writeTotalTime(BinaryTreeNode* node, ofstream* file) {
    if (node == nullptr) {
        return;
    }
    //Mostramos la informacion en la consola
    cout << "Key: " << node->key << ", Veces que aparecio: " << node->timesAppeared << "\n";

    //guardamos la informacion en el txt con los detalles de cada persona avistada
    *file << "Key: " << to_string(node->key) << ", Veces que apareció: " << to_string(node->timesAppeared) << "\n";
    writeTotalTime(node->left, file);
    writeTotalTime(node->right, file);
}
void BinaryTree::writeImages(BinaryTreeNode *node) {
    if (node == nullptr)
        return;
    //Creamos las imagenes en docs/results/images
    String path = "image_" + to_string(node->key) + ".jpg";
    imwrite("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/docs/results/images/" + path,node->image);
    writeImages(node->left);
    writeImages(node->right);
}
void BinaryTree::observeFiveIdentities(BinaryTreeNode *node, int cant) {
    if (node == nullptr or cant == 5)
        return;
    imshow("Image: ", node->image);
    waitKey(0);
    observeFiveIdentities(node->left, cant);
    observeFiveIdentities(node->right, cant);
}
BinaryTree::~BinaryTree() {
}