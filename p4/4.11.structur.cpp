#include <iostream>

/**
 * 结构
 * 
 * struct关键字
 * 
 * 1.声明位置： 可以再函数中声明， 也可以在函数外声明
 * 2. 结构也支持列表初始化
 * inflatable duck {"Daphne", 0.12, 9.98};
 * 3. 结构可以将string作为成员,必须结构体可以访问std：string
 * #include <string>  
 * struct inflatable
 * {
 *  std:string name;
 *  float valume;
 *  double price;
 * }
 * 4. 结构可以作为参数传递给函数，也可以作为函数的返回值
 */ 

struct inflatable
{
    char name[20];
    float volume;
    double price;
};

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    inflatable guest = 
    {
        "Glorious Gloria",
        1.88,
        29.99
    };

    inflatable pal = 
    {
        "Audacious Arthur",
        3.12,
        32.99
    };

    cout << "Expand your guest list with " << guest.name
         << " and " << pal.name << "!\n";
    cout << "You can have both for $";
    cout << guest.price + pal.price << endl;

    cout<<endl;
    return 0;
}