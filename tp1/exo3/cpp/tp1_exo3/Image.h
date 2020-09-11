//
// Created by mc on 07/09/2020.
//

#ifndef TP1_IMAGE_H
#define TP1_IMAGE_H

#include "Pixel.hpp"

class Image {
public:
    Image(int height, int width);

    Pixel getPixel(int poxX, int posY) const; //Première façon de faire le mutateur/accesseur.
    void setPixel(int posX, int posY, Pixel& pixel);

    Pixel& operator[] (int i);// Autre façon de faire.
    Pixel operator[] (int i) const;

    int getHeight() const;
    int getWidth() const;

    void setHeight(int height);
    void setWidth(int width);

    ~Image(); // Destructeur.

private:
    int height;
    int width;
    Pixel ** pixels;

    void initAllPixels();
};

Image::Image(int height, int width) {
    this->height = height;
    this->width = width;
    initAllPixels();
}

/**
 * Allocation et initialisation du tableau de pixels.
 */
void Image::initAllPixels() {
    //Allocation d'un tableau 2D (donc un tableau de tableaux).
    pixels = new Pixel*[height]; // Allocation des lignes.

    //Allocation des colones.
    for (int i = 0; i < height; ++i) {
        pixels[i] = new Pixel[width];
        // Initialisation de chaque pixel.
        for (int j = 0; j < width; ++j) {
            Pixel pixel;
            pixels[i][j] = pixel;
        }
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


#endif //TP1_IMAGE_H
