#include <iostream>


class Informer {
public:
    Informer() {
        std::cout << "Informer constructed." << std::endl;
    }

    ~Informer() {
        std::cout << "Informer destructed." << std::endl;
    }
};

class Wektor2D {
private:
    double x;
    double y;
    static int num_wek;
    Informer informer;

public:
    Wektor2D(double x_val = 0.0, double y_val = 0.0) : x(x_val), y(y_val) {
        num_wek++;
        std::cout << "Wektor (" << x << ", " << y << ") constructed. Total vectors: " << num_wek << std::endl;
    }

    ~Wektor2D() {
        num_wek--;
        std::cout << "Wektor (" << x << ", " << y << ") destructed. Remaining vectors: " << num_wek << std::endl;
    }

    static Wektor2D kart(double x_val, double y_val) {
        return Wektor2D(x_val, y_val);
    }

    static Wektor2D bieg(double r, double theta) {
        double x_val = r * cos(theta);
        double y_val = r * sin(theta);
        return Wektor2D(x_val, y_val);
    }

    double norm() const {
        return sqrt(x * x + y * y);
    }

    void print() const {
        std::cout << "(" << x << ", " << y << ")";
    }

    void setX(double x_val) {
        x = x_val;
    }

    double getX() const {
        return x;
    }

    void setY(double y_val) {
        y = y_val;
    }

    double getY() const {
        return y;
    }

    static int populacja() {
        return num_wek;
    }

    Wektor2D operator*(double scalar) const {
        return Wektor2D(x * scalar, y * scalar);
    }

    Wektor2D operator+(const Wektor2D& other) const {
        return Wektor2D(x + other.x, y + other.y);
    }

    friend std::ostream& operator<<(std::ostream& os, const Wektor2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int Wektor2D::num_wek = 0;

int main() 
    {
        Wektor2D v1 = Wektor2D::kart(3.0, 4.0);
        Wektor2D v2 = Wektor2D::bieg(5.0, 3.14 / 3);

        std::cout << "Vector 1: ";
        v1.print();
        std::cout << ", Norm: " << v1.norm() << std::endl;

        std::cout << "Vector 2: ";
        v2.print();
        std::cout << ", Norm: " << v2.norm() << std::endl;

        Wektor2D v3 = v1 + v2;
        std::cout << "Vector 3 (v1 + v2): " << v3 << std::endl;

        Wektor2D v4 = v2 * 2.0;
        std::cout << "Vector 4 (v2 * 2): " << v4 << std::endl;
    

    std::cout << "Remaining vectors: " << Wektor2D::populacja() << std::endl;

    return 0;
}
