#include <iostream>
#include "test2.h"

class Poly;

typedef Poly P;

class LiLei{
    friend class Poly; //都可以编译
};

class Jim {
    friend Poly; //C++98不能通过编译 因为没有写成 friend class
};

class HanMeiMei{
    friend P;//C++98不能通过编译，因为没有写成 friend class
};

/**
 * 在模板中定义友元
 */ 
template <typename T> class People2{
    friend T;
};

int testp2_19(){

    Poly p();

    LiLei lilei;

    Jim j;

    HanMeiMei hmm;

    People2<HanMeiMei> p2;

    return 0;
}