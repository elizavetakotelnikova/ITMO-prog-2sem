#ifndef LAB_FIFTH_INIT_H
#define LAB_FIFTH_INIT_H
#include <iostream>
#include <cmath>
#include <exception>

class IndexEx: public std::exception {
private: const char* msg;
public:
    IndexEx(const char* msg);
    const char* what();
};

class WrongSize: public std::exception {
private:
    const char *msg;
public:
    WrongSize(const char *msg);
    const char* what();
};

template <class T>
T find_max(T array[], int size);

template <class T>
class Matrix {
public:
    Matrix();
    Matrix(int rows, int columns);
    Matrix(const Matrix &Second);

    ~Matrix();

    int Get_m();
    int Get_n();
    T Get_Matrix(int i, int j);

    void Init();

    Matrix operator+(const Matrix<T> &SecondM);
    Matrix operator-(Matrix<T> &SecondM);
    Matrix operator*(Matrix<T> &SecondM);
    Matrix operator[](int i);

private:
    int N{}, M{};
    T **matrix;
};
#endif
