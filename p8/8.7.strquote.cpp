#include <iostream>
#include <string>

using namespace std;

string version1(const string& s1, const string& s2);

const string& version2(string& s1, const string& s2);

const string& version3(string& s1, const string& s2);


int main()
{
    //cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    string input;
    string copy;
    string result;

    cout << "Enter a string: ";
    getline(cin, input);
    copy = input;
    cout << "Your string as entered : " << input << endl;
    result = version1(input, "***");
    cout << "Your string enhanced: "<< result << endl;
    cout << "Your original string : " << input << endl;

    result = version2(input, "###");
    cout << "Your string enhanced: " << result << endl;
    cout << "Your original string : " << input << endl;

    cout << "Resetting original string.\n";
    input = copy;  //恢复原始数据
    result = version3(input , "@@@");
    cout << "Your string enhanced : " << result << endl;
    cout << "Your original string : " << input << endl;

    cout<<endl;
    return 0;
}

string version1(const string& s1, const string& s2){
    string temp;
    temp = s2 + s1 + s2;
    return temp; //temp只在version1中有效，该函数执行完之后就不存在了
    //返回string，意味着temp的内容会被复制到一个临时存储单元中，然后在main（）
    //中，该存储单元的内容会复制到一个名为result的string中。
}

const string& version2(string& s1, const string& s2) {
    s1 = s2 + s1 + s2;
    return s1;
}

const string& version3(string& s1, const string& s2) {
    string temp;
    temp = s2 + s1 + s2;
    return temp; //返回本地变量，这是不安全的返回方式
}