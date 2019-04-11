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

class BaseDMA7 : public DmaABC {
    public:
        BaseDMA7(const char * l = "null", int r= 0):DmaABC(l, r){};
        BaseDMA7(const BaseDMA7 & rs):DmaABC(rs){};
        virtual ~BaseDMA7(){};
        virtual void view() const;
};

//================LacksDMS===================

class LacksDMA7 : public DmaABC {
    private:
        enum{COL_LEN=40};
        char color[COL_LEN];   //固定数组，则不需要动态分配内存，则不需要使用到new
    public:
        LacksDMA7(const char * c="blanks", const char * l ="null", int r= 0);
        LacksDMA7(const char *c, const DmaABC & rs);

        friend std::ostream & operator<<(std::ostream & os, const LacksDMA7 & rs);

        virtual void view() const ;
};

//===================================

class HasDMA7 : public DmaABC{
    private:
        char * style;  //包含指针，那么会需要用到new来创建管理内存，则需要使用到 【复制构造函数 ， 赋值运算符】
    public:
        HasDMA7(const char * s = "none", const char * l = "null", int r=0);
        HasDMA7(const char * s, const DmaABC & rs);
        HasDMA7(const HasDMA7 & hs); //复制构造函数
        ~HasDMA7();
        HasDMA7 & operator=(const HasDMA7 & rs); //赋值运算符
        
        // friend std::ostream & operator<<(std::ostream & os, const HasDMA7 & rs);

        virtual void view() const;
};

#endif