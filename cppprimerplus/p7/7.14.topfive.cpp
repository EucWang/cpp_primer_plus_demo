#include <iostream>
#include <string>

using namespace std;

const int SIZE = 5;

void display(const string sa[], int n);

int main274()
{
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    string list[SIZE];
    cout <<"Enter your "<< SIZE <<" favorite astronomical sights:\n";
    for(int i = 0; i < SIZE; i++)    {
        cout << (i+1) << ": ";
        getline(cin, list[i]);  //看这里，数组list的每一个元素都是string对象，可以像这样使用它：
    }

    cout << "Your list:\n";
    display(list, SIZE);
    
    cout<<endl;
    return 0;
}

void display(const string sa[], int n){
    for(int i = 0; i < n; i++)
    {
        cout << (i+1) << ": " << sa[i] << endl;
    }
    
}
