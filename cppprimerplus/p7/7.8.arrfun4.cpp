#include <iostream>

const int ArSize = 8;

int sum_arr(const int * begin, const int * end);

/**
 * 指针和const
 * 
 * 可以用两种不同的方式将const关键字用于指针
 * 1. 让指针指向一个常量对象
 *      int age = 39;
 *      const int * pt = &age; 
 *   
 *      pt指向一个const int,因此不能使用pt来修改这个值，虽然age本身不是const的，可以直接通过age来修改这个地址的值
 * 
 *      可以将const变量的地址赋值给指向const的指针，但是不能将const变量的地址赋值给常规的指针。
 *      如果非要将const变量的地址赋值给非const的指针，那么可以使用强制类型转换来突破这种限制。
 *      
 *      二级指针的情况更复杂些，
 *      const int **p2;   //const的二级指针
 *      int *p1;            //非const的一级指针
 *      const int n = 13;   //const的变量
 *      p2 = &p1;           //关联二级指针和一级指针，
 *      *p2 = &n;           //把const变量的地址赋值给 const的二级指针的一级指针
 *      *p1 = 10;           //这几就可以通过非const的一级指针去修改const的变量了
 *
 *      如果函数参数声明为非const的， 数组时const修饰的常量数组，那么将数组名传递给函数时，编译器会禁止这样的函数调用
 *  
 * 2. 将指针本身声明为一个常量
 *      int sloth = 3;
 *      int * const finger = &sloth;  //指针是const修饰的，就是说指针只能指向sloth，但是允许通过指针修改sloth的值
 *      *finger = 4;
 * 
 * 3. 如果愿意，可以申明指向const对象的const指针：  
 *      double troble = 2.0E30;
 *      const double * const stick = &troble;  //stick 和 *stick都是const的了
 */ 

int main92()
{
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    int cookies[ArSize] = {1,2,4,8,16,32,64,128};
    int sum = sum_arr(cookies, cookies + ArSize);
    cout << "Total cookies eaten : " << sum << endl;
    sum = sum_arr(cookies, cookies + 3);
    cout << "First three eaters ate " << sum << " cookies.\n";
    sum = sum_arr(cookies + 4, cookies + ArSize);
    cout << "Last four eaters ate " << sum << " cookies.\n";
    
    cout<<endl;
    return 0;
}

/**
 * 通过前后指针来确定数组取值区间
 */ 
int sum_arr(const int * begin, const int * end) {
    const int * pt;
    int total = 0;
    for(pt = begin; pt != end; pt++)    {
        total += *pt;
    }
    return total;
    
}
