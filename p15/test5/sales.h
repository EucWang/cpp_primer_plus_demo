#ifndef SALES_H_
#define SALES_H_

#include <stdexcept>
#include <string>

using std::string;

class Sales{
    protected:
        enum {MONTHS=12};
    private:
        double gross[MONTHS];
        int year;
    public:
        class BadIndex : public std::logic_error{ //继承自logic_error,能够存储和报告数组索引越界值
            private:
                int bi;
            public:
                explicit BadIndex(int ix, const string & s="Index error in Sales object\n");
                virtual ~BadIndex()throw(){}  //这里的C98规范,表示不抛出任何异常

                int getBiVal() const{return bi;}
        };

        explicit Sales(int yy=0);
        Sales(int yy, const double * gr, int n);
        virtual ~Sales(){}

        int getYear() const{return year;}
        virtual double operator[](int i) const;
        virtual double & operator[](int i);
};

class LabeledSales : public Sales {
    private:
        string label;
    public:
        class NbadIndex : public Sales::BadIndex{
            private:
                string lbl;
            public:
                NbadIndex(const string & lb, int ix, const string & s = "Index error in LabeledSales object\n");
                virtual ~NbadIndex() throw(){}//这里的C98规范,表示不抛出任何异常
                
                const string getLabelVal() const {return lbl;}
        };

        explicit LabeledSales(const string & lb="none", int yy=0);
        LabeledSales(const string & lb, int yy, const double * gr, int n);
        virtual ~LabeledSales(){} 

        const string & getLabel() const{return label;}
        virtual double operator[](int i) const;
        virtual double & operator[](int i);
};

#endif