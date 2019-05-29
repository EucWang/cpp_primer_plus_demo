#include <iostream>
#include "sales.h"
using namespace std;

using namespace SALES;

namespace SALES{

    void Sales::setSales() {
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
        min =ar[0];
        max = ar[0];
        for(int i=0; i<4; i++) {
            sales[i] = ar[i];
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
        average = total/4;
    }

    void Sales::setSales(const double ar[], int n){
        if(n > 4) n = 4;
        double total;
        min =ar[0];
        max = ar[0];
        for(int i=0; i<n; i++) {
            sales[i] = ar[i];
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
        average = total/n;

        if(n < 4) {
            for(int i=n;i<4; i++) {
                sales[i] = 0.0;
            }
        }
    }

    void Sales::showSales(){
        cout << "=====Sales info=======" << endl;
        cout << "SALES ARRAY : ";
        for(int i=0; i<QUARTERS; i++) {
            cout << sales[i] << " ";
        }
        cout << endl;
        cout << "AVERAGE : " << average << endl;
        cout << "MAX : " << max << endl;
        cout << "MIN : " << min << endl;
    }
}