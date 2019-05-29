#include <iostream>
#include <cstdlib>
#include <ctime>
#include <typeinfo>
#include "rtti1.h"

using namespace std;

class Grand2{
    private:
        int hold;
    public:
        Grand2(int h=0):hold(h){}
        virtual void speak() const {cout << "I am a grand2 class!\n";}
        virtual int value() const {return hold;}
};

class Superb2: public Grand2{
    public:
        Superb2(int h=0):Grand2(h){}
        void speak()const {cout << "I am a superb class!\n";}
        virtual void say() const {cout << "I hold the superb2 value of " << value() << "!\n";}

};

class Magnificent2 : public Superb2 {
    private:
        char ch;
    public:
        Magnificent2(int h=0, char cv = 'A'): Superb2(h), ch(cv){}
        void speak() const {cout << "I am a magnificent2 class !\n";}
        void say() const {cout << "I hold the character " << ch << " and the integer " << value() << "!\n";}
};

Grand2 * getOne2(){
    Grand2 * p;
    switch( rand() % 3) {
        case 0:
            p = new Grand2(rand() %100);
        break;
        case 1:
            p = new Superb2(rand() %100);
        break;
        case 2:
            p = new Magnificent2(rand() %100, 'A' + rand() %26);
        break;
    }
    return p;
}

/**
 *  typeid 运算符 使得能够确定两个对象是否为同种类型，
 * 它与sizeof有些相像，可以接受两种参数：
 * 类名
 * 结果为对象的表达式
 * typeid运算符返回一个 对type_info对象的引用，
 * 其中，type_info 是在头文件typeinfo 种定义的一个类，
 * type_info重载了 ==  和 != 运算符，以便可以使用这些运算符来对类型进行比较。
 * 如果typeid(point) 接受的参数point是一个空指针，程序将引发bad_typeid异常。
 * type_info对象， 包含一个name()成员， 该函数返回一个通常是类的名称的字符串，但不一定是。
 * 
 */ 
int main_rtti2(){

    srand(time(0));
    Grand2 * pg;
    Superb2 * ps;
    for(int i=0; i<10; i++) {
        pg = getOne2();
        cout << "Now processing type [" << typeid(*pg).name() << "].\n";

        pg->speak();

        if((ps = dynamic_cast<Superb2 *>(pg)) != nullptr) {
            ps->say();
        }

        if(typeid(Magnificent2) == typeid(*pg)) {
            cout << "Yes, you're really magnificent2.\n";
        }

        cout << "\n---------------\n";
    }

    return 0;
}