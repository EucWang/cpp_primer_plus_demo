#include <iostream>
#include <fstream>

/**
 * 文件输出
 * 必须包含头文件fstream
 * 头文件fstream定义了一个用于处理输出的ofstream类
 * 需要声明一个或者多个ofstream对象，
 * 必须使用名称空间std，
 * 需要将ofstream对象和文件关联起来，使用open()方法
 * 使用完文件之后，close()关闭文件。
 * 可以结合使用ofstream对象和运算符<<来输出各种类型的数据
 * 所有可以用于cout的操作和方法(<<, endl setf()) 都可以用于ofstream对象
 * 
 */ 

int main177()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    char automobile[50];
    int year;
    double a_price;
    double b_price;

    cout << "Enter the make and model of automobile : ";
    cin.getline(automobile, 50);
    cout << "Enter the model year: ";
    cin >> year;
    cout << "Enter the original asking price: ";
    cin >> a_price;
    b_price = 0.913 * a_price;

    //在控制台输出信息
    cout << fixed;
    cout.precision(2);
    cout.setf(ios_base::showpoint);
    cout << "Make and model : " << automobile << endl;
    cout << "Year: " << year << endl;
    cout << "Was asking $" << a_price << endl;
    cout << "Now asking $" << b_price << endl;

    //输出信息到文件中
    ofstream outFile;
    outFile.open("carinfo.txt");  //如果文件存在，清空文件内容，如果文件不存在，创建文件
    outFile << fixed;
    outFile.precision(2);   //浮点数显示2位小数部分
    outFile.setf(ios_base::showpoint);
    outFile << "Make and model : " << automobile << endl;
    outFile << "Year: " << year << endl;
    outFile << "Was asking $" << a_price << endl;
    outFile << "Now asking $" << b_price << endl;
    outFile.close();
    
    cout<<endl;
    return 0;
}
