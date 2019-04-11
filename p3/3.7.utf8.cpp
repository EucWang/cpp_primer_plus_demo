#include <iostream>
#include <iomanip>

using namespace std;

int main156()
{
    const char* uTest = u8"你好";
    cout << uTest << endl;

    for(int i=0; uTest[i] != 0; i++)
    {
        cout << setiosflags(ios::uppercase) << hex << (uint32_t)(uint8_t)uTest[i] << " ";
    }
    cout << endl;
    return 0;
}

//编译选项： g++ -std=c++0x -finput-charset=utf-8 3.7.utf8.cpp -o 3.7.utf8