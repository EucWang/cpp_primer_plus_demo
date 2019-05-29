#include <iostream>
#include <cmath>
#include "bad_mean3.h"
#include "error7.h"

using std::cin;
using std::cout;
using std::string;
using std::endl;

double hmean7(double a, double b);
double gmean7(double a, double b);

int main_error7(){

    double x, y, z;

    cout << "Enter two number: ";
    while (cin >> x >> y) {
        try{
            z = hmean7(x, y);
            cout << "Harmonic mean of " << x << " and " << y
                << " is " << z << endl;

            z = gmean7(x, y);
            cout << "Geometric mean of " << x << " and " << y
                << " is " << z << endl;

                cout << "Enter next set of numbers <q to quit>: ";
        }catch(BadHMean3 & bhm){
            // bhm.msg();
            cout << bhm.what() << " and arguemnt is " << bhm.getV1() << " , " << bhm.getV2() << endl;
            cout << "Try again.\n";
            continue;
        }catch(BadGMean3 & bgm) {
            cout << bgm.what() << " and arguemnt is " << bgm.getV1() << " , " << bgm.getV2() << endl;
            // cout << "values used: "<< bgm.getV1() << ", "
            //     << bgm.getV2() << endl;
            cout << "Sorry, you don't get to play any more.\n";
            break;
        }
    }
    cout << "Bye.\n";
    return 0;
}
double hmean7(double a, double b) {
    if(a==-b){
        // throw BadHMean2(a, b);
        throw BadHMean3("hmean6() function call fail, becuause argument a == b", a, b);
    }
    return 2.0 * a * b / (a + b);
}

double gmean7(double a, double b) {

    if(a < 0 || b < 0) {
        throw BadGMean3("gmean6() function call fail, becuause argument a < 0  || b < 0", a, b);
    }
    return std::sqrt(a * b);
}
