#include <iostream>
#include <thread>
#include <atomic>
#include <unistd.h>

using namespace std;

/**
 * 将lock初始化为值 ATOMIC_FLAG_INIT， 即 false 的状态。
 */
atomic_flag Lock = ATOMIC_FLAG_INIT;

void f(int n) {
    cout << __func__ << "() called. n = " << n << "\n";

    // 这里不停的通过lock 的成员test_and_set 来设置lock为true    
    // 这里的test_and_set() 是一种原子操作   
    // 用于在一个内存空间原子的写入新值并且返回旧值  
    // 因此test_and_set会返回之前的lock值。
    while(Lock.test_and_set(memory_order_acquire)) {  //尝试获得锁
        cout << "waiting from thread |" << n << endl; //自旋
    }
    cout << "Thread " << n << " starts wroking " << endl;
    cout << __func__ << "() called.done.\n";
}

void g(int n) {
    cout << __func__ << "() called. n = " << n  << "\n";
    cout << "Thread " << n << " is going to start." << endl;
    Lock.clear();
    cout << "Thread " << n << " starts working." << endl;
    cout << __func__ << "() called.done.\n";
}

void testp6_20(){
    cout << __func__ << "() called.\n";
    Lock.test_and_set();  //这里设置过一次， 所以在 f()函数中就会一开始test_and_set()就返回true
    thread t1(f, 1);
    thread t2(g, 2);
    t1.join();
    usleep(100);
    t2.join();
    cout << __func__ << "() called.done.\n";
}