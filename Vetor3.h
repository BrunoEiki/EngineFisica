#ifndef VETOR3_H
#define VETOR3_H
#include <cmath>

class Vetor3{

private:
    float x;
    float y;
    float z;

public:
// CONSTRUTORES
    Vetor3();
    Vetor3(float, float, float);
    Vetor3(const Vetor3 &vOther);

// DESTRUTOR
    ~Vetor3();

// MÉTODOS
    float getMagnitude();

    void operator+(const Vetor3 &);
    // Subtração
};
#endif