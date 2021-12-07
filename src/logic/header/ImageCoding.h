//
// Created by z on 07-12-2021.
//

#ifndef ED21_02_ARAVENA_GALLEGUILLOS_IMAGECODING_H
#define ED21_02_ARAVENA_GALLEGUILLOS_IMAGECODING_H

#include "opencv2/opencv.hpp"
using namespace cv;
class ImageCoding {
public:
    explicit ImageCoding();

    std::vector<Mat> codeGray(std::vector<Rect> detections, bool equalize, Size size);

    void setImage(Mat frame);
private:
    Mat frame;
};


#endif //ED21_02_ARAVENA_GALLEGUILLOS_IMAGECODING_H
