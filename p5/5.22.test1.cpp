#include <iostream>
#include <string>

int main61()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    string tip1 = "Please enter a litter num : ";
    string tip2 = "Plase enter a another bigger num : ";

    cout << tip1;
    int num1;
    cin >> num1;

    cout << tip2;
    int num2;
    cin >> num2;

    int result = 0;
    if (num1 < num2) {
       for(int i = num1; i <= num2; i++)
       {
           result += i;
       }
    } else if(num1 > num2) {
        for(int i = num2; i <= num1; i++)
       {
           result += i;
       }
    }
    cout << "count of between " << num1 << " and " << num2 << " is " << result << endl;
    return 0;
}
