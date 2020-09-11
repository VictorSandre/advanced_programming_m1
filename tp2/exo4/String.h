//
// Created by victor sandre.
//

#ifndef EXO4_STRING_H
#define EXO4_STRING_H

#include <cstring>
#include <ostream>

class String {
public:
    String();
    explicit String(const char *chars);
    explicit String(char character);
    String(const String& string);

    // La classe est protégé par le const. On ne pourra pas modifier la valeur retournée par la fonction.
    const char * cstr() const;

    int getLength() const;

    friend std::ostream &operator<<(std::ostream &os, const String &string);

    // Opérations de comparaison.
    bool operator==(const String &rhs) const;
    bool operator!=(const String &rhs) const;
    bool operator<(const String &rhs) const;
    bool operator>(const String &rhs) const;
    bool operator<=(const String &rhs) const;
    bool operator>=(const String &rhs) const;

    // Opéraion de concaténation.
    String operator+(const String& rhs);

    // Opérateurs d'accès à un élément.
    const char& operator[](int index) const; // En lecture seulement.
    char& operator[](int index); // En lecture et en écriture.

    // Fabrication d'une sous chaine
    String subString (int start, int end) const;

    ~String();

private:
    int length;
    char* chars;
};

String::String() {
    length = 0;
    chars = new char[1];
    chars[0] = '\0';
}

String::String(const char* chars) {
    if (chars != nullptr) {
        length = std::strlen(chars);
        this->chars = new char[length+1];
        std::strcpy(this->chars, chars);
        std::strcat(this->chars, "\0");
    }
    else {
        length = 0;
        this->chars = new char[1];
        this->chars[0] = '\0';
    }
}

String::String(char cha) {
    length = 1;
    chars = new char[2];
    chars[0] = cha;
    chars[1] = '\0';
}

String::String(const String &string) {
    length = string.length;
    chars = new char[length+1];
    std::strcpy(chars, string.chars);
    std::strcat(chars, "\0");
}

const char* String::cstr() const{
    return chars;
}

int String::getLength() const {
        return length;
}

std::ostream &operator<<(std::ostream &os, const String &string) {
    return os << string.chars;
}

bool String::operator<(const String &rhs) const {
    if (std::strcmp(rhs.chars, chars) < 0) // Comparaison sur ordre lexicographique
        return true;
    else
        return false;
}

bool String::operator>(const String &rhs) const {
    return rhs < *this;
}

bool String::operator<=(const String &rhs) const {
    return !(rhs < *this);
}

bool String::operator>=(const String &rhs) const {
    return !(*this < rhs);
}

bool String::operator==(const String &rhs) const {
    return length == rhs.length &&
           (std::strcmp(rhs.chars,chars )== 0);
}

bool String::operator!=(const String &rhs) const {
    return !(rhs == *this);
}

String String::operator+(const String & rhs) {
    if (rhs.chars != nullptr) {
        // Calcul de la nouvelle longueur.
        int totalLength = length + rhs.length;
        // Création du tableau dynamique qui recevra la String concaténée.
        char* tmpChars = new char[totalLength+1];
        // Copie des Strings a concaténer.
        std::strcpy(tmpChars, chars);
        std::strcat(tmpChars, rhs.chars);
        std::strcat(tmpChars, "\0");
        // Désallocation de l'ancienne String pour éviter une fuite mémoire.
        delete [] this->chars;
        // Changement du pointeur de notre String pour pointer sur la String concatenée.
        chars = tmpChars;
        length = totalLength;
    }
    return *this;
}

const char &String::operator[](int index) const {
    return chars[index];
}

char &String::operator[](int index) {
    return chars[index];
}

//TODO voir avec le prof la fuite memoire sur le conditional jump
String String::subString(int start, int end) const {
    if (start < 0 && end >= length)
        throw std::out_of_range("index de début ou de fin non correct");

    int newStringSize = end - start + 1;
    char * tmpChars = new char[newStringSize+1]; // Le + 1 pour le "\0".
    for (int i = start; i < end+1; ++i) {
        tmpChars[i-start] = chars[i];
    }
    std::strcat(tmpChars, "\0");

    String toReturn(tmpChars);
    delete [] tmpChars;
    return toReturn;

}

String::~String() {
    delete [] chars;
}

#endif //EXO4_STRING_H