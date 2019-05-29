#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue1.h"
#include "customer.h"

const int MIN_PER_HR = 60;

using namespace std;
//是否有新的Customer来到
bool newcustomer(double x) {
    return (rand() * x / RAND_MAX) < 1;
}

int main47(){
    
    srand(time(0));  //随机数初始化

    cout << "Case Study : Bank of Heather Automatic Teller:\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue line(qs);  //初始化 队列

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours; //初始化最大循环次数

    cout << "Enter the average number of customers per hour : ";
    double perhour;
    cin >> perhour;
    double min_per_cust;
    min_per_cust = MIN_PER_HR / perhour;  //每小时顾客平均数量

    Item temp;
    long turnaways = 0;
    long customers = 0;
    long served = 0;
    long sum_line =0;
    int wait_time =0;
    long line_wait = 0;

    for(int cycle = 0; cycle < cyclelimit; cycle ++) {
        if(newcustomer(min_per_cust)) {
            cout << "come in a customer." << endl;
            if(line.isfull()) {
                turnaways++;
                cout << "but line is full. the customer turn aways..[turnaways = " << turnaways << "]" << endl;
            }else {
                customers++;
                temp.set(cycle);
                line.enqueue(temp);
                cout << "----------------->" << temp << "into the line.<--------------" << endl;
            }
        }

        if(wait_time <= 0 && !line.isempty()) {
            line.dequeue(temp);
            wait_time = temp.ptime();
            line_wait += cycle - temp.when();
            served++;
            cout << "------------>no need to wait, and line is not empty. then a customer gone.------------>" << endl;
            cout << "next wait time is " << wait_time << endl;
        }

        if(wait_time > 0) {
            wait_time--;
            cout << "need to wait, and next wait_time is " << wait_time  << endl;
        }
        sum_line += line.queuecount();
    }

    if(customers > 0) {
        cout << "=========================================" << endl;
        cout << "Customers acccepted : " << customers << endl;
        cout << " customers served : " << served << endl;
        cout << "    turnaways: " << turnaways << endl;
        cout << "average queue size : ";
        cout.precision(2);
        cout .setf(ios_base::fixed, ios_base::floatfield);

        cout << (double) sum_line / cyclelimit << endl;
        cout << " average wait time : " 
            << (double) line_wait / served << " minutes\n";
        cout << "=========================================" << endl;
    }else {
        cout << "No customers .\n";
    }
    cout << "Done!\n";
}