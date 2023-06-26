#include "cmath"
#include "init.h"
#include "iostream"

Triangle::Triangle() {
    A.x = 0;
    A.y = 0;
    B.x = 0;
    B.y = 0;
    C.x = 0;
    C.y = 0;
};

Triangle::Triangle(double x1, double y1, double x2, double y2, double x3, double y3) {
    A.x = x1;
    A.y = y1;
    B.x = x2;
    B.y = y2;
    C.x = x3;
    C.y = y3;
};

Triangle::Triangle(struct point *pa, struct point *pb, struct point *pc) {
    A.x = pa->x;
    A.y = pa->y;
    B.x = pb->x;
    B.y = pb->y;
    C.x = pc->x;
    C.y = pc->y;
};
struct point Triangle::GetPointA() {
    return A;
};

struct point Triangle::GetPointB() {
    return B;
};

struct point Triangle::GetPointC() {
    return C;
};

double Triangle::Area() {
    double AB = Side(&A, &B);
    double BC = Side(&B, &C);
    double AC = Side(&A, &C);
    double half_perimetr = Perimeter() / 2;
    double area = sqrt(half_perimetr*(half_perimetr - AB)*(half_perimetr - BC)*(half_perimetr - AC));
    return area;
}

double Triangle::Side(struct point *pa, struct point *pb) {
    double AB = sqrt(pow((pb->x - pa->x),2) + pow((pb->y - pa->y),2));
    return AB;
}

double Triangle::Perimeter() {
    double AB = Side(&A, &B);
    double BC = Side(&B, &C);
    double AC = Side(&A, &C);
    return (AB + BC + AC);
}

void Triangle::MoveTriangle(struct vector *v) {
    A.x += (v->B.x - v->A.x);
    A.y += (v->B.y - v->A.y);
    B.x += (v->B.x - v->A.x);
    B.y += (v->B.y - v->A.y);
    C.x += (v->B.x - v->A.x);
    C.y += (v->B.y - v->A.y);
}

bool Triangle::operator==(Triangle s) {
    return (this->Area() == s.Area());
}

bool Triangle::operator!=(Triangle s) {
    return (this->Area() != s.Area());
}

bool Triangle::operator<(Triangle s) {
    return (this->Area() < s.Area());
}

bool Triangle::operator>(Triangle s) {
    return (this->Area() > s.Area());
}

Stack::Stack() {
    m = new int(100);
    maxsize = 100, top = -1;
}

Stack::Stack(int max_s) {
     if (max_s > 100) {
         max_s = 100;
     };
     maxsize = max_s;
     top = -1;
 };

Stack::~Stack() {
     delete[]m;
};

Stack::Stack(const Stack &t) {
    if (t.maxsize > 100) {
        m = new int(100);
        maxsize = 100;
        top = 100;
    }
    else {
        m = new int(maxsize);
        maxsize = t.maxsize;
        top = t.top;
    };
    for (int i = 0; i < maxsize; i++) {
        m[i] = t.m[i];
    }
};

int Stack::GetM(int i) {
    return m[i];
};

int Stack::GetMaxsize() {
    return maxsize;
}

int Stack::GetTop() {
    return top;
}

void Stack::Push(int t) {
    if (top == maxsize) {
        std::cout << "Error, Stack Overflow";
        return;
    }
    top++;
    m[top] = t;
}

int Stack::Top() {
    if (top == -1) {
        std::cout << "Stack underflow" << "\n";
        return 0;
    }
    return m[top];
}

void Stack::Pop() {
    top--;
}

bool Stack::Empty() {
    return  top == 0 ? true: false;
}

void Stack::operator<<(int t) {
    Push(t);
}

void Stack::operator>>(int &t) {
    t = Top();
    Pop();
}

void Stack::ShowStack() {
    for (int i = top; i >= 0; i--) {
        std::cout << m[i] << " ";
    }
}


/*
Stack::Stack() {
    int m[100];
    top = -1;
    maxsize = 100;
};

Stack::Stack(const Stack &t) {
    for (int i = 0; i < maxsize; i++) {
        m[i] = t.m[i];
    }
    maxsize = t.maxsize;
    top = t.top;
};

int Stack::GetM(int i) {
    return m[i];
};

int Stack::GetMaxsize() {
    return maxsize;
}

int Stack::GetTop() {
    return top;
}

void Stack::Push(int t) {
    if (top == maxsize) {
        std::cout << "Error, Stack Overflow";
        return;
    }
    top++;
    m[top] = t;
}

int Stack::Top() {
    if (top == -1) {
        std::cout << "Stack underflow" << "\n";
        return 0;
    }
    return m[top];
}

void Stack::Pop() {
    top--;
}

bool Stack::Empty() {
    return  top == 0 ? true: false;
}

void Stack::operator<<(int t) {
    Push(t);
}

void Stack::operator>>(int &t) {
    t = Top();
    Pop();
}

void Stack::ShowStack() {
    for (int i = top; i >= 0; i--) {
        std::cout << m[i] << " ";
    }
}*/
