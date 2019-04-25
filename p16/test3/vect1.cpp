/**
 * 16.7 introducint the vector template
 */ 

#include <iostream>
#include <vector>
#include <string>

const int NUM = 5;

using std::vector;
using std::string;
using std::cin;
using std::cout;
using std::endl;

int main_vect1(){

    vector<int> ratings(NUM);
    vector<string> titles(NUM);

    cout << "You will do exactly as told. You will enter" << endl
        << NUM << " book titles and yours ratings (0-10)." << endl;

    int i;
    for(i = 0; i < NUM; i++) {
        cout  << "Enter title #" << i +1 << ": ";
        getline(cin, titles[i]);
        cout << "Enter your rating (0-10): ";
        cin >> ratings[i];
        cin.get();
    }
    cout << "Thank you. You entered the following:\n"
        << "Rating\t Book\n";
    for(i=0; i<NUM; i++) {
        cout << ratings[i] << "\t" << titles[i] << endl;
    }

    return 0;
}