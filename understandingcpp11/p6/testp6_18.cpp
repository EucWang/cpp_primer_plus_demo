// #include <pthread.h>
#include <pthread.h>
#include <thread>
#include <iostream>

using namespace std;

static long long total = 0;


/**
 * pthread_mutex_t 互斥锁
 */
pthread_mutex_t m = PTHREAD_MUTEX_INITIALIZER;

void * func(void *) {
    cout << __func__ << "() called." << endl;
    long long i;
    for(i = 0; i< 100LL; i++) {
        pthread_mutex_lock(&m);  //加锁 , 可以确保只有一个线程可以访问下面的语句
        total += i;
        cout << "thread id : " << this_thread::get_id() << "\ttotal is : " << total << endl;
        pthread_mutex_unlock(&m);  //解锁
    }
    cout << __func__ << "() called.done." << endl;
}

void testp6_18(){
    pthread_t thread1, thread2;
    if(pthread_create(&thread1, NULL, &func, NULL)) {
        throw;
    }
    if(pthread_create(&thread2, NULL, &func, NULL) ){
        throw;
    }

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    cout << total << endl;
}