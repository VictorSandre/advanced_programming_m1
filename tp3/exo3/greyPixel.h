//
// Created by victor SANDRE.
//

#ifndef EXO3_GREYPIXEL_H
#define EXO3_GREYPIXEL_H

#include <ostream>
#include "pixel.h"

class GreyPixel : public Pixel {

public:
    long luminance() const;

    std::string value() const override;

    friend std::ostream &operator<<(std::ostream &os, const GreyPixel &pixel);

};

long GreyPixel::luminance() const {
    return 0.2126 * r + 0.7152 * g + 0.0722 * b;
}

std::string GreyPixel::value() const {
    return std::string("g:" + std::to_string(luminance()));
}

std::ostream &operator<<(std::ostream &os, const GreyPixel &pixel) {
    os << pixel.value();
    return os;
}

#endif //EXO3_GREYPIXEL_H
