#include "Vetor3.h"

Vetor3::Vetor3()
:x(0), y(0), z(0){

}

Vetor3::Vetor3(float xin, float yin, float zin)
:x(xin), y(yin), z(zin){

}

Vetor3::Vetor3(const Vetor3 &vOther){
    this->x = vOther.x;
    this->y = vOther.y;
    this->z = vOther.z;
}

float Vetor3::getMagnitude(){
    return std::sqrt(x*x + y*y + z*z);
}

void Vetor3::operator+(const Vetor3 &vOther){
    this->x = this->x + vOther.x;
    this->y = this->y + vOther.y;
    this->z = this->z + vOther.z;
}
    // Subtração

