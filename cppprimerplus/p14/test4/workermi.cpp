#include "workermi.h"
#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//----------------Worker--------------------

//析构函数
Worker::~Worker(){}

/**
 * protected
 *  输出控制台显示数据
 */ 
void Worker::data() const {
    cout << "Name :\t" << fullname << endl;
    cout << "Employee ID :\t" << id << endl;
}

/**
 *  protected
 *  控制台输入获取数据
 */ 
void Worker::get() {
    getline(cin, fullname);
    cout << "Enter worker's ID:";
    cin >> id;
    while(cin.get() != '\n') {
        continue;
    }
}

//----------------Waiter--------------------

/**
 * protected
 *  模块化，只输出当前继承类部分数据
 */
void Waiter::data() const {
    cout << "Panache rating: " <<panache << endl;
}

/**
 * protected
 * 模块化，只输入当前继承类定义的部分数据
 */ 
void Waiter::get() {
    cout << "Enter waiter's panache rating:";
    cin >> panache;
    while(cin.get() != '\n') {
        continue;
    }
}

/**
 * public
 */ 
void Waiter::set() {
    cout << "Enter waiter's name:";
    Worker::get();
    get();
}

/**
 * public 
 */ 
void Waiter::show() const {
    cout << "Category: waiter\n";
    Worker::data();
    data();
}

//----------------Singer--------------------

char * Singer::pv[Singer::Vtypes] = {
    "other", "alto", "contralto",
    "soprano", "bass", "batitone", "tenor"
};

/**
 * protected
 * 只输出voice
 */ 
void Singer::data() const {
    cout << "Vocal range: " << pv[voice] << endl;
}

/**
 * protected
 * 只处理输入voice
 */ 
void Singer::get() {
    cout << "Enter number for singer's vocal range:\n";
    int i;
    for(i =0; i<Vtypes; i++) {
        cout << i << ": " << pv[i] <<"\t";
        if(i % 4 == 3) {
            cout << endl;
        }
    }
    if(i % 4 != 0) {
        cout << endl;
    }
    cin >> voice;
    while(cin.get() != '\n') continue;
}

/**
 * public 输入Singer的信息
 */ 
void Singer::set() {
    cout << "Enter singer's name : ";
    Worker::get();
    get();
}

/**
 * public 显示Singer的信息
 */ 
void Singer::show() const {
    cout << "Category : singer\n";
    Worker::data();
    data();
}

//----------------SingingWaiter--------------------

void SingingWaiter::data() const {
    Singer::data();
    Waiter::data();
}

void SingingWaiter::get() {
    Waiter::get();
    Singer::get();
}

void SingingWaiter::set() {
    cout << "Enter singing waiter's name : ";
    Worker::get();
    get();
}

void SingingWaiter::show() const {
    cout << "Category: singing waiter\n";
    Worker::data();
    data();
}