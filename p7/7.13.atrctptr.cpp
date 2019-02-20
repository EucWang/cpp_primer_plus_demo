#include <iostream>
#include <cmath>
/**
 * 较早的g++版本需要使用下面的命令才能正确的搜素数学库
 *  g++ structfun.c -lm
 */ 

struct rect{
    double x;
    double y;
};

struct polar{
    double distance;
    double angle;
};

void show_polar(const polar * dapos) {
    using namespace std;
    const double Rad_to_deg = 57.29577951;   // 弧度转换成角度需要乘以 （180/PI），这个值就是。

    cout << "distance = " << dapos->distance;
    cout << ", angle = " << dapos->angle * Rad_to_deg;
    cout << " degress\n";
}

/**
 * 将直角坐标转换成极坐标
 * 这里需要将返回的数据的指针也传递给函数，则函数就不需要返回一个新的数据结构了
 */ 
void rect_to_polar(/*in*/const rect * xypos, /*out*/polar * pda) {
    // polar result;
    pda->distance = sqrt(xypos->x * xypos->x + xypos->y * xypos->y);
    pda->angle = atan2(xypos->y, xypos->x);
    // return result;
}

int main()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    rect rplace;
    polar pplace;

    cout << "Enter the x and y values : ";
    while(cin >> rplace.x >> rplace.y) {
        // pplace = rect_to_polar(&rplace);
        rect_to_polar(&rplace, &pplace);
        show_polar(&pplace);
        cout << "Next two numbers (q to quit) : ";
    }
    cout << "Done !\n";
    cout<<endl;
    return 0;
}
