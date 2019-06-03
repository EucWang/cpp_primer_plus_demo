#include <iostream>

#include <list>
#include <vector>
#include <deque>

#include "test3.h"


using namespace std;

//第一个版本， 每一个构造函数都需要对每一个字段进行设置，没有覆盖到的用initRest()方法进行设置
// class Info{
// private:
//     void initRest(){cout << "initRest()" << endl;}
//     int type;
//     char name;
// public:
//     Info():type(1), name('a') {initRest();}
//     Info(int i):type(i), name('a'){initRest();}
//     Info(char e):type(1), name(e){initRest();}
//     int getType(){return type;}
//     char getName(){return name;}
// };

//第二个版本，为每一个字段提供一个默认值，没有覆盖到的就会使用默认值
// class Info{
// private:
//     void initRest(){cout << "initRest()" << endl;}
//     int type{1};
//     char name{'a'};
// public:
//     Info(){initRest();}
//     Info(int i):type(i){initRest();}
//     Info(char e):name(e){initRest();}
//     int getType(){return type;}
//     char getName(){return name;}
// };

//第三个版本，为字段提供默认值的前提下，采用委托构造函数的方式，简化调用
//初始化列表中使用了委派构造函数，那么字段的赋值只能在构造函数体中调用了
// 构造函数在初始化列表中同时使用委派构造函数和字段赋初值
// class Info{
// private:
//     void initRest(){cout << "initRest()" << endl;}
//     int type{1};
//     char name{'a'};
// public:
//     Info(){initRest();}
//     Info(int i):Info(){type = i;}
//     Info(char e):Info(){name = e;}  //
//     int getType(){return type;}
//     char getName(){return name;}
// };

//第四个版本， 委派构造函数为全部字段赋值, 这样可以避免使用了委派构造函数，但是还需要在构造函数体中对字段的赋值
//所以， 委派构造函数 应该是 最为“通用”的一个构造函数
// class Info{
// private:
//     void initRest(){cout << "initRest()" << endl;}
//     int type{1};
//     char name{'a'};
// public:
//     Info():Info(1, 'a'){}
//     explicit Info(int i):Info(i, 'a'){}
//     explicit Info(char e):Info(1, e){}  //
//     Info(int i, char e): type(i), name(e){}
//     int getType(){return type;}
//     char getName(){return name;}
// };

//第五个版本，  链状的调用委派构造函数
//注意，不要形成委托环
class Info{
private:
    void initRest(){cout << "initRest()" << endl;}
    int type{1};
    char name{'a'};
    Info(int i, char e): type(i), name(e){}
public:
    Info():Info(1){}
    explicit Info(int i):Info(i, 'a'){}
    explicit Info(char e):Info(1, e){}  //
   
    int getType(){return type;}
    char getName(){return name;}
};

//委托构造函数是一个模板函数的情况
//这样可以接受多种容器对其进行初始化
class TDConstructed {
list<int> l;
template<class T>
TDConstructed(T first, T last) : l(first, last) {}

public:
    TDConstructed(vector<short> & v): TDConstructed(v.begin(), v.end()){}
    TDConstructed(deque<int> & d): TDConstructed(d.begin(), d.end()){}
};

//委派构造函数中使用try..catch.. 从而统一处理异常
class DCExcept {
public:
    DCExcept(double d)   //这里调用了委派构造函数，同时捕获其抛出的异常，虽然捕获了，但是程序依然会终止，这是合理的。
        try : DCExcept(1, d){
            cout << "Run the body." << endl;
        }catch(...) {
            cout << "Caught exception." << endl;
        }
private:
    DCExcept(int i, double d) { //这里委派构造函数中抛出了异常，
        cout << "going to throw!" << endl;
        throw 0;
    }
    int type;
    double data;
};

void testp3_2(){

    Info info;
    cout << info.getType() << ", " << info.getName() << endl;
    cout << "testp3_2" <<endl;


    DCExcept dc(3.1415926);
}