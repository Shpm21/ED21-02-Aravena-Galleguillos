#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using std::vector;
using std::string;

using cv::Mat;
using cv::imread;
using cv::imshow;
using cv::waitKey;
using cv::Rect;
using cv::CascadeClassifier;
using cv::Scalar;
using cv::rectangle;

int main() {
    string path = "D:/Proyectos/CLion/Taller/src/resources/photo.jpg";
    Mat img = imread(path);

    CascadeClassifier faceCascade;
    faceCascade.load("D:/Proyectos/CLion/Taller/src/resources/haarcascade_frontalface_default.xml");

    vector<Rect> faces;
    faceCascade.detectMultiScale(img, faces, 1.1, 10);

    for (int i = 0; i < faces.size(); i++)
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(0, 0, 255), 3);

    imshow("Image", img);
    waitKey(3000);
    return 0;
}

