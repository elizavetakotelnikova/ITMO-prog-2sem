#ifndef LAB_THREE_LAB_FOUR_INIT_H
#define LAB_THREE_LAB_FOUR_INIT_H
#include <vector>
#define p 1;
#define h 1;

class IGeoFig {
public:
    virtual double Area() const = 0;
    virtual double Perimeter() = 0;
};

class Point {
public:
    double x, y;
};

class IPhysObject {
public:
    virtual double Mass() const = 0;
    virtual Point CenterPosition() = 0;
    virtual bool operator== (IPhysObject& ob) const = 0;
    virtual bool operator< (IPhysObject& ob) const = 0;
};

class IPrintable {
public:
    virtual void Draw() = 0;
};

class IDialogInitiable {
public:
    virtual void InitFromDialog() = 0;
};

class BaseObject {
public:
    virtual const char* Classname() = 0;
    virtual unsigned int Size() = 0;
};

class Figures : public IGeoFig, public IPrintable, public IPhysObject, public BaseObject, public IDialogInitiable {
};

class Hexagon : public Figures {
private:
    Point A, B, C, D, E, F;
public:
    Hexagon();

    void InitFromDialog() override;
    static double Side(Point A, Point B);
    double Area() const override;
    double Perimeter() override;
    void Draw() override;
    double Mass() const override;
    Point CenterPosition() override;
    bool operator== (IPhysObject &ob) const override;
    bool operator< (IPhysObject& ob ) const override;
    const char* Classname() override;
    unsigned int Size() override;
};

class Ellipse : public Figures {
private:
    Point A;
    double a, b, F;
public:
    Ellipse();

    void InitFromDialog() override;
    double Area() const override;
    double Perimeter() override;
    void Draw() override;
    double Mass() const override;
    Point CenterPosition() override;
    bool operator== (IPhysObject &ob) const override;
    bool operator< (IPhysObject& ob ) const override;
    const char* Classname() override;
    unsigned int Size() override;
};

double SumArea(std::vector<Figures *> m, int counter);
double SumPerimeter(std::vector<Figures *> m, int counter);
void Draw(std::vector<Figures *> m, int counter);
void CenterPosition(std::vector<Figures *> m, int counter);
void SystemsCenter(std::vector<Figures *> m, int counter);
unsigned int Size(std::vector<Figures *> m, int counter);
void MassSort(std::vector<Figures *> m, int counter);
void InitFigures (std::vector<Figures *> m, int counter);

#endif //LAB_THREE_LAB_FOUR_INIT_H
