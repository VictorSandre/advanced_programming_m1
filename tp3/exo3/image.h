//
// Created by victor SANDRE.
//

#ifndef EXO3_IMAGE_H
#define EXO3_IMAGE_H

#include <ostream>
#include "pixel.h"

class Image {
public:
    Image(int height, int width, bool isGrey);

    Image(int height, int width);

    Pixel getPixel(int poxX, int posY) const; //Première façon de faire le mutateur/accesseur.
    void setPixel(int posX, int posY, Pixel& pixel);

    Pixel& operator[] (int i);// Autre façon de faire.
    Pixel operator[] (int i) const;

    int getHeight() const;
    int getWidth() const;

    void setHeight(int height);
    void setWidth(int width);

    friend std::ostream &operator<<(std::ostream &os, const Image &image);

    ~Image(); // Destructeur.

private:
    int height;
    int width;
    Pixel ** pixels;

    void initAllGreyPixels();
    void initAllColoredPixels();
};

Image::Image(int height, int width, bool isGrey) : height(height), width(width){
    if (isGrey)
        initAllGreyPixels();//TODO demander au prof: ici je fais un downcast et non un upcast non ? comment faire du coup ?
    else
        initAllColoredPixels();
}

Image::Image(int height, int width) : Image(height, width, true) {

}

void Image::initAllGreyPixels() {
    //Allocation d'un tableau 2D (donc un tableau de tableaux).
    pixels = (Pixel**) new GreyPixel*[height]; // Allocation des lignes.

    //Allocation des colones.
    for (int row = 0; row < height; ++row) {
        pixels[row] = (Pixel*) new GreyPixel[width];
    }
}

void Image::initAllColoredPixels() {
    //Allocation d'un tableau 2D (donc un tableau de tableaux).
    pixels = (Pixel**) new ColoredPixel*[height]; // Allocation des lignes.

    //Allocation des colones.
    for (int row = 0; row < height; ++row) {
        pixels[row] = (Pixel*) new ColoredPixel[width];
    }
}

Pixel Image::getPixel(int posX, int posY) const {
    return pixels[posY][posX];
}

void Image::setPixel(int posX, int posY, Pixel &pixel) {
    pixels[posY][posX] = pixel;
}

int Image::getHeight() const {
    return height;
}

int Image::getWidth() const {
    return width;
}

void Image::setHeight(int height) {
    Image::height = height;
}

void Image::setWidth(int width) {
    Image::width = width;
}

Pixel &Image::operator[](int i) {
    // Si l'index est incorrect on envoie une erreur.
    if (i < 0 || i > width*height)
        throw std::out_of_range("index incorrect");

    // Sinon on cherche le pixel pour le renvoyer.
    for (int h = 0; h < height; ++h) {
        for (int c = 0; c < width; ++c) {
            // Ici on fait un cast d'un indice de tableau 1D en indice de tableau 2D.
            if (h*width+c == i)
                return pixels[h][c];
        }
    }
}

Pixel Image::operator[](int i) const {
    // Si l'index est incorrect on envoie une erreur.
    if (i < 0 || i > width*height)
        throw std::out_of_range("index incorrect");

    // Sinon on cherche le pixel.
    for (int h = 0; h < height; ++h) {
        for (int c = 0; c < width; ++c) {
            // Ici on fait un cast d'un indice de tableau 1D en indice de tableau 2D.
            if (h*width+c == i)
                return pixels[h][c];
        }
    }
}

Image::~Image() {
    // On supprime en premier les colonnes.
    for (int i = 0; i < height; ++i) {
        delete [] pixels[i];
    }
    // On supprime les lignes.
    delete [] pixels;
}

std::ostream &operator<<(std::ostream &os, const Image &image) {
    for (int row = 0; row < image.width; ++row) {
        for (int column = 0; column < image.height; ++column) {
            os << image.pixels[column][row];
        }
        os << std::endl;
    }
    return os;
}

#endif //EXO3_IMAGE_H
