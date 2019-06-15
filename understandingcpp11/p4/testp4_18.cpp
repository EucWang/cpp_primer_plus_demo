#include <iostream>
#include <iterator>
#include <vector>
#include <map>
#include "test4.h"

using namespace std;

void testp4_18(){
    cout << __func__ << "() called.\n";

    vector<int> vec;

    typedef decltype(vec.begin()) vectype; //typedef 将  decltype 推导出的类型 定义称新的类型
    for(vectype i = vec.begin(); i < vec.end(); i++) {
        cout << ".." << endl;
    }

    /**
     * decltype(vec)::iterator  这种用法 没有想明白
     */
    for(decltype(vec)::iterator i = vec.begin(); i<vec.end(); i++) {
        cout << "..." << endl;
    }
    cout << __func__ << "() called. done. \n";
}

enum class ANON_E{K1, K2, K3};  // 不能匿名的强类型枚举
ANON_E anon_e;

union {
    decltype(anon_e) key;  //推导出类型作为成员的类型
    char* name;
}anon_u;  //匿名的联合体

struct{
    int d;
    decltype(anon_u) id;   //推导出类型作为成员的类型
}anon_s[100];  //匿名的结构体

void testp4_19(){
    cout << __func__ << "() called.\n" << endl;
    decltype(anon_s) as;
    as[0].id.key = decltype(anon_e)::K1;
}

/**
 * decltype 用于模板中
 * 可以根据输入类型 推导出 输出类型，
 * ⚠️这里的返回结果 结合了 auto 以后函数的后置返回类型
 */
template<typename T1, typename T2>
auto sum3(T1 & t1, T2 & t2) -> decltype(t1 + t2) {
    auto s =  t1 + t2;
    return s;
}

const int ARR_SIZE = 3;
/**
 * 上面的模板函数，如果T1， T2 是数组， 那么不适用了，需要特例化该函数了
 * 操蛋的例子， 这个数组的大小没有指定啊， 
 * ⚠️固定一个值 ARR_SIZE = 3 为数组大小
 */
int * sum3(int a[], int b[]){
    int * c = new int[ARR_SIZE];
    for(int i=0; i<ARR_SIZE; i++) {
        c[i] = a[i] + b[i];
    }
    return c;
}

void testp4_20(){
    cout << __func__ << "() called.\n";
    int a = 3;
    long b = 5;
    float c = 1.0f;
    float d = 2.3f;
    // long e;   //这里已经定义了返回类型了， 虽然 模板函数可以推导出来
    // float f;
    auto e = sum3(a, b);   //这个例子真是💩
    auto f = sum3(c, d);

    cout << " e is " << e << ", and it's typeid().name() is " << typeid(e).name() << endl;
    cout << " f is " << f << ", and it's typeid().name() is " << typeid(f).name() << endl;

    int a1[3] = {1,3,5};
    int b1[3] = {2, 4, 6};
    int * c1 = sum3(a1, b1);
    cout << "c1 is [";
    for(int i=0; i<ARR_SIZE; i++) {
        cout << *(c1+i);
        if(i != ARR_SIZE -1) {
            cout << ",";
        }
    }
    cout << "]\n";

    cout << __func__ << "() called. done.\n";
    delete [] c1;
}


/**
 * decltype 接受表达式作为参数
 * 比如 函数调用的表达式也是可以的
 * 但是只是函数名的表达式是不行的
 */
int hash(char *);

// map<char *, decltype(hash)> dict_key;  //无法通过编译， ⚠️candidate found by name lookup is 'hash'
// map<char *, decltype(hash(nullptr))> dict_key1;  //这个依然不能通过编译， ️⚠️error: reference to 'hash' is ambiguous


/**
 * 
 * 
 * decltype 的类型推导的规则：
 * 1 如果e是一个没有带括号的"标记符表达式"或者类成员访问表达式 ，那么 decltype(e)就是 e所命名的实体的类型。
 *      此外 ，⚠️如果e是一个被重载的函数 ，则会导致编译时错误 。 
 * 2 否则 ，假设e的类型是T ，⚠️如果e是一个将亡值 (xvalue) ，那么 decltype(e)为 T&&
 * 3 否则 ，假设e的类型是T ，️️️⚠️如果e是一个左值 ，则 decltype(e)为 T&   【容易和第一条弄混淆】
 * 4 否则 ，假设e的类型是T ，⚠️则 decltype(e)为 T
 * 
 * "标记符表达式" ----> 
 *          除去关键字，字面量等编译器需要使用的标记之外的自定义标记都是标记符
 *          单个标记符对应的表达式就是标记符表达式
 *          比如  decltype(i) ,  i  就是 标记符表达式
 *              而 decltype((i))   (i) 就不是标记符表达式， 而是一个左值表达式， 
 */
