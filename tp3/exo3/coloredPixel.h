//
// Created by victor SANDRE.
//

#ifndef EXO3_COLOREDPIXEL_H
#define EXO3_COLOREDPIXEL_H

#include "pixel.h"

class ColoredPixel : public Pixel {

public:
    std::string value() const override {
        return Pixel::value();
    }
};

#endif //EXO3_COLOREDPIXEL_H
