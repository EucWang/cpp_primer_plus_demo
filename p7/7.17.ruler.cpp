#include <iostream>

const int Len = 66;
const int Divs = 6;

void subdivide(char ar[], int low, int high, int level);

int main80()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    //数据初始化
    char ruler[Len];
    int i;
    for(i = 0; i < Len - 2; i++) {
        ruler[i] = ' ';
    }
    ruler[Len - 1] = '\0';

    //第一层手动赋值， 最开始和最后一个元素赋值
    int max = Len - 2;
    int min = 0;
    ruler[min] = ruler[max] = '|';
    cout << ruler << endl;

    for(i = 1; i < Divs; i++) {
        subdivide(ruler, min , max, i);   //根据层级来递归，数组内容一次出现不同的赋值情况

        cout << ruler << endl;

        for(int j = 1; j < Len - 2; j++) { //每次递归调用之后，重置数组内容
            ruler[j] = ' ';
        }
    }

    cout<<endl;
    return 0;
}

void subdivide(char ar[], int low, int high, int level) {
    if (level == 0) return;
    int mid = (high + low) /2;
    ar[mid] = '|';
    subdivide(ar, low, mid, level - 1);
    subdivide(ar, mid, high, level - 1);
}