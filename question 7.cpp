// question 7
#include <iostream>

using namespace std;

template <typename T>
class TwoDim {
protected:
    T x, y;

public:
    // Default constructor
    TwoDim() : x(0), y(0) {}

    // Parameterized constructor
    TwoDim(T xVal, T yVal) : x(xVal), y(yVal) {}

    // Function to print coordinates
    void print() const {
        cout << "Coordinates: (" << x << ", " << y << ")" << endl;
    }
};

// Subclass ThreeDim inheriting from TwoDim
template <typename T>
class ThreeDim : public TwoDim<T> {
private:
    T z;

public:
    // Default constructor
    ThreeDim() : TwoDim<T>(), z(0) {}

    // Parameterized constructor
    ThreeDim(T xVal, T yVal, T zVal) : TwoDim<T>(xVal, yVal), z(zVal) {}

    // Function to print coordinates
    void print() const {
        cout << "Coordinates: (" << this->x << ", " << this->y << ", " << z << ")" << endl;
    }
};

int main() {
    // Using TwoDim with integers
    TwoDim<int> point2D(3, 5);
    point2D.print();

    // Using ThreeDim with doubles
    ThreeDim<double> point3D(1.2, 4.5, 6.7);
    point3D.print();

    // Runtime polymorphism
    TwoDim<double>* ptr = &point3D;
    ptr->print();

    return 0;
}
