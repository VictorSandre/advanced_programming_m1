#include <iostream>

#include "pixel.h"
#include "coloredPixel.h"
#include "greyPixel.h"
#include "image.h"

int main() {
    Pixel* pix;
    ColoredPixel cPix;
    GreyPixel gPix;

    pix = &gPix;
    // Test pour voir si la résolution des liens se fait bien.
    std::cout << "Cast pixelGeneral en gris vaut : " << pix->value() << std::endl;

    Image greyImage(4,3);
    std::cout<< "Test image grise: " <<std::endl;
    std::cout << greyImage << std::endl;

    Image coloredImage(3,3,false);
    std::cout<< "Test image couleur: " <<std::endl;
    std::cout << coloredImage << std::endl;

    return 0;
}
