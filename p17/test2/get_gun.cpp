#include <iostream>


/**
 * 17.13 
 * 
 * use get() getline() input string
 * 
 * istream & get(char *, int, char);
 * istream & get(char *, int);
 * 
 *      get() 和getline()主要区别在于，get 将换行符留在输入流中，这样接下来输入操作首先看到的是换行符，
 *                                  而getline  抽取并丢弃输入流中的换行符
 *      都有三个参数的版本，第三个参数用于指定分界符，遇到分界字符后，输入将定制，即使没有读取到最大数目字符。
 * 
 * istream & getline(char *, int, char);
 * istream & getline(char *, int);
 * 
 * istream & ignore(int = 1, int = EOF); //第一个参数表示最大字符数， 另一个是作为输入分界符
 * 
 * 
 * 输入行为导致的字节流异常情况
 * ------------------------------------------------------------------------------------
 * getline(char *, int);    如果没有读取任何字符，则设置failbit
 *                          如果读取了最大数目的字符，且行中还有其他字符，则设置failbit
 * ------------------------------------------------------------------------------------
 * get(char *, int);       如果没有读取任何字符，则设置failbit
 * ------------------------------------------------------------------------------------
 */ 
int main_get_gun(){
    const int LIMIT = 255;
    using namespace std;

    char input[LIMIT];
    cout << "Enter a string for getline() processing:\n";
    cin.getline(input, LIMIT, '#');
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 1\n";
    cout << "--------\n";

    char ch;
    cin.get(ch);
    cout << "The next input character is " << ch << endl;

    if(ch != '\n') {
        cin.ignore(LIMIT, '\n');
    }

    cout << "Enter a string fro get() processing:\n";
    cin.get(input, LIMIT, '#');
    cout << "Here is your input:\n";
    cout << input << "\nDone with phase 2\n";

    cin.get(ch);
    cout << "The next input character is " << ch << endl;

    return 0;
}