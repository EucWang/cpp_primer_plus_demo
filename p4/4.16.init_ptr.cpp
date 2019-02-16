#include <iostream>

/**
 * ⚠️警告：一定要对指针执行初始化设置。
 * 可以使用new关键字为指针分配空间
 * 例如： int* pt = new int;
 */ 

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int higgen = 5;
    int* pt = &higgen;

    cout << "Value of higgen :" << higgen << "\n\tAddress of higgen : " << &higgen << endl;

    cout << "Value of *pt : " << *pt << "\n\tValue of pt : " << pt << endl;

    // fellow没有初始化，它可能有任何值，不管值是什么，
    // 程序都将它解释为存储223322的地址。
    // 如果fellow中存储的恰巧是程序代码其他位置的地址，那么这会导致一些最隐匿的，最难以发现的bug。
    long* fellow; 
    *fellow = 223322; 

    // 指针不是整数，
    // 如果要将整数赋值给指针， 需要强制转换
    int* pt2;
    pt2 = (int*) 0xB8000000;

    //为一个数据对象（可以是结构，也可以是基本数据类型）获得并分配内存的通用格式如下：
    // typeName * pointer_name = new typeName;
    int* pt3 = new int;

    cout<<endl;
    return 0;
}
