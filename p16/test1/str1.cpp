#include <iostream>
#include <string>

using namespace std;

/**
 * 16.1 str1.cpp
 */ 
int main_str1(){

    string one("Lottery Winner!");   //string 第一个构造函数
    cout << one << endl;

    string two(20, '$');            //string 第2个构造函数
    cout << two << endl;

    string three(one);            //string 第3个构造函数
    
    one += "Oops!";     //重载了+=运算符
    cout <<  one << endl;

    two = "Sorry! That was ";
    three[0] = 'p';

    string four;                    //string 第4个构造函数
    four = two + three;
    
    char alls[] = "All's well that ends well";
    string five(alls, 20);              //string 第5个构造函数
    cout << five << "!\n";

    string six(alls+6, alls+10);         //string 第6个构造函数
    cout << six << ", ";

    string seven(&five[6], &five[10]);    //string 第6个构造函数
    cout << seven << "...\n";

    string eight(four, 7 , 16);            //string 第7个构造函数
    cout << eight << " in motion!" << endl;

    string piano_man = {'L', 'i', 's', 'z', 't'};    //string 第8个构造函数
    cout << piano_man << endl;

    cout << endl;
    cout << endl;
    return 0;
}