#include <iostream>
#include <ctime>  //引入clock()函数, clock_t 类型

/**
 * clock()函数， 返回程序开始执行后所用的系统时间，
 * clock()函数有2个问题：
 *    clock()函数返回的时间单位不一定是秒，
 *    clock()函数返回的类型在某些系统上可能是long,在另一些系统上可能是unsigned long或者其他类型.
 * 
 * 头文件ctime 定义了一个符号常量 :  
 * CLOCKS_PER_SEC， 该常量等于每秒钟包含的系统时间单位数。
 * 因此，将系统时间除以这个值，可以得到秒数； 或者将秒数乘以CLOCKS_PER_SEC可以得到以系统时间单位为单位的时间
 * 
 * 其次，ctime将clock_t 作为clock()返回类型的别名，意味着可以将变量声明为clock_t类型，
 * 编译器将把它转换为long, unsigned int或者适合系统的其他类型.
 */ 

/**
 * 类型别名
 * C++为类型建立别名有两种方式：
 * 1. 使用与处理器：
 *  #define BYTE char
 * 这样，与处理器将在编译程序时用char替换所有BYTE，从而使BYTE成为char的别名
 * 
 * 2. 使用C++/C的关键字 typedef 来创建别名。
 * 例如，要将byte作为char的别名，可以：
 *  typedef char byte;   // makes byte an alias for char
 * 例如：要将byte_pointer成为char指针的别名，可以将byte_pointer声明为char指针，然后在
 * 前面加上typedef：
 * typedef char * byte_pointer;
 * 通用格式：
 * typedef typeName aliasName;
 * 
 */ 

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    float secs;
    cin >> secs;

    clock_t delay = secs * CLOCKS_PER_SEC;
    cout << "starting\a\n";

    clock_t start = clock();
    while(clock() - start < delay){} //延迟 secs秒，停留在while循环中
    
    cout<< "done \a\n" << endl;
    return 0;
}