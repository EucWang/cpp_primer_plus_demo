#include <iostream>
#include <cstring>

int main11()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    char animal[20] = "bear";  //将字符串存储到数组中，直接使用 “=” 即可

    //字符串字面值是常量
    //使用const修复指针，表示可以用指针访问字符串，但是不能修改它
    // 因此， 不能将 bird指针作为cin 输入的目标
    const char * bird = "wren";

    char * ps;

    cout << animal << " and " << bird << ".\n";

    cout << "Eenter a kind of animal : " << endl;

    //请不要使用字符串常量，或者未被初始化的指针来接收输入
    cin >> animal;
    ps = animal;
    cout << ps << ".\n";

    cout << "Before use strcpy():\n";
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;

    //复制字符串， 首先需要创建新的空间， 然后将字符串内容复制一份到这个新的空间，比如这里的数组
    ps = new char[strlen(animal) + 1];
    // strcpy(), 复制字符串， 第一个参数是目标地址， 第二个参数是要复制的字符串的地址
    strcpy(ps, animal);

    cout << "After use strcpy():\n";

    //如果给cout提供一个指针，默认将打印地址
    //如果指针的类型是char *， 则cout将显示指向的字符串
    //如果需要显示字符串的地址，则需要强制转换(int *)
    cout << animal << " at " << (int *)animal << endl;
    cout << ps << " at " << (int *)ps << endl;

    delete ps;

    cout<<endl;
    return 0;
}
