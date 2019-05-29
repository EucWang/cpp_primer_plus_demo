#include <iostream>
#include <exception>


/**
 * 17.12 
 * having cin throw an exception
 * 
 * cin或cout对象包含一个描述流状态的数据成员（iostate 类型，一种bitmask类型）
 * 流状态有3个ios_base元素组成：eofbit, badbit, failbit， 每个元素都是一位，1（设置），0（正常）
 * cin操作到文件尾时， eofbit 设置1；
 * cin未能读取到预期字符时，将设置failbit或者badbit
 * io失败时，也可能设置failbit
 * 其他一些失败导致破坏流时，会设置badbit
 * 
 * 流状态：
 * 
 * good()   正常，则返回true
 * eof()    是否eofbit被设置
 * bad()    是否设置 badbit
 * fail()   是否设置 failbit
 * rdstate()   返回流状态
 * 
 * exceptions()   返回一个位掩码，指出哪些标记位导致异常被引发
 * exceptions(iosstate ex) 设置哪些状态将导致clear()引发异常， 例如ex是eofbit,则如果eofbit被设置，clear()将引发异常
 * 
 * clear(iostate s)   将流状态设置为s， s的默认值为0，如果 (restate() & exception()) != 0, 则引发异常
 * setstate(iostate s)  调用clear(rdstate()|s), 这将设置与s中设置的位对应的流状态位，其他流状态位不变
 * 
 * 
 * clear() ; 无参数是默认值为0，将清除3个状态位，有参数时，参数指定位被设置，其他两个状态位被清除
 * setstate() ； 无默认值，只影响其参数中已经被设置的位。
 * 
 */ 
int main_cinexcp(){

    using namespace std;

    //重载的exceptions(iostate)函数使得能够控制其行为
    //下面的语句，将导致如果流状态有被设置，则引发异常 ios_base::failure， 
    //  ios_base::failure 从std::exception派生而来
    cin.exceptions(ios_base::failbit|ios_base::eofbit|ios_base::badbit);

    cout << "Enter number: ";
    int sum = 0;
    int input;
    try{
        while(cin>>input){
            cout << "rdstate()" << cin.rdstate() << endl;
            cout << "eof():" << cin.eof() << endl;
            cout << "bad():" << cin.bad() << endl;
            cout << "fail():" << cin.fail() << endl;
            cout << "input is :" << input << "\n----------" << endl;
            sum += input;
        }
    }catch(ios_base::failure & bf) {
        cout << bf.what() << endl;

        cout << "rdstate()" << cin.rdstate() << endl;
        cout << "eof():" << cin.eof() << endl;
        cout << "bad():" << cin.bad() << endl;
        cout << "fail():" << cin.fail() << endl;
        cout << "O! the horror!\n";


        //读取出错之后， 
        //如果是由于到达文件尾或者由于硬件故障导致，则无需处理错误输入，直接结束
        //如果后续还需要读取输入
        //首先清除标志位
        //然后消费掉所有输入内容，直到遇到换行符为止
        if(cin.fail() && !cin.eof()) {
            cin.clear();
            // while(cin.get() != '\n') {  
            while(!isspace(cin.get())) {  
                continue;
            }
        } else {
            cout << "I cannot go on!\n";
            exit(1);
        }

        cout << "\nafter clear()\n";
        cout << "rdstate()" << cin.rdstate() << endl;
        cout << "eof():" << cin.eof() << endl;
        cout << "bad():" << cin.bad() << endl;
        cout << "fail():" << cin.fail() << endl;
    }

    cout << "Last value entered :" << input << endl;
    cout << "Sum = " << sum << endl;

    return 0;
}