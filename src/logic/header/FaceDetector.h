//
// Created by z on 07-12-2021.
//
#ifndef ED21_02_ARAVENA_GALLEGUILLOS_FACEDETECTOR_H
#define ED21_02_ARAVENA_GALLEGUILLOS_FACEDETECTOR_H

#include "opencv2/opencv.hpp"

using namespace cv;
class FaceDetector {
public:
    explicit FaceDetector();

    std::vector<Rect> detectRectangles(const Mat &frame);
private:

    CascadeClassifier face_cascade;

};


#endif //ED21_02_ARAVENA_GALLEGUILLOS_FACEDETECTOR_H
