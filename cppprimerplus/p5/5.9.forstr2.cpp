#include <iostream>
#include <string>

int main26()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    cout << "Enter a word : ";
    string word;
    cin >> word;

    char temp;
    int i,j;
    for(j = 0, i = word.size() - 1; j < i; --i, ++j)
    {
        temp = word[i];
        word[i] = word[j];
        word[j] = temp;
    }
    cout << word << "\nDone\n";
    cout<<endl;
    return 0;
}