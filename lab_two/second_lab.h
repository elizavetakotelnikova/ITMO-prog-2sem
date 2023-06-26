#ifndef LABS_SECOND_LAB_H
#define LABS_SECOND_LAB_H
#include <iostream>
#include <vector>
#include <cmath>
class QuadraticPolinomial {
public:
    QuadraticPolinomial();
    QuadraticPolinomial(float a, float b, float c);
    QuadraticPolinomial(QuadraticPolinomial const &s);

    float GetA();
    float GetB();
    float GetC();

    void SetA(float A);
    void SetB(float B);
    void SetC(float C);

    double Result(float x);
    int RootsQuantity();
    std::vector<double> FindRoots();
    double FindMin();
    double FindMax();
    void Print();

    bool operator == (const QuadraticPolinomial& s);
    bool operator != (const QuadraticPolinomial& s);
    QuadraticPolinomial operator + (const QuadraticPolinomial& s);
    QuadraticPolinomial operator - (const QuadraticPolinomial& s);
    QuadraticPolinomial operator * (const QuadraticPolinomial& s);
    QuadraticPolinomial operator / (const QuadraticPolinomial& s);

private:
    float a;
    float b;
    float c;
};

#endif //LABS_SECOND_LAB_H
