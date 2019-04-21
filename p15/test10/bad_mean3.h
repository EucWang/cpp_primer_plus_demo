#ifndef BAD_MEAN2_H_
#define BAD_MEAN2_H_

#include <stdexcept>
#include <iostream>
#include <string>

class BadHMean3 : public std::logic_error{
    private:
        double v1;
        double v2;
    public:
        explicit BadHMean3(const std::string & s):std::logic_error(s), v1(0), v2(0){}
        explicit BadHMean3(const char * c):std::logic_error(c), v1(0), v2(0){}

        BadHMean3(const char * c, double a1, double a2):std::logic_error(c), v1(a1), v2(a2){}
        BadHMean3(const std::string & s, double a1, double a2):std::logic_error(s), v1(a1), v2(a2){}
    //     BadHMean(double a=0, double b=0):v1(a),v2(b){}
    //     void msg();
    
        // const char* what() const _NOEXCEPT {
        //     return "BadHMean2 exception";
        // }

        double getV1(){ return v1;}
        double getV2(){ return v2;}
};

// inline void BadHMean::msg(){
//     std::cout << "hmean(" << v1 << ", " << v2 << "): "
//         << "invalid arguments : a = -b\n";
// };

class BadGMean3 : public std::logic_error{
    private:
        double v1;
        double v2;
    public:
        explicit BadGMean3(const std::string & s):std::logic_error(s){}
        explicit BadGMean3(const char * c):std::logic_error(c){}

        BadGMean3(const char * c, double a1, double a2):std::logic_error(c), v1(a1), v2(a2){}
        BadGMean3(const std::string & s, double a1, double a2):std::logic_error(s), v1(a1), v2(a2){}
        // BadGMean(double a=0, double b=0):v1(a),v2(b){}
        // double getV1(){return v1;}
        // double getV2(){return v2;}
        // const char * msg();
        // const char* what() const _NOEXCEPT {
        //     return "BadGMean2 exception";
        // }

        double getV1(){ return v1;}
        double getV2(){ return v2;}
};

// inline const char * BadGMean::msg(){
//     return "gmean arguments should be >= 0\n";
// }


#endif