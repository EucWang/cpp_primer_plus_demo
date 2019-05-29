#ifndef HAS_FRIEND_H_
#define HAS_FRIEND_H_

#include <iostream>
using std::cout;
using std::endl;

/**
 *  模板类的约束友元函数
 *  ⚠️：使友元函数本身成为模板
 *  1. 首先，在类定义前声明友元函数同名的模板函数
 *  2. 然后， 在类定义中依然提供友元函数声明，并声明为模板形式
 *  3. 最后，为友元约束模板函数提供定义， 注意这里的函数不能直接访问类的私有成员变量了
 * 
 * ⚠️： 模板类中的静态变量，针对类型实例化之后，每一种类型都会有一份静态变量
 */
template <typename T> void counts();
template <typename T> void report(T &);

template <typename TT>
class HasFriendT{
    private:
        TT item;
        static int ct;
    public:
        HasFriendT(const TT & i) : item(i) {ct++;}
        ~HasFriendT() {ct--;};

        TT getItem(){return item;}

        friend void counts<TT>();
        friend void report<>(HasFriendT<TT> &);
};

template <typename TT>
int HasFriendT<TT>::ct = 0;


template<typename TT>
void counts() {
    cout << "template size : " << sizeof(HasFriendT<TT>) << "; ";
    cout << "template counts():" << HasFriendT<TT>::ct << endl;
};

template<typename TT>
void report(HasFriendT<TT> & hf) {
    cout << hf.getItem() << endl;
};

#endif