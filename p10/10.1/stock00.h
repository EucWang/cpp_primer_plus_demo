#ifndef STOCK00_H_
#define STOCK00_H_

#include <string>
// using namespace std;

class Stock{

    private:
        std::string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot() {total_val = shares * share_val;}   //类声明中定义的函数自动成为内联函数
    public:
        Stock();
        ~Stock();
        Stock(const std::string & co, long n=0, double pr=0.0);

        void acquire(const std::string & co, long n, double pr);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);

        /**
         * const放置在函数名称后面，表示函数的调用能保证调用对象不会被修改，调用对象和const一样，不被修改。
         */ 
        void show() const;

        const Stock & topval(const Stock & s) const;

        double getTotalVal() const;
};

#endif