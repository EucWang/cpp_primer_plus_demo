#include <iostream>
#include "string1.h"

using namespace std;

void test();

int main42(){

    test();
    // String a("wahaha");
    // String b("duolemei");
    // String c = a+b;
    // cout << c << endl;

    // String d = c.up();
    // cout << d << endl;
    // cout << d.low() << endl;

    // cout << "count of  letter a is :" << c.countOf('a') << endl;

    return 0;
}

void test(){
    String127 s1(" and I am a C++ Student.");
    String127 s2 = "Please enter your name: ";
    String127 s3;

    cout << s2;
    cin >> s3;

    s2 = "My name is " + s3;
    cout << s2 << ".\n";
    s2 = s2 + s1;
    s2.up();
    
    cout << "The String127\n" << s2 << "\ncontians " << s2.has('A')
        << " 'A' characters in it.\n";

    s1 = "red";
    String127 rgb[3] = {
        String127(s1), String127("green"), String127("blue")
    };
    cout << "Enter the name of a primary color for mixing light: ";
    String127 ans;
    bool success = false;
    while(cin>>ans){
        ans.low();
        for(int i=0; i<3;i++) {
            if(ans == rgb[i]) {
                cout << "That's right!\n";
                success = true;
                break;
            }
        }
        if(success) {
            break;
        }else {
            cout << "Try again!\n";
        }
    }
    cout << "Bye!\n";
}