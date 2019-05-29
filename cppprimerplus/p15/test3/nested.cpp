#include <iostream>
#include <string>
#include "queuetp.h"

using std::string;
using std::cin;
using std::cout;
using std::endl;

int main_queuetp(){

    QueueTP<string> cs(5);
    string temp;

    while(!cs.isfull()){
        cout << "Please enter your name. You will be"
            " served in the order of arrival.\n"
            "name : ";
        getline(cin, temp);
        cs.enqueue(temp);
    }

    cout << "The queue is full. Processing begins!" << endl;

    while(!cs.isempty()){
        cs.dequeue(temp);
        cout << "Now processing " << temp << "..." << endl;
    }
    return 0;
}