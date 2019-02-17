#include <iostream>
#include <fstream>
#include <cstdlib>  // 支持 exit()方法

const int SIZE = 60;
/**
 * 文件输入
 * 必须包含头文件fstream
 * 头文件fstream定义了一个用于处理输入的ifstream类
 * 需要声明 ifstream对象
 * 必须指明名称空间 std
 * 
 * 需要将ifstream对象和文件进行关联，使用open()方法
 * 使用完文件之后，close()方法关闭文件
 * 
 * 所有可用于cin的操作和方法都可以用于ifstream对象,例如：
 * >> 读取各种类型的数据， get()读取一个字符,getline()读取一行字符
 * eof(), fail()判断输入是否成功
 * 
 * 检查文件是否打开成功 is_open()方法来检测
 * inFile.open("bowling.txt");
 * if(!inFile.is_open()) exit(EXIT_FAILURE);
 * 
 * 
 * open()
 * is_open()
 * close()
 * good()方法，检测读取数据是否正常
 * eof()方法， 判断是否到达文件结尾
 * fail()方法， 读取文件数据类型错误
 * 
 * exit(EXIT_FAILURE) 退出程序, 需要导入<cstdlib>库
 */ 
int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char filename[SIZE];
    ifstream inFile;

    cout << "Enter name of data file: ";
    cin.getline(filename, SIZE);
    inFile.open(filename);
    if(!inFile.is_open()) {
        cout << "Could not open the file " << filename << endl;
        cout << "Program terminating.\n";
        exit(EXIT_FAILURE);   //退出程序
    }

    double value;
    double sum = 0.0;
    int count = 0;

    inFile >> value;
    while(inFile.good()){   //从文件读取内容是否正确
        ++count;
        sum += value;
        inFile >> value;
    }
    
    if (inFile.eof()) {   //到达文件结尾
        cout << "End of file reached.\n";
    } else if(inFile.fail()) {   //数据类型读取错误
        cout << "Input terminatd by data mismatch.\n";
    } else {    //其他原因
        cout << "Input terminated for unknown reason.\n";
    }

    if (count == 0) {
        cout << "No data processed.\n";
    }else {
        cout << "Items read : " << count << endl;
        cout << "Sum : " << sum << endl;
        cout << "Average : " << (sum/count) << endl;
    }
    inFile.close();    //关闭文件
    cout<<endl;
    return 0;
}
