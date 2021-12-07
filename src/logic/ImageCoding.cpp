//
// Created by z on 07-12-2021.
//

#include "header/ImageCoding.h"
#include <sstream>
#include <vector>

#include <string>

using namespace std;
ImageCoding::ImageCoding() {

}

std::vector<Mat> ImageCoding::codeGray(std::vector<Rect> detections, bool equalize, Size size) {
    Mat cropColor;
    Mat imageGray;
    Mat resizedDown;

    vector<Mat> cropFaces;
    for (const auto &det: detections) {
        cropColor = frame(det);
        cvtColor(cropColor, imageGray, COLOR_BGR2GRAY);
        if (equalize)
            equalizeHist(imageGray, imageGray);
        resize(imageGray, resizedDown, size, INTER_LINEAR);
        cropFaces.push_back(resizedDown.clone());

    }
    return cropFaces;
}

void ImageCoding::setImage(Mat frame) {
    this->frame = frame;
}
