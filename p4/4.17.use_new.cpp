#include <iostream>

/**
 * new关键字分配的内存是在堆（heap） 或者 自由存储区（free store）
 * 而其他变量存储在 栈（stack）中
 * ⚠️警告：
 * 1. 一定要配对的使用new和delete,否则容易导致内存泄漏
 * 2. 不要尝试释放已经释放了的内存，这样做的结果是不确定的
 * 3. 不要使用delete来释放申命变量所获得的内存，只能针对new分配的内存
 * 4. 对于大型数据（数组，字符串，结构），应该使用new关键字
 */ 

int main18()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int night = 1001;
    int* pt = new int;
    *pt = 1001;

    cout << "night value is : " << night << ", location : " << &night << endl;

    cout << "int value is : " << *pt << ", location : " << pt << endl;

    double * pt2 = new double;
    *pt2 = 10000001.0;

    cout << "double value : " << *pt2 << ", location of pt2 : " << pt2 
        << ", location of pointer : " << &pt2 << endl;

    cout << "size of pt : " << sizeof(pt)
        << ", size of *pt : " << sizeof(*pt) << endl;

    cout << "size of pt2 : " << sizeof(pt2)
        << ", size of *pt2 : " << sizeof(*pt2) << endl;

    // 释放内存, delete只能释放new分配的内存，然而，对空指针释放内存是安全的。
    // 
    delete pt;
    delete pt2;

    cout<<endl;
    return 0;
}
