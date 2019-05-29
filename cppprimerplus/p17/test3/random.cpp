#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>

inline void eatline() {while(std::cin.get() != '\n')continue;}
/**
 * 17.20 random.cpp random access to a binary file
 * 
 * 同时读写对象
 * fstream
 *
 * 类型： 
 * streampos  位置
 * 
 * 方法：
 * seekg();   //定位输入流的位置
 *      
 *  
 * setp();    //定位输出流的位置
 * 
 */ 
int main_random(){
    const int LIM = 20;
    const char * file = "planets.dat";
    using namespace std;

    struct planet {
        char name[LIM];
        double population;
        double g;
    };

    fstream finout;
    finout.open(file, ios_base::in | ios_base::out | ios_base::binary);

    planet pl;
    int ct = 0;
    if(finout.is_open()) {
        finout.seekg(0); // input buffer to begin
        cout << "Here are the current contents of the " 
            << file << " file.\n";
        while( finout.read((char *)&pl, sizeof pl)) {
            cout << ct++ << ": " << setw(LIM) << pl.name << ": "
                << setprecision(0) << setw(12) << pl.population
                << setprecision(2) << setw(6) << pl.g << endl;
        }
        if(finout.eof()) {
            finout.clear(); //结束，清空流
        } else {
            cerr << "Error in reading " << file << ".\n";
            exit(EXIT_FAILURE);
        }
    } else {
            cerr << "Could not be opened -- bye.\n";
            exit(EXIT_FAILURE);
    }


    cout << "Enter the record number you wish ot change: ";
    long rec;
    cin >> rec;
    eatline();
    if(rec < 0 || rec >= ct) {
        cerr<< "INvalid record number -- bye.\n";
        exit(EXIT_FAILURE);
    }

    streampos place = rec * (sizeof pl);
    finout.seekg(place);  //跳转到指定位置去读取数据
    if(finout.fail()) {
        cerr << "Error on attempted seek\n";
        exit(EXIT_FAILURE);
    }

    finout.read((char *) &pl, sizeof pl);
    cout << "Your selection : \n";
    cout << rec << ": " << setw(LIM) << pl.name << ": "
        << setprecision(0) << setw(12) << pl.population
        << setprecision(2) << setw(6) << pl.g << endl;

    if(finout.eof()) {
        finout.clear();
    }

    //将刚才显示的planet数据覆盖掉
    cout << "Enter planet name : ";
    cin.get(pl.name, LIM);
    eatline();
    cout << "Enter planetary population: ";
    cin >> pl.population;
    cout << "Enter planet's acceleration of gravity: ";
    cin >> pl.g;
    finout.seekp(place);   //定位输出流的位置
    finout.write((char * )&pl, sizeof pl) << flush;  //写入数据，并刷新缓冲区
    if(finout.fail()) {
        cerr << "Error on attempted write.\n";
        exit(EXIT_FAILURE);
    }

    //显示刚才的新的数据
    ct = 0;
    finout.seekg(0);
    cout << "Here are the new contents of the " << file
        << " file.\n";
    while(finout.read((char *)&pl, sizeof(pl))){
        cout << ct++ << ": " << setw(LIM) << pl.name << ": "
            << setprecision(0) << setw(12) << pl.population
            << setprecision(2) << setw(6) << pl.g << endl;
    }

    finout.close();
    cout << "Done.\n";
    return 0;
}