#include <iostream>
using namespace std;

struct Mem{
    Mem() {cout << "Mem default, num : " << num << endl;}
    Mem(int i) : num(i) {cout << "Mem, num : " << num << endl;}
    int num = 2;
};

class Group {
    public:
        Group() {cout << "Group default : val : " << val << endl;}
        Group(int i) : val('G'), a(i) {cout << "Group. val : " << val << endl;}
        void numA() {cout << "Number of A ; " << a.num << endl;}
        void numB() {cout << "Number of B :  "<< b.num << endl;}
    private:
        char val{'g'};  //使用{}初始化非静态成员
        Mem a;
        Mem b{19};   //使用{}初始化非静态成员
};

/**
 * 在类声明中对非静态成员变量进行就地初始化
 * 和在构造函数中用初始化列表初始化都可以使用
 * 
 * 
 * 而对于非常量的静态成员变量，
 * C++11 和C++98 都需要到头文件之外去定义它，
 * 这会保证编译时，类静态成员的定义最后只存在于一个目标文件中
 */ 
int testp2_16(){

    Mem member;
    Group group;

    group.numA();
    group.numB();

    Group group2(7);
    group2.numA();
    group2.numB();

    return 0;
}