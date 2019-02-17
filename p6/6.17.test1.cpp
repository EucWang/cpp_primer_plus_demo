#include <iostream>
#include <cctype>

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char ch;
    while(cin >> ch && ch != '@'){
        if(!isdigit(ch)){
            char tmp;
            if (islower(ch)) {
                tmp = (char)toupper(ch);
            }else if(isupper(ch)) {
                tmp = (char)tolower(ch);
            }else {
                tmp = ch;
            }
            cout << tmp;
        }
    }
    cout<<endl;
    return 0;
}
