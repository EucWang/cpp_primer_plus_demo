#include <iostream>
#include "stock00.h"

using namespace std;

void test121();
void test122();
void test123();

/**
 * 10.9.usestock2.cpp 
 */
void test124();

int main40()
{
    test122();
    test123();
    test124();
    return 0;
}

void test121(){

    Stock128 fluffy_the_cat;
    fluffy_the_cat.acquire("NanoSmart", 20, 12.50);
    cout << fluffy_the_cat << endl;

    fluffy_the_cat.buy(15, 18.125);
    cout << fluffy_the_cat << endl;

    fluffy_the_cat.sell(400, 20.00);
    cout << fluffy_the_cat << endl;

    fluffy_the_cat.buy(300000, 40.125);
    cout << fluffy_the_cat << endl;

    fluffy_the_cat.sell(300000, 0.125);
    cout << fluffy_the_cat << endl;

}

void test122(){
    cout << "Using constructors to create new objects" << endl;
    Stock128 stock1("NanoSmart", 12, 20.0);
    cout << stock1 << endl;

    Stock128 stock2 = Stock128("Boffo Objects" , 2, 2.0);
    cout << stock2 << endl;

    cout << "Assigning stock1 to stock2: " << endl;
    stock2 = stock1;
    cout << "Listing stock1 and stock2 : " << endl;
    cout << stock2 << endl;

    cout << "using a constructor to reset an object" << endl;
    stock1 = Stock128("Niffy Foods", 10, 50.0);
    cout << "Revised stock1: " << endl;
    cout << stock1 << endl;
    cout << "Done!\n";
}

/**
 * const修饰的对象，只能调用const修饰的类成员函数
 * 只要方法不修改调用函数，就应将其声明为const。
 */ 
void test123(){
    const Stock128 land = Stock128("Kludgehorn Properties");
    // land.show();
    cout << land << endl;

    Stock128 s3("Wahaha", 1,1.0);
    auto s2 = s3.topval(land);
    cout << "Top Val Stock128 is : " << endl;
    // s2.show();
    cout << s2 << endl;
}

const int STKS = 4;

/**
 * 对象数组
 */ 
void test124() {
    Stock128 stocks[STKS] = {
        Stock128("NanoSmart", 12, 20.0),
        Stock128("Boffo Objects", 200, 2.0),
        Stock128("Monolithic Obelisks" , 130, 3.25),
        Stock128("Fleep Enterprises", 60, 6.5)
    };

    cout << "Stock128 holdings:" << endl;
    int st;
    for(st = 0; st < STKS; st++) {
        // stocks[st].show();
        cout << stocks[st] << endl;
    }

    const Stock128 * top = &stocks[0];
    for(st = 1; st < STKS ; st++) {
        top = &top->topval(stocks[st]);  //这里居然可以用结构的访问方式来访问对象的函数
    }

    cout << endl << "Most valuable holding : " << endl;
    // top->show();
    cout << (*top) << endl;
}
