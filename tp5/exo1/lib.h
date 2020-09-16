//
// Created by victor SANDRE.
//

#ifndef EXO1_LIB_H
#define EXO1_LIB_H

template <typename T>
void mySwap(T& t1, T& t2) {
    T tTmp(t1);
    t1 = t2;
    t2 = tTmp;
}

template <typename T>
const T& myMin(const T& t1, const T& t2) {
    if (t1 <= t2)
        return t1;
    else
        return t2;
}

template <>
const std::string & myMin<std::string>(const std::string& a, const std::string& b) {
    if(a.size() <= b.size())
        return a;
    else
        return b;
}

// Pour les chaines de caractères, on peut proposer une surcharge spécifique de min
// const char *  min(const char * a,const char * b)
// Elle convient tout à fait mais ce n'est pas une spécialisation du template ci-dessus
// qui prend des références

template <>
const char * const & myMin<char const *>(const char * const & a,const char * const & b)
{
    std::cout<<"specialisation pour const char *"<<std::endl;
    int i=0;
    while(a[i]==b[i])
    {
        if(a[i]=='\0')
            return a;
        else i++;
    }
    return (a[i]<b[i]?a:b);
}

template <>
char * const & myMin<char *>(char * const & a,char * const & b)
{
    std::cout<<"Specialisation pour char *"<<std::endl;
    int i=0;
    while(a[i]==b[i])
    {
        if(a[i]=='\0')
            return a;
        else i++;
    }
    return (a[i]<b[i]?a:b);
}

//--------------------------------------------------------------------
// Un autre template pour les tableaux statiques de tailles différentes
// Il ne s'agit pas d'une spécialisation mais d'une surcharge du premier
// template général

template <int I, int J>
const char * myMin(const char (&a)[I],const char (&b)[J])
{
    std::cout<<"Un autre template pour const char [I] et const char [J]"<<std::endl;
    int i=0;
    while(a[i]==b[i])
    {
        if(a[i]=='\0')
            return a;
        else i++;
    }
    return (a[i]<b[i]?a:b);
}

// Un autre template pour les tableaux statiques de même taille
// La spécialisation du template précédent ne passe pas.
template <int I>
const char * myMin(const char (&a)[I],const char (&b)[I])
{
    std::cout<<"Un autre template pour const char [I]"<<std::endl;
    int i=0;
    while(a[i]==b[i])
    {
        if(a[i]=='\0')
            return a;
        else i++;
    }
    return (a[i]<b[i]?a:b);
}
#endif //EXO1_LIB_H
