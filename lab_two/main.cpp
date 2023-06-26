#include <iostream>
#include "second_lab.h"
int main() {
    QuadraticPolinomial f();
    QuadraticPolinomial s = QuadraticPolinomial(1, 2, 1);
    s.Print();
    std::cout << s.RootsQuantity() << "\n";
    std::cout << s.GetA() << "\n";
    std::cout << s.Result(4) << "\n";
    std::cout << s.FindMax() << "\n";
    std::cout << s.FindMin() << "\n";
    QuadraticPolinomial t = QuadraticPolinomial(1, -4, 3);
    QuadraticPolinomial res = s + t;
    res.Print();
    std::vector<double> roots = s.FindRoots();
    for (int i = 0; i < roots.size(); i++) {
        std::cout << roots[i] << " ";
    }
    std::cout << "\n";
    return 0;
}
