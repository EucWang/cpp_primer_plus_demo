#include <iostream>
#include "sales.h"
using namespace std;

using namespace SALES;

namespace SALES{

    void setSales(Sales & s) {
        cout << "Please enter 4 sales value : "<< endl;
        double ar[4];
        for(int i=0; i<4; i++) {
            while(!(cin >> ar[i])){
                cin.clear();
                char tmp = cin.get();
                while(tmp != '\n')continue;
                cout << "Bad input, try again:" << endl;
            }
        }
        // setSales(s, ar, 4);
        double total;
        double min =ar[0];
        double max = ar[0];
        for(int i=0; i<4; i++) {
            s.sales[i] = ar[i];
            if(i >0) {
                total += ar[i];
                if(ar[i] < min) {
                    min = ar[i];
                }
                if(ar[i] > max) {
                    max = ar[i];
                }
            }
        }
        s.max = max;
        s.min = min;
        s.average = total/4;
    }

    void setSales(Sales & s, const double ar[], int n){
        if(n > 4) n = 4;
        double total;
        double min =ar[0];
        double max = ar[0];
        for(int i=0; i<n; i++) {
            s.sales[i] = ar[i];
            if(i >0) {
                total += ar[i];
                if(ar[i] < min) {
                    min = ar[i];
                }
                if(ar[i] > max) {
                    max = ar[i];
                }
            }
        }
        s.max = max;
        s.min = min;
        s.average = total/n;

        if(n < 4) {
            for(int i=n;i<4; i++) {
                s.sales[i] = 0.0;
            }
        }


    }


    void showSales(Sales & s){
        cout << "=====Sales info=======" << endl;
        cout << "SALES ARRAY : ";
        for(int i=0; i<QUARTERS; i++) {
            cout << s.sales[i] << " ";
        }
        cout << endl;
        cout << "AVERAGE : " << s.average << endl;
        cout << "MAX : " << s.max << endl;
        cout << "MIN : " << s.min << endl;
    }
}