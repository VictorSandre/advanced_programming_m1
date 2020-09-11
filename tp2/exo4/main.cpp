#include <iostream>
#include "String.h"

int main() {
    // Test constructeur vide.
    std::cout << "test constructeur vide : " << std::endl;
    String str;
    std::cout << "longueur String : " << str.getLength() << "; String : " << str << std::endl;

    // Test constructeur argument.
    std::cout << "test constructeur avec une chaine : " << std::endl;
    String str2("toto");
    std::cout << "longueur String : " << str2.getLength() << "; String : " << str2 << std::endl;

    // Test constructeur par copie.
    std::cout << "test constructeur par copie : " << std::endl;
    String strx(str2);
    std::cout << "longueur String : " << strx.getLength() << "; String : " << strx << std::endl;

    // Test constructeur avec un char.
    std::cout << "test constructeur avec un \'char\' : " << std::endl;
    char cha = 't';
    String str3(cha);
    std::cout << "longueur String : " << str3.getLength() << "; String : " << str3 << std::endl;

    // Test du cast d'une string en char*
    std::cout << "test du cast d'une str en \'char*\' : " << std::endl;
    char * cstr = new char[3];
    String str4("to");
    // Utilisation d'une fonction de la stl manipulant les char pour voir si le cast est bon.
    std::strcpy(cstr, str4.cstr());
    std::cout << cstr << std::endl;
    delete[] cstr;

    // Test operateur == .
    std::cout << "test opérateur \'==\' : " << std::endl;
    String str5("aaab");
    String str6("aaab");
    String str7;
    std::cout << "aaab == aaab : " << (str5==str6) << std::endl;
    std::cout << R"('' == '' : )" << (str7==str) << std::endl;

    // Test opérateur != .
    std::cout << "test opérateur \'!=\' : " << std::endl;
    std::cout << "aaab != \'\' : " << (str6!=str) << std::endl;

    // Test opérateur < .
    String str8("aaba");
    std::cout << "test opérateur \'<\' : " << std::endl;
    std::cout << "aaba < aaab : " << (str8 < str6) << std::endl;

    // Opérateurs >; <=; >= sont "hérités" de l'opérateur < donc normalement tout est bon.

    // Test opérateur+ .
    String str9(str8+str6);
    std::cout << "test opérateur \'+\' : " << std::endl;
    std::cout << "longueur String : " << str9.getLength() << "; String : " << str9 << std::endl;

    // Test opérateur [].
    std::cout << "test opérateur \'[ ]\' : " << std::endl << " \'aabaaaab\'[0] : " << str9[0] << std::endl;
    String str10("titi");
    std::cout << "longueur String : " << str10.getLength() << "; String : " << str10 << std::endl
              << "modification de str10[0] par j : " ;
    str10[0] = 'j';
    std::cout << "longueur String : " << str10.getLength() << "; String : " << str10 << std::endl;

    // Test substr().
    std::cout << "test fonction substr : " << std::endl;
    String str11("aaabcd");
    std::cout << "substring (aaabcd, start:2, end:4) : " << str11.subString(2,4) << std::endl;


    return 0;
}
