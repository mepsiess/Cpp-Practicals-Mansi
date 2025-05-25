#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

class Triangle {
    double a, b, c;

public:
    Triangle(double x=0, double y=0, double z=0) : a(x), b(y), c(z) {}

    double area() const {
        double s = (a+b+c)/2;
        return sqrt(s*(s-a)*(s-b)*(s-c));
    }

    double area(double base, double height) const {
        return 0.5 * base * height;
    }

    Triangle& operator=(const Triangle& t) {
        if (this != &t) { a = t.a; b = t.b; c = t.c; }
        return *this;
    }

    bool operator==(const Triangle& t) const {
        double sides1[3] = {a,b,c}, sides2[3] = {t.a,t.b,t.c};
        sort(sides1, sides1+3);
        sort(sides2, sides2+3);
        return equal(sides1, sides1+3, sides2);
    }
};

int main() {
    Triangle t1(3,4,5);
    cout << "Area (stored sides): " << t1.area() << "\n";
    cout << "Area (base,height): " << t1.area(7,13) << "\n";

    Triangle t2;
    t2 = t1;
    cout << (t2 == t1 ? "Triangles equal\n" : "Triangles not equal\n");

    return 0;
}
