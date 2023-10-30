#include <iostream>

class Wektor2D {
private:
    double x;
    double y;

public:
    // Konstruktor domyślny
    Wektor2D() : x(0.0), y(0.0) {}

    // Konstruktor nadający współrzędne
    Wektor2D(double _x, double _y) : x(_x), y(_y) {}

    // Setter dla współrzędnej x
    void setX(double _x) {
        x = _x;
    }

    // Setter dla współrzędnej y
    void setY(double _y) {
        y = _y;
    }

    // Getter dla współrzędnej x
    double getX() const {
        return x;
    }

    // Getter dla współrzędnej y
    double getY() const {
        return y;
    }

    // Przeciążony operator dodawania wektorów
    Wektor2D operator+(const Wektor2D& other) const {
        return Wektor2D(x + other.x, y + other.y);
    }

    // Przeciążony operator iloczynu skalarnego
    double operator*(const Wektor2D& other) const {
        return x * other.x + y * other.y;
    }
};
