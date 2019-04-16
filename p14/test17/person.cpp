//
// Created by 王新年 on 2019-04-12.
//

#include <iostream>
#include "person.h"

using std::cout;
using std::cin;
using std::endl;

//--------------------------------------------
//##########  Person2  ####################

//#protected
void Person2::showdata(){
    cout << "[" << firstname << " " << lastname << "] ";
}

//#protected
void Person2::setdata(string tag){
    cout << "Enter " << tag <<"'s firstname : " << endl;
    getline(cin, firstname);
    cout << "Enter " << tag <<"'s lastname : " << endl;
    getline(cin, lastname);
};

//#public
void Person2::show(){
    cout << "Person2 show->" << endl;
    cout << firstname << " " << lastname << endl;
}

//#public
void Person2::set(){
    setdata("Person2");
}


//--------------------------------------------
//##########  Gunslinger  ####################

//#protected
void Gunslinger::showdata() {
    cout << "\ntime of take out gun is "<< draw()
         << "\nmarkcount is " << markcount << " ";
}

//#protected
void Gunslinger::setdata(string tag) {
    cout << "Enter " << tag <<"'s markcount :" << endl;
    cin >> markcount;
    cin.clear();
    while(cin.get() != '\n') {
        continue;
    };
}

//#public
//枪手的拔枪时间
double Gunslinger::draw(){
//    srand(time(0));
    return rand();
}


//#public
void Gunslinger::show() {
    cout << "Gunslinger show->" << endl;
    Person2::showdata();
    showdata();
    cout << endl;
}

//#public
void Gunslinger::set() {
    Person2::setdata("Gunslinger");
    setdata("Gunslinger");
}


//--------------------------------------------
//##########  PokerPlayer  ####################

//#protected
void PokerPlayer::showdata(){
    cout << "\nonce again card is " << draw();
}

void PokerPlayer::setdata(string tag){
    Person2::setdata(tag);
}


//#public
//返回1 ～ 52之间的随机数
int PokerPlayer::draw(){
//    srand(time(0));
    return ((int)(rand()*100))%52;
};

//#public
void PokerPlayer::show(){
    cout << "PokerPlayer show->" << endl;
    Person2::showdata();
    showdata();
    cout << endl;
}

//#public
void PokerPlayer::set(){
    setdata("PokerPlayer");
}


//--------------------------------------------
//##########  BadDude  ####################

//#protected
void BadDude::showdata() {
    Person2::showdata();
    Gunslinger::showdata();
    PokerPlayer::showdata();
}

//#protected
void BadDude::setdata(string tag) {
    PokerPlayer::setdata(tag);
    Gunslinger::setdata(tag);
}


//#public
void BadDude::show(){
    cout << "BadDude show->" << endl;
    showdata();
    cout << endl;
}

//#public
double BadDude::gdraw(){
    return Gunslinger::draw();
}

//#public
int BadDude::cdraw(){
    return PokerPlayer::draw();
}

//#public
void BadDude::set(){
    setdata("BadDude");
}