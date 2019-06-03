#include <iostream>

/**
 * 指针成员 和 拷贝构造
 * 如果类成员包含 指针成员，则要小心编写，防止内存泄漏
 */ 

using namespace std;

//自定义的复制构造函数
// class HasPtrMem{
//     int *d;
// public:
//     HasPtrMem(): d(new int(0)){}  //构造函数， 从堆中分配内存，

//     // 复制构造函数， 从堆中分配内存，然后用 *h.d初始化
//     // 在没有声明复制构造函数时，编译器会自动为类创建一个浅复制的默认复制构造函数。
//     // 浅复制 的问题 就在于如果碰到 指针类型的变量， 复制的只是地址，
//     // 在执行析构函数时，原始类会释放指针地址空间， 同时新的类对象再对该地址进行释放，则会导致程序异常
//     HasPtrMem(const HasPtrMem & h) : d(new int(*h.d)){}
//     ~HasPtrMem(){delete d;}  //析构函数

//     void setValue(int val) {*d = val;}
//     int getValue(){return *d;}
// };

class HasPtrMem{
public:
    int * d;
    static int n_cstr;
    static int n_dstr;
    static int n_cptr;
    static int n_mvtr;

    HasPtrMem():d(new int(0)){
        cout << "Construct: " << ++ n_cstr << endl;
    }

    HasPtrMem(const HasPtrMem & h) :  //复制构造函数
        d(new int(* h.d)) {
        cout << "Copy Construct: " << ++n_cptr << endl;
    }

    HasPtrMem(HasPtrMem && h):d(h.d){  //移动构造函数， 指针类型直接复制，
        h.d = nullptr;  //将原始对象中的指针置空
        cout << "Move Construct: " << ++n_mvtr << endl;
    }

    ~HasPtrMem(){
        cout << "Destruct: " << ++n_dstr << endl;
    }
};

int HasPtrMem::n_cptr = 0;
int HasPtrMem::n_dstr = 0;
int HasPtrMem::n_cstr = 0;
int HasPtrMem::n_mvtr = 0;

/**
 * 返回一个对象， 这个时候，其实会默认在函数外部生成一个新的对象，
 * 然后将函数内部的临时对象 复制给新的对象， 通过 复制构造函数,
 * 但是 编译器 通常会对其 进行优化， 这个不一定看得到
 */ 
HasPtrMem getTemp(){
    HasPtrMem h;
    cout << "Resouce from " <<  __func__  << "(): " 
        << hex << h.d  << endl;
    return h;
}

struct Copyable {
    Copyable(){}

    Copyable(const Copyable &o) {
        cout << "Copied" << endl; //编译器优化，所以这里不会调用
    }
};

Copyable returnRvalue(){return Copyable();}

void accpetVal(Copyable){}

void acceptRef(const Copyable &){}

void testp3_3(){
    cout << "testp3_3()" << endl;

    // int b = 123;

    // HasPtrMem a;
    // // a.d = &b;
    // a.setValue(b);
    // cout << "a.d is " << a.getValue() << endl;

    // HasPtrMem h(a);

    // cout << "h.d is " << h.getValue() << endl;

    // HasPtrMem a = getTemp();
    // *a.d = 123;
    // cout << "a.d is " <<  * a.d << endl;

    // cout << "Resource from " << __func__ << ": " << hex 
    //     << a.d << endl;

    cout << "Pass by value: "<< endl;
    
    accpetVal(returnRvalue());
    
    cout << "Pass by references: " << endl;

    acceptRef(returnRvalue());

    cout << "testp3_3() done" << endl;
}