#include "init.h"
#include <iostream>

int main() {
    class Triangle my_triangle = Triangle(0, 0, 0, 3, 4, 0);
    struct point C = my_triangle.GetPointC();
    std::cout << C.x << " " << C.y << "\n";
    std::cout << my_triangle.Area() << "\n";
    std::cout << my_triangle.Perimeter() << "\n";
    int res = 0;
    class Stack S; //неявный вызов конструктора по умолчанию
    S.Push(5);
    std::cout << S.Top() << "\n";
    S.Push(3);
    S.Pop();
    S.Pop();
    S.Top();
    S.Push(4);
    S.Push(6);
    S >> res;
    S << 8;
    std::cout << res << "\n";
    S.ShowStack();
    std::cout << "\n";
    if (S.Empty()) {
        std::cout << "Yes";
    }
    else {
        std::cout << "No";
    }
    return 0;
}
