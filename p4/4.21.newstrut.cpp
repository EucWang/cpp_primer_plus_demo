#include <iostream>

struct inflatable {
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    inflatable * ps = new inflatable;

    cout << "Please enter name of inflatable item: ";
    cin.get(ps->name, 20);

    cout << "Enter volume in cubic feet: ";
    // 如果结构标示符是结构名，则可以使用 句点 来访问结构成员
    // 如果 标识符 是指针， 则 只能使用 -> 来访问结构成员
    // 如果 ps是只想结构的指针，那么(*ps) 就是被指向的值， 也就是结构本身
    cin >> (*ps).volume;    

    cout << "Enter price: $";
    cin >> ps->price;

    cout << "Name : " << (*ps).name << endl;
    cout << "Volume : " << ps->volume << endl;
    cout << "Price : " << ps->price << endl;

    
    cout<<endl;
    return 0;
}
