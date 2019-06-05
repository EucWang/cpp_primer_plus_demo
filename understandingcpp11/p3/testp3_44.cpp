#include <iostream>

using namespace std;

typedef unsigned char uint8;


/**
 * 字面量操作符有一定的规则，该规则跟字面量的 类型 相关：
 * 1. 如果字面量是整型数， 那么 字面量操作符函数只能接收 unsigned long long 或者 const char * 为参数。
 * 2. 如果字面量是浮点数，则字面量操作符函数只可接收long double 或者 const char* 为参数
 * 3. 如果字面量是字符串， 则字面量操作符函数只可接受(const char*, size_t)为参数
 * 
 * 后缀建议以下划线开始
 */ 

struct RGBA{
    uint8 r;
    uint8 g;
    uint8 b;
    uint8 a;
    RGBA(uint8 R, uint8 G, uint8 B, uint8 A=0):
        r(R), g(G), b(B), a(A) {}
};

//toString()
std::ostream & operator << (std::ostream & out, RGBA & col){
    return out << "r: " << (int)col.r
            << ", g: " << (int)col.g
            << ", b: " << (int)col.b
            << ", a: " << (int)col.a << endl;
}

/**
 * 一个长度为n的字符串col
 * 
 * 字面量操作符函数(literal operator)
 * 这个函数会解析字符串后面加上后缀_C的字符串，并返回一个RGBA的临时变量。
 */ 
RGBA operator ""_C(const char * col, size_t n) {
    const char * p = col;
    const char * end = col + n;
    const char * r, * g, * b, * a;
    r = g = b = a = nullptr;
    for(; p != end; ++p) {
        if (*p == 'r') r = p+1;          //指向后面一个字符‘r’位置
        else if (*p == 'g') g = p+1;    //指向后面一个字符‘g’位置
        else if (*p == 'b') b = p+1;   //指向后面一个字符‘b’位置
        else if (*p == 'a') a = p+1;    //指向后面一个字符‘a’位置
    }
    if((r == nullptr) || (g == nullptr) || (b == nullptr)) {
        throw;
    }else if(a== nullptr) {
        return RGBA(atoi(r), atoi(g), atoi(b));
    } else {
        return RGBA(atoi(r), atoi(g), atoi(b), atoi(b));
    }
}

/**
 * 这里接收右值的参数作为入参，
 * 比如 字面量操作符函数返回的临时变量
 */ 
void blend(RGBA && col1, RGBA && col2) {
    cout << "blend " << endl << col1 << col2 << endl;
}

void blend(RGBA & col1, RGBA & col2) {
    cout << "blend " << endl << col1 << col2 << endl;
}

struct Watt{
    unsigned int v;
};

Watt operator ""_W(unsigned long long v) {
    return {(unsigned int)v};
}

void testp3_44(){
    cout << __func__ << "() called.\n";

    RGBA col1(255, 240, 155);
    RGBA col2({15, 255, 10, 7});
    blend(col1, col2);

    blend("r255 g240 b155"_C, "r15 g255 b10 a7"_C);  //这里的字面量是字符串，

    Watt capacity = 1024_W;   //这里的字面量是整形

    cout << "Watt capacity is " << capacity.v << endl;

    cout << __func__ << "() called.done\n";
}