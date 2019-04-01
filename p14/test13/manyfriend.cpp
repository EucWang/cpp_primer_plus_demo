#include <iostream>
using std::cout;
using std::endl;

/**
 * 模板类的非约束模板友元函数
 * 
 * 通过在类内部声明模板，可以创建非约束友元函数。
 * 即每个函数具体化都是每个类具体化的友元
 * ⚠️：对于非约束友元， 友元模板类型参数与模板类型参数是不同的
 * 
 */ 

template <typename T>
class ManyFriend {
    private:
        T item;
    public:
        ManyFriend(const T & i) : item(i) {}
        template <typename C, typename D> friend void show2(C & , D & );
};

/**
 * 在类外 定义 友元函数的实现
 */ 
template <typename C, typename D>
void show2(C & c, D & d) {
    cout << c.item << ", " << d.item << endl;
}

int main() {
    ManyFriend<int> hfi1(10);
    ManyFriend<int> hfi2(20);
    ManyFriend<double> hfdb(10.5);

    cout << "hfi1, hfi2 : ";
    show2(hfi1, hfi2);

    cout << "hfdb, hfi2 : ";
    show2(hfdb, hfi2);

    return 0;
}
