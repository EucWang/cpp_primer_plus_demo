#include <iostream>


int main28()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    // cout<<endl;
    
    // cout<<endl;

    cout << "Enter number of rows : ";
    int rows = 0;
    cin >> rows;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < rows; j++)
        {
            if( j < rows - i - 1)
            {
                cout << ". ";
            }else {
                cout << "* ";
            }
        }
        cout << endl;
    }

    return 0;
}
