#include "lab_four_init.h"
#include <iostream>
#include <vector>

int main() {
    Hexagon H;
    //std::vector<IGeoFig*> m;
    std::vector<Figures*> m;
    m.resize(3);
    int size = 3;
    int k;
    unsigned char type;
    m[0] = new Ellipse();
    m[1] = new Hexagon();
    m[2] = new Ellipse();
    std::cin >> k;
    for (int i = 0; i < k; i++) {
        std::cin >> type;
        if (type == 'e') {
            Figures * t = new Ellipse();
            m.push_back(t);
        }
        else {
            if (type == 'h') {
                Figures * t = new Hexagon();
                m.push_back(t);
            }
        }
        size = m.size();
    }
    //Draw(((IPhysObject*)m[0]), size);
    Draw(m, size);
    std::cout << SumPerimeter(m, size) << "\n";
    std::cout << SumArea(m, size) << "\n";
    CenterPosition(m, size);
    SystemsCenter(m, size);
    MassSort(m, size);
    std::cout << "\n";
    return 0;
}
