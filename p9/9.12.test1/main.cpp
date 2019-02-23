#include <iostream>
#include "golf.h"
using namespace std;


int main()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout<<endl;

    golf ann;
    setgolf(ann, "Ann Birdfree", 24);
    showgolf(ann);

    golf andy;
    int retval = setgolf(andy);
    const char * retval_str;
    if(retval){
        retval_str = "already set fullname\n";
    }else {
        retval_str = "donot set fullname\n";
    }
    cout << retval_str << endl;
    showgolf(andy);
    cout << ">>>>Change handicap of andy to 100.\n";
    handicap(andy, 100);
    showgolf(andy);
    
    //cout<<endl;
    return 0;
}
