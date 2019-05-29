/**
 * 16.19
 * usealgo.cpp
 * using several STL elements
 */ 
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <iterator>
#include <algorithm>
#include <cctype>

#include "strgst.h"

using namespace std;

/**
 * 将字符转换成小写形式
 */ 
char toLower(char ch){
    return tolower(ch);
}

/**
 * 将字符串转换成小写形式
 */ 
string & ToLower(string & str);

void display(const string & s);

int main_usealgo(){

    vector<string> words;
    cout << "Enter words (enter quit to quit):\n";
    string input;
    while(cin >> input && input != "quit") {
        words.push_back(input);
    }

    cout << "\n===============result===================\n";

    cout << "You entered the following words:\n";
    for_each(words.begin(), words.end(), display);
    cout << endl;

    //place words in set, converting to lowercase
    set<string> wordset;
    transform(words.begin(), words.end(), insert_iterator<set<string>>(wordset, wordset.begin()), ToLower);

    cout << endl << "Alphabetic list of words:" << endl;
    for_each(wordset.begin(), wordset.end(), display);
    cout << endl;

    //place word and frequency in map
    map<string, int> wordmap;
    set<string>::iterator si; //遍历集合的另一种方式
    for(si = wordset.begin(); si != wordset.end(); si++) {
        wordmap[*si] = count(words.begin(), words.end(), *si);
    }

    //display map contents
    cout << endl << "Word Frequency:" << endl;
    for(si = wordset.begin(); si != wordset.end(); si++) {
        cout << *si << ": " << wordmap[*si] << endl;
    }

    return 0;
}

/**
 * 将字符串全部转换成小写形式
 */ 
string & ToLower(string & st) {
    transform(st.begin(), st.end(), st.begin(), toLower);
    return st;
}

void display(const string & s) {
    cout << s << " ";
}

