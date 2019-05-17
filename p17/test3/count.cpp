#include <iostream>
#include <fstream>
#include <cstdlib>

/**
 * 17.17 count.cpp
 * counting characters in a list of files
 * 用同一个 文件流对象  去轮流打开关闭多个文件
 * 
 * 
 * is_open()    可以确定是否指定的文件打开成功
 * clear()    关闭文件流之前最后clear()一下
 * close()     关闭文件流
 */ 
int main_count(int argc, char * argv[]) {
    using namespace std;

    if(argc == 1) {
        cerr << "Usage : " << argv[0] << " filename[s]\n";
        exit(EXIT_FAILURE);
    }

    ifstream fin;
    long count;
    long total = 0;
    char ch;
    for(int file = 1; file < argc; file ++) {
        fin.open(argv[file]);
        if(!fin.is_open()) {
            cerr << "Cound not open " << argv[file] << endl;
            fin.clear(); //清空流
            continue; 
        }

        count = 0;
        while(fin.get(ch)) {
            count++;
        }

        cout << count << " characters in " << argv[file] << endl;
        total += count;
        fin.clear();  //首先清空流
        fin.close();  //然后再关闭流， 关闭流之后，可以重新open()指定一个新的文件
    }
    cout << total << " characters in all files.\n";
    return 0;
}