#include "second_lab.h"
#include <cmath>
QuadraticPolinomial::QuadraticPolinomial() {
    a = b = c = 0;
};

QuadraticPolinomial::QuadraticPolinomial(float A, float B, float C) {
    a = A;
    b = B;
    c = C;
};

QuadraticPolinomial::QuadraticPolinomial(const QuadraticPolinomial &s) {
    this->a = s.a;
    this->b = s.b;
    this->c = s.c;
}

float QuadraticPolinomial::GetA() {
    return a;
};

float QuadraticPolinomial::GetB() {
    return b;
}

float QuadraticPolinomial::GetC() {
    return c;
}

void QuadraticPolinomial::SetA(float A) {
    this->a = A;
};

void QuadraticPolinomial::SetB(float B) {
    this->b = B;
};

void QuadraticPolinomial::SetC(float C) {
    this->c = C;
};

double QuadraticPolinomial::Result(float x) {
    double res = pow(x,2)*a + x*b + c;
    return res;
};

int QuadraticPolinomial::RootsQuantity() {
    float d = pow(b,2) - 4*a*c;
    int k;
    (d > 0) ? (k = 2) : ((d == 0) ? k = 1 : k = 0);
    return k;
};

std::vector<double> QuadraticPolinomial::FindRoots() {
    std::vector<double> results;
    if (a == 0) {
        results.push_back((-1)*c / b);
    }
    float d = pow(b, 2) - 4*a*c;
    if (d > 0) {
        results.push_back((-b + std::sqrt(d)) / (2*a));
        results.push_back((-b - std::sqrt(d)) / (2*a));
    }
    else if (d == 0) {
        results.push_back(-b / (2*a));
    }
    return results;
};

double QuadraticPolinomial::FindMax() {
    float derivative = 2*a + b;
    float root = -b / (2*a);
    float second_derivative = 2*a;
    if (second_derivative >= 0) {
        return 1000000;
    }
    else {
        return root;
    }
}

double QuadraticPolinomial::FindMin() {
    float derivative = 2*a + b;
    float root = -b / (2*a);
    float second_derivative = 2*a;
    if (second_derivative >= 0) {
        return root;
    }
    else  {
        return 1000000;
    }
}
void QuadraticPolinomial::Print() {
    if (a != 0) {
        std::cout << a << "x^2";
    }
    if (b > 0) {
        std::cout << " + " << b << "x";
    }
    if (b < 0) {
        std::cout << " - " << std::abs(b) << "x";
    }
    if (c > 0) {
        std::cout << " + " << c << "\n";
    }
    if (c < 0) {
        std::cout << " - " << std::abs(c) << "\n";
    }

}

bool QuadraticPolinomial::operator==(const QuadraticPolinomial& s) {
    if ((this->a == s.a) and (this->b == s.b) and (this->c == s.c)) {
        return true;
    }
    else {
        return false;
    }
}

bool QuadraticPolinomial::operator!=(const QuadraticPolinomial& s) {
    if ((this->a == s.a) and (this->b == s.b) and (this->c == s.c)) {
        return false;
    }
    else {
        return true;
    }
}

QuadraticPolinomial QuadraticPolinomial::operator+(const QuadraticPolinomial& s) {
    float A = this->a + s.a;
    float B = this->b + s.b;
    float C = this->c + s.c;
    QuadraticPolinomial New = QuadraticPolinomial(A, B, C);
    return New;
}

QuadraticPolinomial QuadraticPolinomial::operator-(const QuadraticPolinomial& s) {
    float A = this->a - s.a;
    float B = this->b - s.b;
    float C = this->c - s.c;
    QuadraticPolinomial New = QuadraticPolinomial(A, B, C);
    return New;
}

QuadraticPolinomial QuadraticPolinomial::operator*(const QuadraticPolinomial& s) {
    float A = this->a * s.a;
    float B = this->b * s.b;
    float C = this->c * s.c;
    QuadraticPolinomial New = QuadraticPolinomial(A, B, C);
    return New;
}

QuadraticPolinomial QuadraticPolinomial::operator/(const QuadraticPolinomial& s) {
    float A = this->a / s.a;
    float B = this->b / s.b;
    float C = this->c / s.c;
    QuadraticPolinomial New = QuadraticPolinomial(A, B, C);
    return New;
};


