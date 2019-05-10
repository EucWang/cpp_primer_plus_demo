#include <iostream>


/**
 * 17.2 defaults.cpp
 * cout default formats
 * 
 * 
 * 
 */ 
int main_defaults(){

    using namespace std;

    cout << "12345678901234567890\n";
    char ch = 'K';
    int t = 273;
    cout << "ch = " << ch << ":\n";
    cout << "t = "  << t << ":\n";
    cout << "-t = "  << -t << ":\n";


    double f1 = 1.200;
    cout << "f1 = "  << f1 << ":\n";
    cout << "f1` = "  << (f1 + 1.0/9.0) << ":\n";

    double f2 = 1.67e2;
    cout << "f2 = "  << f2 << ":\n";
    f2 += 1.0/9.0;
    cout << "f2` = "  << f2 <<":\n";
    cout << "f2`` = "  << (f2 * 1.0e4) << ":\n";

    double f3 = 2.3e-4;
    cout << "f3 = "  << f3 << ":\n";
    cout << "f3` = "  << f3/10 << ":\n";

    return 0;   
}