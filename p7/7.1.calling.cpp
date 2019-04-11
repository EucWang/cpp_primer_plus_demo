#include <iostream>

void simple();

int main284()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    cout << "main() will call the simple() function:\n";
    simple();
    cout << "main() is finished with the simple() function.\n";
    
    cout<<endl;
    return 0;
}

void simple(){
    using namespace std;
    cout << "I'm but a simple function.\n";
}