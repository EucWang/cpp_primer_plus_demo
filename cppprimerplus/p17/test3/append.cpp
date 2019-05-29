#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>


/**
 * 17.18
 * append.cpp 
 * appending information to a file
 * 
 * --------------------------------------------------------
 * c++                                          c           
 * --------------------------------------------------------
 * ios_base::in                                 "r"         只读    
 * --------------------------------------------------------
 * ios_base::out                                "w"         和下一条等价
 * --------------------------------------------------------
 * ios_base::out|ios_base::trunc                "w"         写入，如果存在，则清空文件
 * --------------------------------------------------------
 * ios_base::out|ios_base::app                  "a"         写入，只追加
 * --------------------------------------------------------
 * ios_base::out|ios_base::out                  "r+"        读写，指定位置写入
 * --------------------------------------------------------
 * ios_base::out|ios_base::out|ios_base::trunc   "w+"       读写，如果存在，则清空文件
 * --------------------------------------------------------
 * c++mode|ios_base::binary                     "cmodeb"    以二进制模式读/写文件
 * --------------------------------------------------------
 * c++mode|ios_base::ate                        "cmode"     将指针放到文件尾，以指定模式打开文件
 * --------------------------------------------------------
 * 
 */ 
int main_append(){

    const char * file = "guests.txt";

    using namespace std;
    char ch;

    //打开文件，输出文件的内容
    ifstream fin;
    fin.open(file);
    if(fin.is_open()) {
        cout << "Here are the current contents of the "
            <<file << " file:\n";
        while(fin.get(ch)) {
            cout << ch;
        }
        fin.close();
    }

    //以输出流的方式打开文件，将键盘输入内容，输出到文件中
    //追加的方式将内容输出到文件中
    ofstream fout(file, ios::out|ios::app);
    if(!fout.is_open()) {
        cerr << "can't open " << file << " file for output.\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter guest names (enter a blank line to quit):\n";
    string name;
    while(getline(cin, name) && name.size() > 0) {
        fout << name << endl;
    }
    fout.close();

    //重新打开刚才的文件， 输出文件的内容
    fin.clear();
    fin.open(file);
    if(fin.is_open()){
        cout << "Here are the new contents of the " 
            << file << " file.\n";
        while(fin.get(ch)) {
            cout << ch;
        }
        fin.close();
    }

    cout << "Done.\n";
    return 0;

}