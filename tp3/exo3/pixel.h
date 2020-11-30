//
// Created by victor SANDRE.
//

#ifndef EXO3_PIXEL_H
#define EXO3_PIXEL_H

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

    virtual std::string value () const;
protected:
    int r;
    int g;
    int b;
};

Pixel::Pixel() : r(0), g(0), b(0) {
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
    if (&pixel != nullptr)
        os << pixel.value();
    else
        os<<"nullptr";
    return os;
}

std::string Pixel::value() const {
    return std::string("[" + std::to_string(r) +
                       "," + std::to_string(g) +
                       "," + std::to_string(b) + "]");
}


#endif //EXO3_PIXEL_H
