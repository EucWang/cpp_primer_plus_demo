#include <iostream>
#include <type_traits>
#include "test3.h"

/**
 * template <typename T>
 * struct std::is_standard_layout;
 * 通过is_standard_layout模板类的成员value，可以查看范型类型是否是标准布局属性
 * 
 * 需要引入 头文件  <type_traits>
 * 
 */ 

using namespace std;

struct SLayout1 {};

struct SLayout2 {
private:
    int x;
    int y;
};

struct SLayout3 : SLayout1 {
int x;
int y;
void f();
};

struct SLayout4 : SLayout1{
int x;
SLayout1 y;
};

struct SLayout5 : SLayout1, SLayout3 {};

struct SLayout6 {
static int y;  //对静态成员没有要求
};

struct SLayout7 : SLayout6{
    int x;   //继承结构中，只有一层有非静态成员
};

struct NonSLayout1 : SLayout1 {
SLayout1 x;
int i;
};

struct NonSLayout2 : SLayout2 {
int z; //继承结构中，只能有一层有非静态成员 ，这里2层都有非静态成员
};

struct NonSLayout3 : NonSLayout2{};

struct NonSLayout4 {
private:
    int y;
public:
    int x;
};

void testp3_13(){
    cout << __func__ << "() called.\n";

    cout << boolalpha;
    cout << "SLayout1 is standard layout :\t" << is_standard_layout<SLayout1>::value << endl;
    cout << "SLayout2 is standard layout :\t"  << is_standard_layout<SLayout2>::value << endl;
    cout << "SLayout3 is standard layout :\t"  << is_standard_layout<SLayout3>::value << endl;

    cout << "SLayout4 is standard layout :\t"  << is_standard_layout<SLayout4>::value << endl;
    cout << "SLayout5 is standard layout :\t"  << is_standard_layout<SLayout5>::value << endl;
    cout << "SLayout6 is standard layout :\t"  << is_standard_layout<SLayout6>::value << endl;
    
    cout << "SLayout7 is standard layout :\t"  << is_standard_layout<SLayout7>::value << endl;
    
    cout << "NonSLayout1 is standard layout :\t"  << is_standard_layout<NonSLayout1>::value << endl;
    cout << "NonSLayout2 is standard layout :\t"  << is_standard_layout<NonSLayout2>::value << endl;
    cout << "NonSLayout3 is standard layout :\t"  << is_standard_layout<NonSLayout3>::value << endl;

    cout << "NonSLayout4 is standard layout :\t"  << is_standard_layout<NonSLayout4>::value << endl;



    cout << __func__ << "() called. done. \n";

}