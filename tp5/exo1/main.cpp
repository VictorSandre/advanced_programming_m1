#include <iostream>
#include "lib.h"

int main() {
    std::cout << "Test swap 4,5" << std::endl;
    int a = 4;
    int b = 5;
    mySwap(a,b);
    std::cout << a << ',' << b << std::endl;

    std::cout << "Test myMin 2,3" << std::endl;
    std::cout << myMin(2,3) << std::endl;

    std::cout << "Test myMin 'tata', 'tot'" << std::endl;
    std::string str("tata");
    std::string str2("tat");
    std::cout << myMin(str,str2) << std::endl;


    const char * cc="mumu";
    const char * dd="ma";
    std::cout << myMin(cc,dd) <<std::endl;
    char ee[5]="toto";
    char ff[5]="ta"; //tableau de même taille que le précédent
    std::cout << myMin(ee,ff) <<std::endl;
    std::cout << myMin("zut",ff) <<std::endl;
    return 0;
}
