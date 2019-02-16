#include <iostream>

struct antarctica_years_end
{
    int year;
};

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;
    
    antarctica_years_end s01, s02, s03;

    s01.year = 1998;

    antarctica_years_end * pa = &s02;  //结构指针
    pa->year = 1999;

    antarctica_years_end trio[3];  // 结构数组
    trio[0].year = 2003;
    cout << trio->year << endl;

    const antarctica_years_end * arp[3] = {&s01, &s02, &s03}; //结构指针数组
    cout << arp[1]->year << endl;

    //指向 结构指针数组 的指针
    // 由于ppa指向arp的第一个元素， 所以 *ppa 为
    const antarctica_years_end ** ppa = arp; 
    auto ppb =arp;  //使用auto 自动推断类型

    cout << (*ppa)->year << endl;
    cout << (*(ppb+1))->year << endl;

    cout<<endl;
    return 0;
}
