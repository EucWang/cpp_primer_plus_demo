#include <iostream>
#include <string>
#include <cmath>
#include "bad_mean.h"
#include "error.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

class Demo{
    private:
        string word;
    public:
        Demo(const string & str){
            word = str;
            cout << "Demo " << word << " created" << endl;
        }

        ~Demo(){
            cout << "Demo " << word << " destroyed" << endl;
        }

        void show() const {
            cout << "Demo " << word << " lives!" << endl;
        }
};

double hmean5(double a, double b);
double gmean5(double a, double b);
double means5(double a, double b);

int main_error5(){
    double x, y, z;

    {
        Demo d1("found in block in main_error5()");
        cout << "Enter two numbers: ";
        while(cin >> x >> y) {
            try {
                z = means5(x, y);
                cout << "The mean mean of " << x << " and " << y
                    << " is " << z << endl;
                cout << "Enter next pair: ";
            }catch(BadHMean & bhm) {
                bhm.msg();
                cout << "Try again.\n";
                continue;
            }catch(BadGMean & bgm) {
                cout << bgm.msg();
                cout << "Values used: " << bgm.getV1() << ", "
                        << bgm.getV2() << endl;
                break;
            }
        }
        d1.show();
    }

    cout << "Bye." << endl;
    cin.get();
    cin.get();
    return 0;
}

double hmean5(double a, double b){
    if(a == -b) {
        throw BadHMean(a, b);
    }
    return 2.0 * a * b /(a + b);
}


double gmean5(double a, double b) {
    if(a < 0 || b < 0) {
        throw BadGMean(a, b);
    }
    return sqrt(a * b);
}

double means5(double a, double b) {
    double am, hm, gm;
    Demo d2("found in means()");
    
    am = (a + b)/2.0;

    try{
        hm = hmean5(a, b);
        gm = gmean5(a, b);
    }catch(BadHMean & bhm) {
        bhm.msg();
        cout << "Caught in means()\n";
        throw;
    }

    d2.show();
    return (am + hm + gm)/3.0;
}