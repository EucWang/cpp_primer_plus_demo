#include <iostream>
#include <cmath>
#include "bad_mean2.h"
#include "error6.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

double hmean6(double a, double b);
double gmean6(double a, double b);

int main_error6(){

    double x, y, z;

    cout << "Enter two number: ";
    while (cin >> x >> y) {
        try{
            z = hmean6(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;

            z = gmean6(x, y);
            cout << "Geometric mean of " << x << " and " << y
                << " is " << z << endl;

                cout << "Enter next set of numbers <q to quit>: ";
        }catch(BadHMean2 & bhm){
            // bhm.msg();
            cout << bhm.what();
            cout << "Try again.\n";
            continue;
        }catch(BadGMean2 & bgm) {
            cout << bgm.what();
            // cout << "values used: "<< bgm.getV1() << ", "
            //     << bgm.getV2() << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye.\n";
    return 0;
}
double hmean6(double a, double b) {
    if(a==-b){
        // throw BadHMean2(a, b);
        throw BadHMean2("hmean6() function call fail, becuause argument a == b");
    }
    return 2.0 * a * b / (a + b);
}

double gmean6(double a, double b) {

    if(a < 0 || b < 0) {
        throw BadGMean2("gmean6() function call fail, becuause argument a < 0  || b < 0");
    }
    return std::sqrt(a * b);
}
