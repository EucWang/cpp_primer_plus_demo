#include <iostream>
using namespace std;
#include "stringbad.h"

void callme1(StringBad &);
void callme2(StringBad);

int main()
{
   
   {
       cout << "======================" << endl;
        cout << "Starting an inner block.\n";
        StringBad headline("Celery Stalks at Midnight");
        StringBad headline2("Lettuce Prey");
        StringBad sports("Spinach Leaves Bow1 for Dollars");

        cout << "headline1 : " << headline << endl;
        cout << "headline2 : " << headline2 << endl;
        cout << "sports : " << sports << endl<<endl;

        callme1(headline);
        cout << "after callme1(headline1), headline1 : "<< headline << endl<<endl;

        callme2(headline2);
        cout << "after callme2(headline2), headline2 : "<< headline2 << endl<<endl;

        cout << "Initialize one object to another:\n";
        StringBad sailor = sports;
        cout << "sailor: "<<sailor << endl<<endl;

        cout << "Assign one object to another : \n";
        StringBad knot;
        knot = headline;
        cout << "knot: " << knot << endl<<endl;
        cout << "Exiting the block.\n";
        cout << "==================" << endl;
        cout << "then call delete all objects in block." << endl;
   }
    
    cout << "End of main() \n";
    return 0;
}

void callme1(StringBad & rsb) {
    cout << "String passed by reference : \n";
    cout << "   \"" << rsb << "\"\n";
}

void callme2(StringBad sb) {
    cout << "String passed by value : \n";
    cout << "   \"" << sb << "\"\n";
}