#include <iostream>

/**
 * 彩票中奖概率计算
 * 例如： 从47个数字中选择5个。彩票管理员随机抽取6个，参与者选择的数和彩票管理员的相同则中奖。
 * 例如51选6，计算公式：
 * 获奖概率 ： 1/R
 * R = 51 * 50 * 49 * 48 * 47 * 46 / (6 * 5 * 4 * 3 * 2 * 1)
 * 
 */ 
long double probability(unsigned numbers, unsigned picks, unsigned second_field);

int main36(){
    using namespace std;
    // cout.setf(ios_base::fixed, ios_base::floatfield);
    cout<<endl;

    double total, choices, second_field;
    cout << "Enter the total number of choices on the game card and" << endl   
        << "the number of picks allowed and " << endl
        << "the second field number of choices to pick one" << endl;

    while( (cin >> total >> choices >> second_field) && choices <= total){
        cout << "You have one chane in ";
        cout << probability(total, choices, second_field);
        cout << " of winning.\n";
        cout << "Next three numbers (q to quit): ";
    }
    cout << "Bye";
    cout<<endl;
    return 0;
}

long double probability(unsigned numbers, unsigned picks, unsigned second_field) {
    long double result = 1.0;
    long double n;
    unsigned p;

    for(n = numbers, p = picks; p > 0 ; n--, p--) {
        result = result * n / p;
    }
    return result * second_field;
}