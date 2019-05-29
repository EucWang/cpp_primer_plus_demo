#include <iostream>
#include <cmath>
#include "error.h"
#include "bad_mean.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

double hmean4(double a, double b);
double gmean(double a, double b);

int main_error4(){

    double x, y, z;

    cout << "Enter two number: ";
    while (cin >> x >> y) {
        try{
            z = hmean4(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;

            z = gmean(x, y);
            cout << "Geometric mean of " << x << " and " << y
                << " is " << z << endl;

                cout << "Enter next set of numbers <q to quit>: ";
        }catch(BadHMean & bhm){
            bhm.msg();
            cout << "Try again.\n";
            continue;
        }catch(BadGMean & bgm) {
            cout << bgm.msg();
            cout << "values used: "<< bgm.getV1() << ", "
                << bgm.getV2() << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye.\n";
    return 0;
}
double hmean4(double a, double b) {
    if(a==-b){
        throw BadHMean(a, b);
    }
    return 2.0 * a * b / (a + b);
}

double gmean(double a, double b) {

    if(a < 0 || b < 0) {
        throw BadGMean(a, b);
    }
    return std::sqrt(a * b);
}
