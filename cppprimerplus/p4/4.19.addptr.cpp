#include <iostream>

/**
 * C++将数组名解释为数组第一个元素的地址
 * 数组名被解释成第一个元素的地址，而对数组名应用地址运算符时，得到的是这个数组的地址
 * 
 * short tell[10];
 * cout << tell << endl;
 * cout << &tell << endl;
 * 从数组上讲， 这两个地址是相同的，
 * 但是从概念上讲，&tell[0] 是2个字节内存块的地址，而&tell是20个字节的内存块的地址
 * 所以 tell+1  结果是将 地址值+2
 *   而  &tell + 1 结果是将 地址值 + 20
 * 也就是说，  tell 是一个  short*指针
 *        而 &tell 是 指向 包含20个元素的short数组的指针
 * 
 * short (* pas)[20] = &tell;
 * 
 */ 

int main21()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    double wages[3] = { 10000.0, 20000.0, 30000.0 };
    short stacks[3] = {3, 2, 1};

    double * pw = wages;  //指向数组的指针，数组名就是数组第一个元素的地址

    short * ps = &stacks[0];

    cout << "pw = " << pw << ", *pw = " << *pw << endl; 

    cout << "ps = " << ps << ", *ps = " << *ps << endl;
    ps++;   //指针左移
    cout << "ps = " << ps << ", *ps = " << *ps << endl;

    
    cout << "stacks[0] = " << stacks[0] << ", stacks[1] = " << stacks[1] << endl;
    // *(stacks + 1) 等价于 stacks[1]
    // 先计算数组第二个元素的地址，然后找到第二地址的数据
    cout << "*stacks = " << *stacks << ", *(stacks+1) = " << *(stacks+1) << endl;

    cout << "sizeof(wages) = " << sizeof(wages) <<endl;  //数组的字节数

    cout << "sizeof(pw) = " << sizeof(pw) << endl;  

    //对数组名应用地址运算符， 得到的是整个数组的地址，
    // 直接使用数组名，得到的是数组第一个元素的地址
    double (* wages_arr_pt)[3] = &wages;
    cout << " wages : " << **wages_arr_pt << endl;

    cout << endl;
    return 0;
}
