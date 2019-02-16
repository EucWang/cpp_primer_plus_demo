#include <iostream>
#include <string>

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    cout << "Enter a word : ";
    string word;
    cin >> word;

    for(int i = word.size() - 1; i >= 0; i--)
    {
        cout << word[i];
    }
    cout << "\nBye.\n";

    cout<<endl;
    return 0;
}
