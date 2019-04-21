#ifndef BAD_MEAN2_H_
#define BAD_MEAN2_H_

#include <stdexcept>
#include <iostream>
#include <string>

class BadHMean2 : public std::logic_error{
    // private:
    //     double v1;
    //     double v2;
    public:
        explicit BadHMean2(const std::string & s):std::logic_error(s){}
        explicit BadHMean2(const char * c):std::logic_error(c){}
    //     BadHMean(double a=0, double b=0):v1(a),v2(b){}
    //     void msg();
    
        // const char* what() const _NOEXCEPT {
        //     return "BadHMean2 exception";
        // }
};

// inline void BadHMean::msg(){
//     std::cout << "hmean(" << v1 << ", " << v2 << "): "
//         << "invalid arguments : a = -b\n";
// };

class BadGMean2 : public std::logic_error{
    // private:
    //     double v1;
    //     double v2;
    public:
        explicit BadGMean2(const std::string & s):std::logic_error(s){}
        explicit BadGMean2(const char * c):std::logic_error(c){}
        // BadGMean(double a=0, double b=0):v1(a),v2(b){}
        // double getV1(){return v1;}
        // double getV2(){return v2;}
        // const char * msg();
        // const char* what() const _NOEXCEPT {
        //     return "BadGMean2 exception";
        // }
};

// inline const char * BadGMean::msg(){
//     return "gmean arguments should be >= 0\n";
// }


#endif