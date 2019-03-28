#ifndef DMA_H_
#define DMA_H_

#include <iostream>

//================BaseDMA===================

class BaseDMA{

    private:
        char * label;
        int rating;
    public:
        BaseDMA(const char * l = "null", int r= 0);
        BaseDMA(const BaseDMA & rs);
        virtual ~BaseDMA();

        BaseDMA & operator=(const BaseDMA & rs);

        friend std::ostream & operator<<(std::ostream & os, const BaseDMA & rs);
};

//================LacksDMS===================

class LacksDMA : public BaseDMA {
    private:
        enum{COL_LEN=40};
        char color[COL_LEN];   //固定数组，则不需要动态分配内存，则不需要使用到new
    public:
        LacksDMA(const char * c="blanks", const char * l ="null", int r= 0);
        LacksDMA(const char *c, const BaseDMA & rs);

        friend std::ostream & operator<<(std::ostream & os, const LacksDMA & rs);

};

//===================================

class HasDMA : public BaseDMA{
    private:
        char * style;  //包含指针，那么会需要用到new来创建管理内存，则需要使用到 【复制构造函数 ， 赋值运算符】
    public:
        HasDMA(const char * s = "none", const char * l = "null", int r=0);
        HasDMA(const char * s, const BaseDMA & rs);
        HasDMA(const HasDMA & hs); //复制构造函数   
        ~HasDMA();
        HasDMA & operator=(const HasDMA & rs); //赋值运算符
        
        friend std::ostream & operator<<(std::ostream & os, const HasDMA & rs);
};

#endif