void testp4_24(){
    cout << __func__ <<"() called.\n";

    int i;

    decltype(i) a;
                        //b 的类型推导  decltype((i)) 仅仅比  decltype(i)  多了一对小括号 就无法通过编译了
    // decltype((i)) b;  //无法通过编译，⚠️error: declaration of reference variable 'b' requires an initializer
    cout << __func__ <<"() called. done. \n";
}

/**
 *  规则3  推到出的 左值引用， 容易和其他规则混淆
 * 
 * ⚠️： 
 *  如果使用decltype定义变量，那么先声明这个变量，再再其他语句中对其进行初始化。
 *   左值引用总是需要定义时初始化，编译器会直接报错提示。这样可以知道 适用于规则3了，而不用强行记忆各个不同规则之间的不同了
 * ⚠️：
 *  c++11 模板库 添加的模板类  is_lvalue_reference ，可以帮助进行一些推导结果的识别
 */
void testp4_25(){
    cout  << __func__ << "() called.\n";
    int i = 4;
    int arr[5] = {0};
    int *ptr = arr;

    struct S {
        double d;
    } s;

    void overloaded(int);
    void overloaded(char);  //重载的函数

    int && rvalRef();   //返回右值引用

    const bool func(int);

    // role 1 :  单个标记符表达式以及访问类成员， 推导为本类型
    decltype(arr) var1;  // int[]
    decltype(ptr) var2;   // int *
    decltype(s.d) var4;   // double
    // decltype(overloaded) var5; //无法通过编译，⚠️error: reference to overloaded function could not be resolved; did you mean to call it?

    //role 2 : 将亡值， 临时变量， 推导为 右值引用
    decltype(rvalRef()) var6 = 1;  // int&&

    //role 3 : 左值， 推导为类型引用
    decltype(true? i : i) var7 = i;  //int&, 
    decltype((i)) var8 = i;  //int&,         带圆括号的左值
    decltype(++i) var9 = i;  //int&,        ++i返回i的左值
    decltype(arr[3]) var10 = i;  //int&,   []操作返回左值
    decltype(*ptr) val11 = i;   //int&,  *操作符 返回的左值
    decltype("lval") var12 = "lval";   //const char(&)[], 字符串字面常量 为左值

    //role 4 ； 以上都不是， 那么还是推导为本类型
    decltype(1) var13;         //int， 除字符串外 字面常量 都是右值
    decltype(i++) var14;       //int ,  i++返回右值
    decltype((func(1))) var15;  // const bool, 

    cout  << __func__ << "() called. done.\n";
}

#include <type_traits>
void testp4_26(){
    cout << __func__ <<"() called.\n";
    int i = 4;
    int arr[5] = {0};
    int * ptr = arr;
    int && rvalref();

    cout << boolalpha;
    cout << "decltype(rvalref()) is rvalue \t:" << is_rvalue_reference<decltype(rvalref())>::value << endl;
    cout << "decltype(true?i:i) is lvalue  \t:" << is_lvalue_reference<decltype(true?i:i)>::value << endl;
    cout << "decltype((i)) is lvalue  \t:" << is_lvalue_reference<decltype((i))>::value << endl;
    cout << endl;

    cout << "decltype(++i) is lvalue  \t:" << is_lvalue_reference<decltype(++i)>::value << endl;
    cout << "decltype(arr[3]) is lvalue  \t:" << is_lvalue_reference<decltype(arr[3])>::value << endl;
    cout << "decltype(*ptr) is lvalue  \t:" << is_lvalue_reference<decltype(*ptr)>::value << endl;
    cout << endl;

    cout << "decltype('lval') is lvalue  \t:" << is_lvalue_reference<decltype("lval")>::value << endl;
    cout << "decltype(i++) is lvalue  \t:" << is_lvalue_reference<decltype(i++)>::value << endl;
    cout << "decltype(i++) is rvalue  \t:" << is_rvalue_reference<decltype(i++)>::value << endl;
    cout << endl;

    cout << __func__ <<"() called.done.\n";
}