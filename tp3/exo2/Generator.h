//
// Created by mc on 11/09/2020.
//

#ifndef EXO2_GENERATOR_H
#define EXO2_GENERATOR_H

class Generator {

public:
    Generator(int value);

    int operator()();

private:
    int value;
    int multiple;
};

Generator::Generator(int value) {
    this->value = value;
    multiple = 0;
}

int Generator::operator()() {
    multiple++;
    return multiple*value;
}

#endif //EXO2_GENERATOR_H
