#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>


/**
 * 使用get() ，getline() 方法读取字符串时， 这个eatline()方法就很有必要了
 */ 
inline void eatline(){while(std::cin.get() != '\n')continue;}

struct planet{
    char name[20];
    double population;
    double g;
};

/**
 * 17.19 
 * binary.cpp
 * binary file i/o
 * 
 * 读写二进制文件
 * read()
 * write()
 * 
 */ 
int main_binary(){
    const char * file = "planets.dat";

    using namespace std;

    planet pl;
    cout << fixed << right;  //右对齐，固定

    ifstream fin;
    fin.open(file, ios_base::in | ios_base::binary); //二进制形式读取内容
    if(fin.is_open()) {
        cout << "Here are the current contents of the " 
            << file << " file.\n";
        while(fin.read((char *) &pl, sizeof pl)){  //读取planet大小的一坨数据，保存到pl中，记得pl地址要强转
            //注意输出格式
            cout << setw(20) << pl.name << ": "    //
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }
        fin.close();
    }

    //追加形式， 二进制， 写出流
    ofstream fout(file, ios_base::out | ios_base::app | ios_base::binary);
    if(!fout.is_open()) {
        cerr << "can't open " << file << " file for output:\n";
        exit(EXIT_FAILURE);
    }

    cout << "Enter planet name (enter a blank line to quit):\n";
    cin.get(pl.name, 20);
    while(pl.name[0] != '\0') {
        eatline();
        cout << "Enter planetary population: ";
        cin >> pl.population;
        cout << "Enter planet's acceleration of gravity: ";
        cin >> pl.g;
        eatline();

        //将键盘输入的数据写入到文件流中
        fout.write((char *)&pl, sizeof pl);
        cout << "Enter planet name (enter a blank line to quit):\n";
        cin.get(pl.name, 20);
    }
    fout.close();


    fin.clear();
    fin.open(file, ios_base::in | ios_base::binary);
    if(fin.is_open()) {
        cout << "Here are the new contents of the " 
            << file << " file:\n";
            while(fin.read((char *) &pl, sizeof pl)) {
                cout << setw(20) << pl.name <<": "
                    << setprecision(0) << setw(12) << pl.population
                    << setprecision(2) << setw(6) << pl.g << endl;
            }        
            fin.close();
    }

    cout << "Done!\n";
    return 0;
}