#include "init.h"
#include <iostream>

IndexEx::IndexEx(const char* msg) {
        this->msg = msg;
}

const char* IndexEx::what() {
        return msg;
}

WrongSize::WrongSize(const char *msg) {
        this->msg = msg;
}
const char* WrongSize::what() {
        return msg;
}

template <class T>
T find_max(T array[], int size) {
    T max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    return max;
}

template<class T>
 Matrix<T>::Matrix() {
        N = 3;
        M = 3;
        matrix = new T *[N];
        for (int i = 0; i < N; i++) {
            matrix[i] = new T[M];
            for (int j = 0; j < M; j++) {
                matrix[i][j] = 0;
            }
        }
}

template<class T>
Matrix<T>::Matrix(int rows, int columns) {
        matrix = new T *[rows];
        this->N = rows;
        this->M = columns;
        for (int i = 0; i < rows; i++) {
            matrix[i] = new T[columns];
            for (int j = 0; j < columns; j++) {
                matrix[i][j] = 0;
            }
        }
}
template<class T>
Matrix<T>::Matrix(const Matrix &Second) {
        this->N = Second.N;
        this->M = Second.M;
        matrix = new T *[N];
        for (int i = 0; i < this->N; i++) {
            matrix[i] = new T[M];
            for (int j = 0; j < this->M; j++) {
                this->matrix[i][j] = Second.matrix[i][j];
            }
        }
}
template<class T>
Matrix<T>::~Matrix() {
        for (int i = 0; i < M; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
    }

template<class T>
int Matrix<T>::Get_m() {
        return M;
    };

template<class T>
int Matrix<T>::Get_n() {
        return N;
    };

template<class T>
T Matrix<T>::Get_Matrix(int i, int j) {
        if ((i > N) or (i > M) or (i < 0)) {
            throw IndexEx("Index is out of range");
        }
        else {
            return matrix[i][j];
        }
    };

template<class T>
void Matrix<T>::Init() {
        std::cin >> N >> M;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                std::cin >> matrix[i][j];
            }
        }
    }

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix<T> &SecondM) {
        if ((this->N != SecondM.N) or (this->M != SecondM.M)) {
            throw WrongSize("Wrong size, cannot be added");
        }
        Matrix<T> NewMatrix(N, M);
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                NewMatrix.matrix[i][j] = this->matrix[i][j] + SecondM.matrix[i][j];
            }
        }
        return NewMatrix;
    }


template<class T>
Matrix<T> Matrix<T>::operator-(Matrix<T> &SecondM) {
        if ((this->N != SecondM.N) or (this->M != SecondM.M)) {
            throw WrongSize("Wrong size, cannot be subbed");
        }
        Matrix<T> NewMatrix(N, M);
        for (int i = 0; i < this->N; i++) {
            for (int j = 0; j < this->M; j++) {
                NewMatrix.matrix[i][j] = this->matrix[i][j] - SecondM.matrix[i][j];
            }
        }
        return NewMatrix;
    }

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix<T> &SecondM) {
        if ((Matrix<T>::M != SecondM.N)) {
            throw WrongSize("Wrong size, cannot be multiplied");
        }
        Matrix<T> NewMatrix(Matrix<T>::N, Matrix<T>::M);
        for (int i = 0; i < Matrix<T>::N; i++) {
            for (int j = 0; j < Matrix<T>::M; j++) {
                for (int k = 0; k < Matrix<T>::M; k++)
                    NewMatrix.matrix[i][j] += Matrix<T>::matrix[i][k] * SecondM.matrix[k][j];
            }
        }
        return NewMatrix;
    }
