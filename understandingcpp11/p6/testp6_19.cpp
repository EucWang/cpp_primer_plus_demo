#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

/**
 * 原子数据类型，
 * 对该数据进行操作，不需要显示的声明互斥锁或者调用加锁/解锁的api类，
 * 线程就能够对变量total 进行互斥的访问了。
 */
atomic_llong total {0};

void func2(int) {
    cout << "thread id : " << this_thread::get_id() << " and function name : " << __func__ << "() called. " << endl;
    for(long long i = 0; i<10000LL; i++){
        cout << this_thread::get_id() << endl;
        total += i;
        cout << "total = " << total << endl;
    }
    cout << __func__ << "() called. done. " << endl;
}

void testp6_19(){

    thread t1(func2, 0);
    thread t2(func2, 0);

    t1.join();
    t2.join();
    cout << total << endl;

}