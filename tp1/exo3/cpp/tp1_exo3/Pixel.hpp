#include <iostream>

class Pixel {
public:
    Pixel();

    int getR() const;
    int getG() const;
    int getB() const;

    void setR(int r);
    void setG(int g);
    void setB(int b);

    friend std::ostream &operator<<(std::ostream &os, const Pixel &pixel);

private:
    int r, g, b;
};

Pixel::Pixel() {
    this->r = 0;
    this->g = 0;
    this->b = 0;
}

int Pixel::getR() const {
    return r;
}

int Pixel::getG() const {
    return g;
}

int Pixel::getB() const {
    return b;
}

void Pixel::setR(int r) {
    Pixel::r = r;
}

void Pixel::setG(int g) {
    Pixel::g = g;
}

void Pixel::setB(int b) {
    Pixel::b = b;
}

std::ostream &operator<<(std::ostream &os, const Pixel &pixel) {
    os << "[" << pixel.r << "," << pixel.g << "," << pixel.b << "] ";
    return os;
}
