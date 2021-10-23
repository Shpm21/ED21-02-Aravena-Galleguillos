#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>

#include "Identidad.h"
using cv::Rect;
using std:: vector;

Identidad::Identidad() {

}
Identidad::Identidad(Rect rostro) {
    this->rostro = rostro;
}
Rect Identidad::getRostro() {
    return this->rostro;
}
int Identidad::getVecesObservado() {
    return this->vecesObservado;
}
void Identidad::setVecesObservado(int vecesObservado) {
    this->vecesObservado = vecesObservado;
}