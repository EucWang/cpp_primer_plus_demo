#include <iostream>
#include <cstring>

int main48()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    // cout<<endl;

    const char * tip = "Enter words (to stop, type the word done):";
    cout << tip;

    char word[32];
    int count = 0;
    do{
        cin >> word;
        cout << word << endl;
        if(strcmp(word, "done") == false) //返回false才便是相等， 条件成立
        {
            cout << "\n!!end input!!\n";
            break;
        }
        count++;
    } while(true);
    
    cout << "You entered a total of " << count << " words" << endl;
    // cout<<endl;
    return 0;
}
