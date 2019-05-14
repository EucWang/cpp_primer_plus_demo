#include <iostream>
#include <fstream>
#include <string>

#include "test3.h"

/**
 * 17.16
 * saving to a file and read from a file
 * 
 */ 
int main_fileio(){

    using namespace std;

    string filename;
    cout << "Enter name for new file: ";
    cin >> filename;

    ofstream fout(filename.c_str());
    fout << "For your eyes only!\n";
    cout << "Enter your secret number: ";
    float secret;
    cin.precision(8);
    cin >> secret;
    fout.precision(8);
    fout << "Your secret number is " << secret <<endl;
    fout.close();

    ifstream fin(filename.c_str());
    cout << "Here are the contents of " << filename << ":\n";
    cout << "--------------\n";
    char ch;
    while(fin.get(ch)) {
        cout << ch;
    }
    cout << "--------------\n";
    cout << "Done\n";
    fin.close();

    return 0;
}