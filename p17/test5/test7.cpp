//
// Created by 王新年 on 2019-05-20.
//

#include <iostream>
#include <iterator>
#include <fstream>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <list>
#include <string>
#include "test.h"

void showStr(const std::string &);

void store(std::ofstream & );

void getStrs(std::ifstream &, std::vector<std::string> &);

class Store{
    private:
        std::ofstream & mFout;
    public:
        Store(std::ofstream & of):mFout(of){}

        void operator()(const std::string & str) {
            if(mFout.is_open()) {
                size_t len = str.size();
                mFout.write((char *)&len, sizeof(std::size_t));
                mFout.write(str.data(), len);
            }
        }

};

int main_p17test7(){

    using namespace std;
    vector<string> vostr;
    string temp;

    cout << "Enter strings (empty line to quit):\n";
    while(getline(cin, temp) && temp[0] != '\0') {
        vostr.push_back(temp);
    }
    cout << "Here is your input:\n";
    for_each(vostr.begin(), vostr.end(), showStr);

    //store in a file
    ofstream fout("strings.dat", ios_base::out|ios_base::binary);
    for_each(vostr.begin(), vostr.end(), Store(fout));
    fout.close();

    //recover file contents
    vector<string> vistr;
    ifstream fin("strings.dat", ios_base::in |ios_base::binary);
    if(!fin.is_open()) {
        cerr << "Could not oepn file for input.\n";
        exit(EXIT_FAILURE);
    }

    getStrs(fin, vistr);
    cout << "\nHere are the strings read from the file.\n";
    for_each(vistr.begin(), vistr.end(), showStr);

    return 0;
}


void showStr(const std::string & str) {
    std::cout << str << std::endl;
}

void getStrs(std::ifstream & fin, std::vector<std::string> & vstrs) {
   if (fin.is_open()) {
       while(true) {
           char * cLen = new char[sizeof(std::size_t)];
           if(fin.read(cLen, sizeof(std::size_t))){
               int  len = *((int *)cLen);
               std::cout << "len is " << len << std::endl;
               char * tmp = new char[len];
               if(fin.read(tmp, len)){
                   vstrs.push_back(tmp);
                   std::cout << "tmp is [" << tmp << "].\n";
               }else {
                   break;
               }
           }else {
               break;
           }
       }
   }
}