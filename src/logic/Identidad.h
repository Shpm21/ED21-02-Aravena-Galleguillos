#ifndef ED21_02_ARAVENA_GALLEGUILLOS_IDENTIDAD_H
#define ED21_02_ARAVENA_GALLEGUILLOS_IDENTIDAD_H
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>
using std::vector;
using cv::Rect;
class Identidad {
private:
    Rect rostro;
    int vecesObservado = 0;

public:
    Identidad();
    Identidad(Rect rostro);
    Rect getRostro();
    int getVecesObservado();
    void setVecesObservado(int vecesObservado);
};

#endif //ED21_02_ARAVENA_GALLEGUILLOS_IDENTIDAD_H