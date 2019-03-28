#ifndef DMA_H_
#define DMA_H_

#include <iostream>

//================DmaABC ===================

class DmaABC {
    private:
        char * label;
        int rating;
    public:
        DmaABC(const char * l = "null", int r= 0);
        DmaABC(const DmaABC & rs);
        virtual ~DmaABC();

        DmaABC & operator=(const DmaABC & rs);

        int getRating(){return rating;};
        void setRating(int r){rating = r;};
        virtual void view() const = 0;

};


//================BaseDMA===================

class BaseDMA : public DmaABC {
    public:
        BaseDMA(const char * l = "null", int r= 0):DmaABC(l, r){};
        BaseDMA(const BaseDMA & rs):DmaABC(rs){};
        virtual ~BaseDMA(){};
        virtual void view() const;
};

//================LacksDMS===================

class LacksDMA : public DmaABC {
    private:
        enum{COL_LEN=40};
        char color[COL_LEN];   //固定数组，则不需要动态分配内存，则不需要使用到new
    public:
        LacksDMA(const char * c="blanks", const char * l ="null", int r= 0);
        LacksDMA(const char *c, const DmaABC & rs);

        friend std::ostream & operator<<(std::ostream & os, const LacksDMA & rs);

        virtual void view() const ;
};

//===================================

class HasDMA : public DmaABC{
    private:
        char * style;  //包含指针，那么会需要用到new来创建管理内存，则需要使用到 【复制构造函数 ， 赋值运算符】
    public:
        HasDMA(const char * s = "none", const char * l = "null", int r=0);
        HasDMA(const char * s, const DmaABC & rs);
        HasDMA(const HasDMA & hs); //复制构造函数   
        ~HasDMA();
        HasDMA & operator=(const HasDMA & rs); //赋值运算符
        
        // friend std::ostream & operator<<(std::ostream & os, const HasDMA & rs);

        virtual void view() const;
};

#endif