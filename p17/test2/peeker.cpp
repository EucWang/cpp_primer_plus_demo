#include <iostream>


/**
 * 17.4 some istream methods
 * 
 * istream 其他的方法有
 * read()   读取指定数目的字节，并存储在指定的位置中， 例如：
 *          char gross[144];
 *          cin.read(gross, 144);  //与getline(), get()不同的是，read不会在输入后加上空值字符，
 *                             read()通常与ostream write()函数结合使用，完成文件的输入输出。
 * peek()       返回输入流中的下一个字符，但是不抽取输入流中的该字符。
 *              可以结合cin.get(char *, int）来使用，get()方法会将换行符保留在输入队列中，而getline(char*,int)不会
 *              可以测试输入流中的字符是否是换行符，从而知道是否由于输入字符过多引起的终止读取。
 * gcount()     返回最后一个非格式化抽取方法读取的字符数。
 *              即get(), getline(), ignore(), read()读取的字符数，而不是由运算符>> 读取的，运算符会对输入进行格式化，使之与特定的数据类型匹配。
 * putback()    将一个字符插入到输入字符串的输入流中，
 *              被插入的字符将是下一条输入语句读取的第一个字符
 * 
 */ 
int main_peeker(){
    using namespace std;

    char ch;
    while(cin.get(ch)) {
        if(ch != '#') {
            cout << ch;
        } else {
            cin.putback(ch); //读取流，然后又放回输入流中
            break;
        }
    }

    if(!cin.eof()) {
        cin.get(ch);
        cout << endl << "------------\n'" <<  ch << "' is next input character.\n-----------------\n";
    } else {
        cout << "End of file reached.\n";
        std::exit(0);
    }

    while(cin.peek() != '#') {
        cin.get(ch);
        cout << ch;
    }

    if(!cin.eof()) {
        cin.get(ch);
        cout << endl << "------------\n'" << ch << "' is next input character.\n-----------------\n";
    } else {
        cout << "End of file reached.\n";
    }

    cout << "lest part of istream :\n";
    while(cin.get(ch) && ch != '\n') {
        cout << ch;
    }

    cout << "\nDone." << endl;

    return 0;
}