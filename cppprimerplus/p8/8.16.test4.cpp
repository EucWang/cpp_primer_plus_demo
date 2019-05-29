#include <iostream>
#include <cstring>  // strlen(), strcpy()

using namespace std;

struct stringy{
    char * str;  //points to a string
    int ct;      // length of string (not counting '\0')
};

void set(stringy& b , char * c);

void show(const stringy& b, int n=1);

void show(const string& t, int n=1);

int main245()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    //cout<<endl;

    stringy beany;

    char testing[] = "Reality isn't what it used to be.";

    set(beany, testing);

    show(beany);
    show(beany, 2);
    testing[0] = 'D';
    testing[1] = 'u';
    show(testing);
    show(testing, 3);
    show("DONE!");
    
    delete [] beany.str;
    //cout<<endl;
    return 0;
}

void set(stringy& b, char * t) {
    int len = strlen(t);
    b.str = new char[len + 1];
    strcpy(b.str, t);
    b.ct = len;
}

void show(const stringy& b, int n){
    cout << "=======stringy info=======" << endl;
    cout << "[\n\tstr : " << b.str << "\n\tct : " << b.ct << "\n]\n"; 
    if(n >= 2) {
        show(b, n-1);
    }
}

void show(const string& b, int n){
    cout << b << "\n"; 
    if(n >= 2) {
        show(b, n-1);
    }
}
