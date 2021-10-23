#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/videoio.hpp>
#include <opencv2/highgui.hpp>
#include "logic/LinkedList.h"
#include <iostream>

using namespace std;
using namespace cv;

int main() {
    //Ruta donde se encuentra el video
    const string pathToVideo = "D:/Proyectos/CLion/Taller/src/resources/video.mp4";

    VideoCapture video(pathToVideo);

    //Verifica si se pudo cargar el video
    if (!video.isOpened()) {
        cout << "No se pudo abrir la referencia " << pathToVideo << endl;
        return -1;
    }

    CascadeClassifier faceCascade;
    faceCascade.load("D:/Proyectos/CLion/Taller/src/resources/haarcascade_frontalface_default.xml");

    //Color del detector de caras
    Scalar drawColor = Scalar(0, 0, 255);

    Mat frame;
    vector<Rect> faces;
    LinkedList array = LinkedList();

    while(video.read(frame)) {

        faceCascade.detectMultiScale(frame, faces, 1.1, 25);

        for (auto & area : faces){
            rectangle(frame, area.tl(), area.br(), drawColor, 3);
            Identidad i = Identidad(area);
            array.add(i);
            cout << area << endl;
        }

        //Muestra los frames
        imshow("Video", frame);
        waitKey(1);
    }
    cout << array.size();
    return EXIT_SUCCESS;
}

