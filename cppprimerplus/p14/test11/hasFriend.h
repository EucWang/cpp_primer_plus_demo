#ifndef HAS_FRIEND_H_
#define HAS_FRIEND_H_

#include <iostream>
using namespace std;

template <typename T>
class HasFriend {
    private:
        T item;
        static int ct;
    public:
        HasFriend(const T & i) : item(i) { ct++; };
        ~HasFriend() {ct--; };

        friend void counts();
        friend void reports(HasFriend<T> &);
};

template <typename T>
int HasFriend<T>::ct = 0;

/**
 * non template friend to all HasFriend<T> classes
 */ 
void counts() {
    cout << "int count : " << HasFriend<int>::ct << ": ";
    cout << "double count : " << HasFriend<double>::ct << endl;
};


/**
 * 友元函数本身不是模板函数， 而只是使用一个模板作为参数
 * 意味着必须为使用的友元定义显示具体化。
 */ 
void reports(HasFriend<int> & hf) {
    cout << "HasFriend<int>: " << hf.item << endl;
};

void reports(HasFriend<double> & hf) {
    cout << "HasFriend<double>: " << hf.item << endl;
};

#endif