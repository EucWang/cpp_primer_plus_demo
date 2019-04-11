#include <iostream>
#include <vector>  // STL C++98
#include <array>

/**
 * 无论是数组，vector对象还是array对象，都可以使用标准数组表示法来访问各个元素
 * array对象和数组存储在相同的内存区域（栈）中， 而vector对象存储在另一个区域（自由存储区或者堆）中
 * 可以将一个array对象赋值给另一个array对象，而对于数组，必须逐个元素复制数据 
 */
int main267()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    //c, orginal c++
    double a1[4] = {1.2, 2.4, 3.6, 4.8};
    
    //C++ 98 STL  创建4个元素的vector
    vector<double> a2(4);
    // c98里初始化vector只能这么麻烦
    a2[0] = 1.0 /3.0;
    a2[1] = 1.0 /5.0;
    a2[2] = 1.0 /7.0;
    a2[3] = 1.0 /9.0;

    //c++11 ,创建和初始化array对象
    array<double, 4> a3 = {3.14, 2.72, 1.62, 1.41};
    array<double, 4> a4;
    a4 = a3;
    cout << "a1[2] : " << a1[2] << " \tat " << &a1[2] << endl;
    cout << "a2[2] : " << a2[2] << " \tat " << &a2[2] << endl;
    cout << "a3[2] : " << a3[2] << " \tat " << &a3[2] << endl;
    cout << "a4[2] : " << a4[2] << " \tat " << &a4[2] << endl;

    /**
     * 索引-2， 表示找到a1指向的地方，然后向前移动两个元素，将给定的值存储到目的地。也就是将信息存储到数组的外面来
     */ 
    a1[-2] = 20.2;   //会抛出警告
    cout << endl;
    cout << "a1[-2] : " << a1[-2] << " \tat " << &a1[-2] << endl;
    cout << "a3[2] : " << a3[2] << " \tat " << &a3[2] << endl;
    cout << "a4[2] : " << a4[2] << " \tat " << &a4[2] << endl;
    
    cout<<endl;
    return 0;
}
