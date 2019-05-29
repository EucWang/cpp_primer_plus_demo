#include <iostream>


/**
 * 17.4 using the width method
 * 
 * int width()  返回字段宽度的当前设置
 * int width(int i); 将字段宽度设置为i，并返回旧的字段宽度值
 * 
 * width(int i) 设置方法只影响下一个项目，然后字段宽度将恢复为默认值.
 * 
 * 输出默认 右对齐
 */ 
int main_width(){

    using std::cout;

    int w = cout.width(30);
    cout << "default field width = " << w << ":\n";
    cout.width(5);
    cout << "N" << ":";
    cout.width(8);
    cout << "N * N" <<":\n";

    for(long i=1; i<=100; i*=10) {
        cout.width(5);
        cout << i << ":";
        cout.width(8);
        cout << i * i << ":\n";
    }

    return 0;
}