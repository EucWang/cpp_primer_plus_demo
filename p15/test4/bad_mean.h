#ifndef BAD_MEAN_H_
#define BAD_MEAN_H_

#include <iostream>

class BadHMean{
    private:
        double v1;
        double v2;
    public:
        BadHMean(double a=0, double b=0):v1(a),v2(b){}
        void msg();
};

inline void BadHMean::msg(){
    std::cout << "hmean(" << v1 << ", " << v2 << "): "
        << "invalid arguments : a = -b\n";
};

class BadGMean{
    private:
        double v1;
        double v2;
    public:
        BadGMean(double a=0, double b=0):v1(a),v2(b){}
        double getV1(){return v1;}
        double getV2(){return v2;}
        const char * msg();
};

inline const char * BadGMean::msg(){
    return "gmean arguments should be >= 0\n";
}


#endif