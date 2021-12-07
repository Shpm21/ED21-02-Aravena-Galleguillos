//
// Created by z on 07-12-2021.
//

#include "header/FaceDetector.h"

#include <sstream>
#include <vector>
#include <string>

FaceDetector::FaceDetector() {
    face_cascade.load("C:/Users/z/Desktop/Nueva_carpeta/C++Projects/Taller1/ED21-02-Aravena-Galleguillos/src/resources/haarcascade_frontalface_default.xml");
}

std::vector<cv::Rect> FaceDetector::detectRectangles(const cv::Mat &frame) {
    std::vector<cv::Rect> faces;
    Mat frameImage;

    cvtColor(frame, frameImage, COLOR_BGR2GRAY);

    equalizeHist(frameImage, frameImage);

    face_cascade.detectMultiScale(frameImage, faces, 1.05, 8, 0|CASCADE_SCALE_IMAGE, Size(50, 50));

    return faces;

}