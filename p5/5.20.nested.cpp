#include <iostream>

const int Cities = 5;
const int Years = 4;

int main()
{
    using namespace std;
    cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    //字符串数组指针， 指针数组存储5个字符串的地址
    const char * cities[Cities] = {
        "Gribble City",
        "Gribbletown",
        "New Gribble",
        "San Gribble",
        "Gribble Vista"
    };
    //char数组的数组，将5个字符串分别复制到5个大小相同的char数组中
    // char cities[Cities][25] = {
    //     "Gribble City",
    //     "Gribbletown",
    //     "New Gribble",
    //     "San Gribble",
    //     "Gribble Vista"
    // };

    int maxtemps[Years][Cities] = 
    {
        {95, 100, 87, 101, 105},
        {96, 98, 91, 107, 104},
        {97, 101, 93, 108, 107},
        {98, 103, 95, 109, 108}
    };

    cout << "Maximum temperatures for 2008 -2011\n\n";
    for(int city = 0; city < Cities; city++)
    {
        cout << cities[city] << ":\t";
        for(int year = 0; year < Years; year++)
        {
            cout << maxtemps[year][city] << "\t";
        }
        cout << endl;
    }

    cout<<endl;
    return 0;
}
