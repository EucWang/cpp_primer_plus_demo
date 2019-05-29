#include <iostream>
#include <array>

int main203()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    array<double, 10> donations;
    int i;
    double total;
    for(i = 0; i < 10; i++) {
        if(cin >> donations[i]){
            total += donations[i];
        }else {
            break; //结束输入
        }
    }

    if (i == 0) {
        cout << "no data.";
    }else {
        double average = total / i;
        int moreThanAverage = 0;
        for(int j = 0; j < i; j++) {
            if (donations[j] > average) {
                moreThanAverage++;
            }
        }
        cout << "There have " << i << " donation , and average value is " << average << endl;  
        cout << "There " << moreThanAverage << " donation more than average.\n";
    }
    
    cout<<endl;
    return 0;
}
