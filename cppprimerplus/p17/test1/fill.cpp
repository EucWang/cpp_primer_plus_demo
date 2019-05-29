#include <iostream>


/**
 * 17.5 changing fill character for fields
 * 
 * 可以用 fill()成员函数 来改变填充字符，模式填充字符是空格
 * 和字段宽度设置不同， 新的填充字符将一直有效，直到更改它为止
 */ 
int main_fill(){
    using namespace std;

    cout.fill('*');

    const char * staff[2] = {
        "Waldo Whipsnade",
        "Wilmarie Wooper"
    };

    long bonus[2] = {900, 1350};

    for(int i=0; i<2; i++) {
        cout << staff[i] << ": $";
        cout.width(7);
        cout << bonus[i] << "\n";
    }
    

    return 0;
}