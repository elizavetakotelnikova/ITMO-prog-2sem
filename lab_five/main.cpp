#include "init.h"
#include <iostream>
int main() {
    Matrix<double> First;
    Matrix<double> Second;
    double array[5] = {-1, 5, 7, -20, 4};
    std::cout << find_max(array, 5) << std::endl;
    First.Init();
    Second.Init();
    try {
        //std::cout << First.Get_Matrix(5, -1);
        Matrix<double> NewMatrix = First * Second;
        std::cout << First.Get_Matrix(3, 4);
    }
    catch (WrongSize &e) {
        std::cout << e.what() << std::endl;
    }
    catch (IndexEx &e) {
        std::cout << e.what() << std::endl;
    }
    return 0;
}
