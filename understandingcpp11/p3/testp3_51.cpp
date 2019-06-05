#include <iostream>
#include <type_traits>
#include <map>

using namespace std;

/**
 * 为 类型定义别名
 * 关键字 ：
 * using
 * typedef
 * 
 * 头文件 type_traits 中的模板 is_same<T1, T2>
 * 判断 T1， T2 两个类型是否相同，
 * 查看模板的value
 */ 
using uint = unsigned int;
typedef unsigned int UINT;
using sint = int;

/**
 * using 比 typedef 更加灵活
 * 如这里 将 map<T, char*> 定义为一个MapString类型
 */ 
template <typename T> 
using MapString = map<T, char*>;

void testp3_51(){
    cout << __func__ << "\n() called.\n";

    cout << boolalpha << is_same<uint, UINT>::value << endl;

    cout << __func__ << "() called.done.\n";
}