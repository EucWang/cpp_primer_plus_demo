//16.6 fow1.cpp auto_ptr is a poor choice
//  错误的使用auto_ptr会导致问题， 同一个指针不能传递给2个auto_ptr对象，否则会导致错误，这也是auto_ptr不推荐使用的原因
// the difference between auto_ptr , unique_ptr shared_ptr

#include <iostream>
#include <memory>
#include <string>

#include "smrtptrs.h"

using namespace std;

int main_fowl(){

    auto_ptr<string> films[5] =    {
        auto_ptr<string>(new string("Fowl Balls")),
        auto_ptr<string>(new string("Duck Walks")),
        auto_ptr<string>(new string("Chicken Runs")),

        auto_ptr<string>(new string("Turkey Errors")),
        auto_ptr<string>(new string("Goose Eggs")) };

    auto_ptr<string> pwin;
    pwin = films[2];// 这里将所有权移交给了pwin 这个智能指针，所以在使用film[2]时，不能正确访问

    cout << "The nominees for best avian baseball film are\n";
    for(int i=0; i<5; i++) {
        if(films[i].get() != nullptr) {   //这里判断下，则可以继续运行程序
            cout << *films[i] << endl;
        } else {
            cout << "~*!@#* index " << i << " is nullptr. ~*!@#*" << endl;
        }
    }
    cout << "\nthe result is: \n";
    cout << "The winner is " << *pwin << "!\n";
    cin.get();
    return 0;
}