#include <iostream>
#include <fstream>
#include <cstdlib>

int main82()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    ifstream inFile;
    inFile.open("carinfo.txt");
    if(!inFile.is_open()){
        cout << "open file error, exit" << endl;
        exit(EXIT_FAILURE);
    }

    char tmp;
    int count;
    inFile.get(tmp);
    while(inFile.good()){
        count++;
        // inFile >> tmp;
        inFile.get(tmp);
    }
    
    if (inFile.eof()) { //到达文件结尾
		cout << "End of file reached.\n";
	} else if(inFile.fail()) { //数据类型读取错误
		cout << "Input terminatd by data mismatch.\n";
	} else { //其他原因
		cout << "Input terminated for unknown reason.\n";
	}

    cout << count << " character in this file.\n";
    
    cout<<endl;
    return 0;
}
