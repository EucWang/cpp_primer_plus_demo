#include <iostream>

int main165()
{
    using namespace std;

    char ch = 'M';

    int i = ch;

    cout << "the ascii code for character: \'" << ch << "\' is " << i << endl;

    cout << "and one to the character code." << endl;

    ch++;
    i = ch;

    cout << "the ascii code for character: \'" << ch << "\' is " << i << endl;

    cout << "display ch using cout.put() : " << endl;

    cout.put(ch);
    cout.put('!');
    cout << endl << "Done!"<<endl;


    return 0;
}