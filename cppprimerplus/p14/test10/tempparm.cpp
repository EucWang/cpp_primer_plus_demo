#include <iostream>
#include "../test5/stacktp.h"

/**
 * 模板包含本身就是模板的参数，这种参数就是模板新增的特性，用于实现STL
 * ⚠️：注意如下的格式
 */ 
// template <template <typename T> class Thing>

/**
 * ⚠️：可以混合使用模板参数和常规参数，
 * 这里 T表示一种模板类型， 而类型参数U和V表示非模板类型
 */ 
template <template <typename T> class Thing, typename U, typename V >
class Crab {
    private:
        Thing<U> s1;
        Thing<V> s2;
        // Thing<int> s1;
        // Thing<double> s2;
    public:
        Crab(){};

        bool push(int a, double x){return s1.push(a) && s2.push(x); };
        bool pop(int & a, double & x) { return s1.pop(a) && s2.pop(x); };
};

using std::cout;
using std::cin;
using std::endl;

int main118() {

    // Crab<Stack> nebula;
    Crab<Stack, int, double> nebula;
    int ni;
    double nb;

    cout << "Enter int double pairs, such as 4 3.5 (0 0 to end):\n";
    while(cin >> ni >> nb && ni > 0 && nb > 0) {
        if(!nebula.push(ni, nb)) {
            break;
        }
    }
    while(nebula.pop(ni, nb)) {
        cout << ni << ", " << nb << endl;
    }

    cout << "Done.\n";
    return 0;
}