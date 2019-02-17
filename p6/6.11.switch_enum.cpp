#include <iostream>

/**
 * 创建枚举
 */ 
enum {
    red, orange, yellow, green, blue, violet, indigo
};

/**
 * switch 语句结合enum 来使用
 */ 
int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    cout << "Enter color code (0 - 6) : ";
    int code;
    cin >> code;
    while(code >= red && code <= indigo){
        switch(code) 
        {
            case red:
                cout << "Her lips were red.\n";
            break;
            case orange:
                cout << "Her hair was orange.\n";
            break;
            case yellow:
                cout << "Her shoes were yellow.\n";
            break;
            case green:
                cout << "Her nails were green.\n";
            break;
            case blue:
                cout << "Her sweatsuit was blue.\n";
            break;
            case violet:
                cout << "Her eyes were violet.\n";
            break;
            case indigo:
                cout << "Her mood was indigo.\n";
            break;
        }

        cout << "Enter color code (0-6):";
        cin >> code;
    }
    cout << "Bye.";
    cout<<endl;
    return 0;
}
