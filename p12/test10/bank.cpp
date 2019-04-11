#include <iostream>
#include <cstdlib>
#include <ctime>
#include "queue1.h"
#include "customer.h"

const int MIN_PER_HR = 60;

using namespace std;
//是否有新的Customer来到
bool newcustomer1210(double x) {
    return (rand() * x / RAND_MAX) < 1;
}

int main64(){
    
    srand(time(0));  //随机数初始化

    cout << "Case Study : Bank of Heather Automatic Teller:\n";
    cout << "Enter maximum size of queue: ";
    int qs;
    cin >> qs;
    Queue1210 line1(qs);  //初始化 队列
    Queue1210 line2(qs);  //初始化 队列

    cout << "Enter the number of simulation hours: ";
    int hours;
    cin >> hours;
    long cyclelimit = MIN_PER_HR * hours; //初始化最大循环次数， 也就是分钟数

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
    int wait_time1 =0;
    int wait_time2 =0;
    long line_wait1 = 0;
    long line_wait2 = 0;

    for(int cycle = 0; cycle < cyclelimit; cycle ++) {//一分钟循环一次
        if(newcustomer1210(min_per_cust)) { //根据 每小时顾客平均数量 来随机获取当前循环是否有新顾客进来
            cout << "come in a customer." << endl;
            if(line1.isfull() && line2.isfull()) {
                turnaways++;
                cout << "but line is full. the customer turn aways..[turnaways = " << turnaways << "]" << endl;
            }else {

                if(line1.queuecount() <= line2.queuecount()) {
                    customers++;
                    temp.set(cycle);
                    line1.enqueue(temp);
                    cout << "------1----------->" << temp << "into the line1.<------1--------" << endl;
                } else {
                    customers++;
                    temp.set(cycle);
                    line2.enqueue(temp);
                    cout << "-------2---------->" << temp << "into the line2.<----------2----" << endl;
                }
            }
        } else {
            cout << "this minute " << cycle << " no customer.";
        }

        if(wait_time1 <= 0 && !line1.isempty()) {
            if(!line1.isempty()) {
                line1.dequeue(temp);
                wait_time1 = temp.ptime();
                line_wait1 += cycle - temp.when();
                served++;
                cout << "------------>no need to wait, and line1 is not empty. then a customer gone.------------>" << endl;
                cout << "next wait time is " << wait_time1 << endl;
            }
        }

        if(wait_time2 <= 0 && !line2.isempty()) {
            line2.dequeue(temp);
            wait_time2 = temp.ptime();
            line_wait2 += cycle - temp.when();
            served++;
            cout << "------------>no need to wait, and line2 is not empty. then a customer gone.------------>" << endl;
            cout << "next wait time is " << wait_time2 << endl;
        }

        if(wait_time1 > 0) {
            wait_time1--;
            cout << "need to wait, and next wait_time is " << wait_time1  << endl;
        }
        

        if(wait_time2 > 0) {
            wait_time2--;
            cout << "need to wait, and next wait_time is " << wait_time2  << endl;
        }

        sum_line += line1.queuecount();
        sum_line += line2.queuecount();
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
        cout << " average wait time1 : " 
            << (double) line_wait1 / served << " minutes\n";
        cout << " average wait time2 : " 
            << (double) line_wait2 / served << " minutes\n";
        cout << "=========================================" << endl;
    }else {
        cout << "No customers .\n";
    }
    cout << "Done!\n";
}