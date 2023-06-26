#include "lab_four_init.h"
#include <iostream>
#include <cmath>

double Hexagon::Area() const {
    double side = sqrt(pow((B.x - A. x), 2) + pow((B.y - A.y), 2));
    double S = (3*sqrt(3)*pow(side, 2)) / 2;
    return S;
};

double Hexagon::Perimeter() {
    double side = Side(A, B);
    double P = side*6;
    return P;
}

void Hexagon::Draw() {
    std::cout << "Coordinates of Hexagon: " << "(" << A.x << ", " << A.y << "), ";
    std::cout << "(" << B.x << ", " << B.y << "), ";
    std::cout << "(" << C.x << ", " << C.y << "), ";
    std::cout << "(" << D.x << ", " << D.y << "), ";
    std::cout << "(" << E.x << ", " << E.y << "), ";
    std::cout << "(" << F.x << ", " << F.y << "), ";
}

Point Hexagon::CenterPosition() {
    double R = Side(A, F);
    Point MassCenter{};
    MassCenter.y = R*sin(std::numbers::pi / 3);
    MassCenter.x = (A. x + F.x) / 2;
    return MassCenter;
}

double Hexagon::Side(Point A, Point B) {
    double side = sqrt(pow((B.x - A. x), 2) + pow((B.y - A.y), 2));
    return side;
}

unsigned int Hexagon::Size() {
    return sizeof(*this);
}

double Hexagon::Mass() const {
    double Volume = Area() * h;
    return Volume*p;
}

bool Hexagon::operator==(IPhysObject &ob) const {
    return (Mass() == ob.Mass());
}

bool Hexagon::operator<(IPhysObject &ob) const {
    return (Mass() < ob.Mass());
}

const char *Hexagon::Classname() {
    return "Hexagon";
}

void Hexagon::InitFromDialog() {
    std::cout << "Enter coordinates of point A" << "\n";
    std::cin >> A.x >> A.y;
    std::cout << "Enter coordinates of point B" << "\n";
    std::cin >> B.x >> B.y;
    std::cout << "Enter coordinates of point C" << "\n";
    std::cin >> C.x >> C.y;
    std::cout << "Enter coordinates of point D" << "\n";
    std::cin >> D.x >> D.y;
    std::cout << "Enter coordinates of point E" << "\n";
    std::cin >> E.x >> E.y;
    std::cout << "Enter coordinates of point F" << "\n";
    std::cin >> F.x >> F.y;
}

Hexagon::Hexagon() {
    A = {0, 0};
    B = {3, 3};
    C = {6, 3};
    D = {9, 0};
    E = {6, -3};
    F = {3, -3};
};

void Ellipse::InitFromDialog() {
    std::cout << "Enter coordinates of center, then a, b and F";
    std::cin >> A.x >> A.y >> a >> b >> F;
}

double Ellipse::Area() const {
    double S = std::numbers::pi * a * b;
    return S;
}

double Ellipse::Perimeter() {
    double P = 4*(std::numbers::pi*a*b + pow((a - b), 2)) / (a + b);
    return P;
}

void Ellipse::Draw() {
    std::cout << "Center of ellipse: " << "(" << A. x << ", " << A.y << "); ";
    std::cout << "Other points: " << "(" << A.x << ", " << (A.y + a) << "), " <<  "(" << (A.x + b) << ", " << A.y << "), "  <<  "(" << (A.x - b) << ", " << A.y << "), " << "(" << A.x - b << ", " << A.y << ")";
}

double Ellipse::Mass() const {
    double Volume = Area() * h;
    return Volume * p;
}

Point Ellipse::CenterPosition() {
    return A;
}

bool Ellipse::operator==(IPhysObject &ob) const {
    return (Mass() == ob.Mass());
}

bool Ellipse::operator<(IPhysObject &ob) const {
    return (Mass() < ob.Mass());
}

const char *Ellipse::Classname() {
    return "Ellipse";
}

unsigned int Ellipse::Size() {
    return sizeof(*this);
}

Ellipse::Ellipse() {
    A.x = A.y = 0;
    a = 1;
    b = 2;
    F = 0.5;
}

double SumArea(std::vector<Figures *> m, int counter) {
    double sum = 0;
    for (int i = 0; i < counter; i++) {
        sum += (*m[i]).Area();
    }
    return sum;
}

double SumPerimeter(std::vector<Figures *> m, int counter) {
    double sum = 0;
    for (int i = 0; i < counter; i++) {
        sum += (*m[i]).Perimeter();
    }
    return sum;
}

void Draw(std::vector<IPrintable *> m, int counter) {
    double sum = 0;
    for (int i = 0; i < counter; i++) {
        (*m[i]).Draw();
        std::cout << "\n";
    }
}

void Draw(std::vector<Figures *> m, int counter) {
    double sum = 0;
    for (int i = 0; i < counter; i++) {
        (*m[i]).Draw();
        std::cout << "\n";
    }
}

void CenterPosition(std::vector<Figures *> m, int counter) {
    std::cout << "Mass Centers: ";
    for (int i = 0; i < counter; i++) {
        Point A = (*m[i]).CenterPosition();
        std::cout << "(" << A.x << ", " << A.y << ");";
        std::cout << " ";
    }
    std::cout << "\n";
};

void SystemsCenter(std::vector<Figures *> m, int counter) {
    std::cout << "System's Center: ";
    double mass_sum = 0;
    Point Center;
    Center = {0, 0};
    double mass_current;
    for (int i = 0; i < counter; i++) {
        Point A = (*m[i]).CenterPosition();
        mass_current = (*m[i]).Mass();
        Center.x += A.x * mass_current;
        Center.y += A.y * mass_current;
        mass_sum += mass_current;
    }
    Center.x /= mass_sum;
    Center.y /= mass_sum;
    std::cout << "(" << Center.x << ", " << Center.y << ");";
    std::cout << " ";
};

unsigned int Size(std::vector<Figures *> m, int counter) {
    unsigned int sum = 0;
    for (int i = 0; i < counter; i++) {
        sum += (*m[i]).Size();
    }
    return sum;
}

void InitFigures (std::vector<Figures *> m, int counter) {
    for (int i = 0; i < counter; i++) {
        (*m[i]).InitFromDialog();
    }
};

void MassSort(std::vector<Figures *> m, int counter) {
    Figures * key;
    int j, i;
    for (i = 1; i < counter; i++) {
        key = m[i];
        j = i - 1;
        while ((j >= 0) && ((*key).Mass() <= (*m[j]).Mass())) {
            m[j + 1] = m[j];
            j--;
        }
        m[j + 1] = key;
    }
}
