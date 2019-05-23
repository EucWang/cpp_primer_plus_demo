//
// Created by 王新年 on 2019-05-23.
//

#include <iostream>
#include "somedefs.h"
#include "test5.h"

double dub(double x){return 2.0 * x;}
double square(double x){return x * x;}

/**
 * 18.7
 * callable types and templates
 * @return
 */
int main_callable() {

    using namespace std;

    double y = 1.21;

    cout << " Function pointer dub: \n";
    cout << " " << use_f(y, dub) << endl;

    cout << "Function pointer square : " << endl;
    cout << "  " << use_f(y, square) << endl;

    cout << "Function object Fp : \n";
    cout << "  " << use_f(y, Fp(5.0)) << endl;

    cout << "Function object Fq : \n";
    cout << " "  << use_f(y, Fq(5.0)) << endl;

    cout << "Lambda expression 1 :\n";
    cout << " " << use_f(y, [](double u){return u*u;}) << endl;

    cout << "Lambda expression 2 :\n";
    cout << " " << use_f(y, [](double u){return u+u/2.0;}) << endl;

    return 0;

}