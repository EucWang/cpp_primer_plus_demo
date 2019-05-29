#include <iostream>

/**
 * 比较2个数值型 使用 == 
 * 一定千万不能使用 =，
 */ 
int main16()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    int quizscores[10] = {
        20,20,20,20,20,19,20,28,20,20,
    };
    cout << "Doing it right:" <<endl;
    int i;
    for(i = 0; quizscores[i] == 20; i++)
    {
        cout << "quiz " << i << " is a 20" << endl;
    }
    
    // cout << "Doing it dangerously wrong: " << endl;
    // for(i = 0; quizscores[i] = 20; i++)
    // {
    //     cout << "quiz " << i << " is a 20" << endl;
    // }

    cout<<endl;
    return 0;
}
