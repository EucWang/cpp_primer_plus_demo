#include <iostream>
#include "stock00.h"

using namespace std;

void test1();
void test2();
void test3();

/**
 * 10.9.usestock2.cpp 
 */
void test4();

int main269()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout<<endl;

  
    // test2();
    // test3();
    test4();
    //cout<<endl;
    return 0;
}

void test1(){

    Stock fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(15, 18.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(400, 20.00);
    fluffy_the_cat.show();

    fluffy_the_cat.buy(300000, 40.125);
    fluffy_the_cat.show();

    fluffy_the_cat.sell(300000, 0.125);
    fluffy_the_cat.show();

}

void test2(){
    cout << "Using constructors to create new objects" << endl;
    Stock stock1("NanoSmart", 12, 20.0);
    stock1.show();

    Stock stock2 = Stock("Boffo Objects" , 2, 2.0);
    stock2.show();

    cout << "Assigning stock1 to stock2: " << endl;
    stock2 = stock1;
    cout << "Listing stock1 and stock2 : " << endl;
    stock1.show();
    stock2.show();

    cout << "using a constructor to reset an object" << endl;
    stock1 = Stock("Niffy Foods", 10, 50.0);
    cout << "Revised stock1: " << endl;
    stock1.show();
    cout << "Done!\n";
}

/**
 * const修饰的对象，只能调用const修饰的类成员函数
 * 只要方法不修改调用函数，就应将其声明为const。
 */ 
void test3(){
    const Stock land = Stock("Kludgehorn Properties");
    land.show();

    Stock s3("Wahaha", 1,1.0);
    auto s2 = s3.topval(land);
    cout << "Top Val Stock is : " << endl;
    s2.show();
}

const int STKS = 4;

/**
 * 对象数组
 */ 
void test4() {
    Stock stocks[STKS] = {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks" , 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };

    cout << "Stock holdings:" << endl;
    int st;
    for(st = 0; st < STKS; st++) {
        stocks[st].show();
    }

    const Stock * top = &stocks[0];
    for(st = 1; st < STKS ; st++) {
        top = &top->topval(stocks[st]);  //这里居然可以用结构的访问方式来访问对象的函数
    }

    cout << endl << "Most valuable holding : " << endl;
    top->show();
}
