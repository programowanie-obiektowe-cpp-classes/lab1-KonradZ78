#include <iostream>
#include <cmath>

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
    Wektor2D() : x(0.0), y(0.0) {
        num_wek++;
        std::cout << "Wektor (" << x << ", " << y << ") constructed. Total vectors: " << num_wek << std::endl;
    }

    Wektor2D(double x_val, double y_val) : x(x_val), y(y_val) {
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

    Wektor2D operator+(const Wektor2D& other) const {
        return Wektor2D(x + other.x, y + other.y);
    }

    double operator*(const Wektor2D& other) const {
        return x * other.x + y * other.y;
    }

    friend std::ostream& operator<<(std::ostream& os, const Wektor2D& vec) {
        os << "(" << vec.x << ", " << vec.y << ")";
        return os;
    }
};

int Wektor2D::num_wek = 0;

int main() {
    Wektor2D v1{}; // Konstruktor domyślny, wektor o wsp. [0, 0]
    v1.setX(1.);   // setter
    v1.setY(1.);   // setter
    double x1 = v1.getX(); // getter
    double y1 = v1.getY(); // getter

    Wektor2D v2 = Wektor2D::kart(2., 2.); // Użycie metody statycznej kart

    Wektor2D sum = v1 + v2; // dodawanie wektorów

    double prod = v1 * v2; // iloczyn skalarny

    std::cout << "v1: " << v1 << ", x1: " << x1 << ", y1: " << y1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "Sum: " << sum << std::endl;
    std::cout << "Scalar product: " << prod << std::endl;
    std::cout << "Remaining vectors: " << Wektor2D::populacja() << std::endl;

    return 0;
}
