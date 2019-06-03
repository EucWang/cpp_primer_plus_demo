#include <iostream>
#include <utility>
#include "test3.h"
using namespace std;

/**
 * 在C++11中，
 * 复制构造函数/移动构造函数
 * 赋值运算符重载函数必须同时提供，
 * 或者同时不提供，程序才能保证同时具有复制和移动语义。
 * 
 * 
 */ 
class HugeMem {
public:
    int * c;
    int sz;
    HugeMem(int size) : sz(size>0?size:1) {
        c = new int[sz];
    }
    ~HugeMem(){delete [] c;}

    HugeMem(const HugeMem & hm) : sz(hm.sz){  //注意， 复制构造函数入参最好是const的
        c = new int(sz);
        for(int i=0; i<sz; i++){
            c[i] = hm.c[i];
        }
    }

    HugeMem(HugeMem && hm) : sz(hm.sz), c(hm.c) {  //⚠️注意， 移动复制构造函数的入参一定不能是const的，否则会导致右值不能被修改，从而无法实现移动语义
        cout << "called HugeMem's move copy constructor.\n";
        hm.c = nullptr;
    }
};

class Moveable {
public:
    int * i;
    HugeMem h;

    Moveable() : i(new int(3)), h(1024) {}
    ~Moveable(){delete i;}
    Moveable(const Moveable & m) : i(new int(* m.i)), h(m.h) {}
    Moveable(Moveable && m): i(m.i), h(move(m.h)) {
        cout << "call Moveable's move constructor.\n";
        m.i = nullptr;
    }
};

Moveable getTemp34(){
    Moveable tmp = Moveable();
    cout << hex << "Hugemem from " << __func__ << " @" << tmp.h.c << endl;
    return tmp;
}

/////////////////////////////////////////

struct Maythrow{
    Maythrow(){}
    Maythrow(const Maythrow &) {
        cout << "Maythrow copy constructor." << endl;        
    }
    Maythrow(Maythrow &&){
        cout << "Maythrow move constructor." << endl;
    }
};

struct Nothrow{
    Nothrow(){}
    Nothrow(Nothrow &&){
        cout << "Nothrow move constructor." << endl;
    }
    Nothrow(const Nothrow &) {
        cout << "Nothrow copy constructor." << endl;
    }
};

/**
 * 为了保证移动语义的传递
 * 在编写移动构造函数的时候，
 * 应该总是记得使用std::move转换 比如有堆内存， 文件句柄等资源的成员为右值。
 * 
 * 编译器中存在 RVO/NRVO 的优化，
 * 可以在 编译运行时 采用  -fno-elide-constructors 选项 
 * 在 g++/clang++ 中关闭这个优化，
 * 这样才会在代码运行中能看到函数返回的临时变量的右值。
 * 如果不关闭这个选项，复制构造函数/移动构造函数往往都会被省略掉。
 * 
 * ⚠️注意：RVO/NRVO优化并不是对任何情况都有效，自定义移动语义可以解决编译器无法解决的优化问题，
 * 而且是总是有用的。
 * 
 */ 
void testp3_4(){
    cout << __func__ << "() called" << endl;

    Moveable a(getTemp34());  //可以看到打印出的地址是相同的，则表示通过编译器优化默认就是采用移动复制构造函数，虽然没有调用
    cout << hex << "Huge mem from " << __func__
        << " @" << a.h.c << endl;
    // Moveable c(move(a));  //这里强制调用了 std::move() 方法，将左值转换成右值
    cout << * a.i << endl;


    Maythrow m;
    Nothrow n;
    Maythrow mt = move_if_noexcept(m);
    Nothrow nt = move_if_noexcept(n);

    cout << __func__ << "() called done.\n";

}