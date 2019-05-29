#ifndef SALES_H
#define SALES_H

namespace SALES{

    // const int QUARTERS = 4;
    // struct Sales{
    //     double sales[QUARTERS];
    //     double average;
    //     double max;
    //     double min;
    // };

    // void setSales(Sales & s);

    // void setSales(Sales & s, const double ar[], int n);

    // void showSales(Sales & s);

    class Sales{
        private:
            static const int QUARTERS = 4;
            double sales[QUARTERS];
            double average;
            double max;
            double min;
        public:
            void setSales();
            void setSales(const double ar[], int n);
            void showSales();

    };

}

#endif