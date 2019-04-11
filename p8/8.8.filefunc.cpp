#include <iostream>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

const int LIMIT = 5;

/**
 * 参数os可以指向ostream对象， 也可以指向ofstream对象。
 */  
void file_it(ostream& os, double fo, const double fe[], int n);

/**
 *  ios::left 输出数据在本域宽范围内左对齐 
    ios::right 输出数据在本域宽范围内右对齐 
    ios::internal 数值的符号位在域宽内左对齐,数值右对齐,中间由填充字符填充 
    ios::dec 设置整数的基数为10 
    ios::oct 设置整数的基数为8 
    ios::hex 设置整数的基数为16 
    ios::showbase 强制输出整数的基数(八进制以0打头,十六进制以0x打头) 
    ios::showpoint 强制输出浮点数的小点和尾数0 
    ios::uppercase 在以科学计数法输出E和十六进制输出字母X时,以大写表示 
    ios::showpos 输出正数时,给出“+”号.
    ios::scientific 设置浮点数以科学计数法(即指数形式)显示 
    ios::fixed 设置浮点数以固定的小数位数显示 
    ios::unitbuf 每次输出后刷新所有流 
    ios::stdio 每次输出后清除stdout,stderr 
 * 
 * 
 *  用流对象的成员控制输出格式
    流成员函数 与之作用相同的控制符 作用 
    precision(n) setprecision(n) 设置实数的精度为n位.
    width(n) setw(n) 设置字段宽度为n位.
    fill(c) setfill(c) 设置填充字符c.
    setf( ) setiosflags( ) 设置输出格式状态,括号中应给出格式状态,内容与控制符setiosflags括号中内容相同.
    ubsetf( ) resetiosflags( ) 终止已设置的输出格式状态.
    cout.width(10); 
    cout.setf(ios::hex);
 * 
 */ 

int main239()
{
    // 避免使用科学计数法显示数据
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    // cout<<endl;
    
    ofstream fout;
    const char * fn = "ep-data.txt";
    fout.open(fn);
    if(!fout.is_open()){
        cout <<"Can't open " << fn << ". Bye" << endl;
        exit(EXIT_FAILURE);
    }

    double objective;
    cout << "Enter the focal length of your "
        << "telescope objective in mm: ";
    cin >> objective;
    double eps[LIMIT];
    cout << "Enter the focal lengths, in mm, of " << LIMIT
        << " eyepieces:\n";
    
    for(int i=0; i<LIMIT; i++) {
        cout << "Eyepiece #" << i + 1 << ": ";
        cin >> eps[i];
    }

    file_it(fout, objective, eps, LIMIT);
    file_it(cout, objective, eps, LIMIT);
    cout << "Done\n";

    return 0;
}

void file_it(ostream& os, double fo, const double fe[], int n) {
    ios_base::fmtflags initial;
    initial = os.setf(ios_base::fixed);  //save initial formatting state

    os.precision(0);  //表示小数位数,这里显示0位小数
    os << "Focal length of objective : "<< fo << " mm\n";
    os.setf(ios::showpoint);  
    os.precision(1);
    os.width(12);
    os << "f.1. eyepiece";
    os.width(15);
    os << "magnification" << endl;
    for(int i=0; i<n; i++) {
        os.width(12);
        os << fe[i];
        os.width(15);
        os << int(fo/fe[i] + 0.5) << endl;
    }
    os.setf(initial);
}