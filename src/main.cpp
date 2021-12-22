#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/highgui.hpp>
#include "logic/header/FaceDetector.h"
#include "logic/header/ImageCoding.h"
#include "logic/header/BinaryTree.h"
#include <iostream>

using namespace std;
using namespace cv;

BinaryTree detectFaces();
BinaryTree guardMenu();
string gMenu();
void adminMenu(BinaryTree abb);
string aMenu();

int main() {
    BinaryTree abb;

    while (true) {
        string option;
        cout << "[1] Menu Guardia.\n[2] Menu Administrador.\n[3] Salir.\nElige una opcion: " << endl;
        cin >> option;
        if (option == "1") {
            abb = guardMenu();
        } else if (option == "2") {
            adminMenu(abb);
        } else if (option == "3") {
            break;
        } else {
            cout << "La opcion ingresada no es valida" << endl;
        }

    }
    return 0;
}

BinaryTree detectFaces() {
    cout << "Presiona Q para salir" << endl;
    vector<string> imagesStr;

    imagesStr.push_back("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/src/resources/image-007.jpeg");
    imagesStr.push_back("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/src/resources/image-008.jpeg");
    imagesStr.push_back("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/src/resources/image-024.jpeg");
    imagesStr.push_back("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/src/resources/image-025.jpeg");
    imagesStr.push_back("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/src/resources/image-026.jpeg");
    imagesStr.push_back("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/src/resources/image-046.jpeg");
    imagesStr.push_back("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/src/resources/image-047.jpeg");
    BinaryTree abb;
    FaceDetector faceDetector;
    ImageCoding icoding;
    Mat frame;
    //Color del detector de caras
    Scalar drawColor = Scalar(0, 0, 255);

    for (string im : imagesStr) {
        cout << im << endl;
        frame = imread(im, IMREAD_COLOR);
        auto faces = faceDetector.detectRectangles(frame);

        icoding.setImage(frame);
        auto faceCodingGray = icoding.codeGray(faces, true, Size(25, 25));
        Mat colorImage;
        Mat newSize;
        int posX = 10;
        for (const auto &cf : faceCodingGray){
            abb.insert(cf);
            cvtColor(cf, colorImage, COLOR_GRAY2BGR);
            resize(colorImage, newSize, Size(40, 40), INTER_LINEAR);
            newSize.copyTo(frame(Rect(posX, 10, newSize.cols, newSize.rows)));
            posX += 40 + 10;
        }

        for(const auto &fm : faces){
            rectangle(frame, fm, drawColor, 4);
        }
        imshow("Image: ", frame);
        waitKey(0);
    }
    while(true){
        int pressKey = waitKey(10);
        if (pressKey == 27 || pressKey == 113) break;
    }
    destroyAllWindows();
    return abb;
}

BinaryTree guardMenu() {
    cout << "Menu Guardia" << endl;
    BinaryTree abb;
    while (true) {
        string option = gMenu();
        if (option == "3") {
            break;
        } else if (option == "1") {
            abb = detectFaces();
        } else if (option == "2") {
            abb.observeFiveIdentities();
        } else {
            cout << "La opcion ingresada no es valida" << endl;
        }
    }
    return abb;
}

string gMenu() {
    string message = "[1] Observar rostos. \n[2] Observar ultimas 5 identidades.\n[3] Salir.\nElige una opcion: ";
    string option;
    cout << message << endl;
    cin >> option;
    return option;
}

void adminMenu(BinaryTree abb) {
    cout << "Menu Administrador" << endl;
    while (true) {
        string option = aMenu();
        if (option == "4") {
            break;
        } else if (option == "1") {
            abb.writeTotalTime();
            cout << "Las identidades han sido guardadas en docs/information/information.txt\n";
        } else if (option == "2") {
            abb.writeImages();
            cout << "Las imagenes han sido guardadas en docs/images\n";
        } else if (option == "3") {
            abb.writeAppearances();
            cout << "La informacion de las apariciones ha sido guardada en dosc/information/appearances.txt\n";
        }
        else {
            cout << "La opcion ingresada no es valida" << endl;
        }
    }
}

string aMenu() {
    string message = "[1] Obtener identidades detectadas.\n[2] Almacenar imagenes.\n[3] Informacion de apariciones.\n[4] Salir.\nElige una opcion: ";
    string option;
    cout << message << endl;
    cin >> option;
    return option;
}

