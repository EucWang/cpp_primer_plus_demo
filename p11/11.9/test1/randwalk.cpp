#include <iostream>
#include <fstream>
#include <cstdlib> //rand(), srand() 
#include <ctime> //time()
#include "vector.h"

using namespace std;
using namespace VECTOR;

int main()
{
    srand(time(0));  //随机种子，根据时间
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;  //统计步数
    double target;
    double dstep;

   

    cout << "Enter target distance(q to quit):";
    while(cin >> target) {
        //输入每一步的移动距离，
        cout << "Enter step length:";
        if(!(cin >> dstep)) {  
            break;
        }
        
        ofstream outFile;
        outFile.open("randwalk.txt");
        outFile << "Target Distance : " << target 
                << ", Step Size : " << dstep << endl;

        //将方向随机的矢量相加， 如果最终距离超过result，则循环结束
        while(result.magval() < target) {
            direction = rand() % 360;
            step.reset(dstep, direction, POL);

            step.rect_mode();
            outFile << steps << ": " << step;

            result = result + step;
            steps++; 
        }

        outFile << "After " << steps 
            << " steps, the subject has the following location:\n"
            <<  result << "or\n";
        result.polar_mode();
        outFile << result;

        outFile.close();
        

        //两种模式输出result的数据
        cout << "After " << steps << " steps, the subject "
            "has the following location.\n";
        cout << result;
        result.polar_mode();
        cout << "or\n" << result;

        //获得每一次移动平均的移动距离，距离目标
        cout << "Average outward distance per step = "
            << result.magval() / steps << endl;
        //置空数据，开始下一次的输入
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit):";
    }

    cout << "Bye!" << endl;
    cin.clear();
    while(cin.get() != '\n') {
        continue;
    }
    return 0;

    return 0;
}
