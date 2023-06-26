#ifndef LAB_THREE_INIT_H
#define LAB_THREE_INIT_H

struct point {
    int x, y;
};

struct vector {
    struct point A;
    struct point B;
};

class Triangle {
private:
    struct point A;
    struct point B;
    struct point C;
public:
    Triangle();
    Triangle(double x1, double y1, double x2, double y2, double x3, double y3);
    Triangle(struct point *pa, struct point *pb, struct point *pc);

    struct point GetPointA();
    struct point GetPointB();
    struct point GetPointC();

    double Side(struct point *pa, struct point *pb);
    double Perimeter();
    double Area();
    void MoveTriangle(struct vector *v);

    bool operator == (Triangle s);
    bool operator != (Triangle s);
    bool operator < (Triangle s);
    bool operator > (Triangle s);
};

class Stack {
private:
    int *m;
    int maxsize, top;
public:
    Stack();
    Stack(int max_s);
    Stack(const Stack &t);
    ~Stack();

    int GetM(int i);
    int GetMaxsize();
    int GetTop();

    void Push(int t);
    int Top();
    void Pop();
    bool Empty();
    void ShowStack();

    void operator<<(int t);
    void operator>>(int &k);
};

/*class Stack {
private:
    int m[100];
    int maxsize, top;
public:
    Stack();
    Stack(const Stack &t);

    int GetM(int i);
    int GetMaxsize();
    int GetTop();

    void Push(int t);
    float Top();
    void Pop();
    bool Empty();
    void ShowStack();

    void operator<<(int t);
    void operator>>(int &k);
};*/

#endif //LAB_THREE_INIT_H


