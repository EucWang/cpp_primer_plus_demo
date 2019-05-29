#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>

using std::string;

class abstr_emp{
    private:
        string fname;
        string lname;
        string job;
    protected:
        virtual void showData() const=0;
    public:
        abstr_emp();
        abstr_emp(const string & fn, const string & ln, const string & j);

        virtual void showAll() const;
        virtual void setAll();

        friend std::ostream & operator<<(std::ostream & os, const abstr_emp & e);

        virtual ~abstr_emp(){}

};
//-----------------------------------------

class employee : public abstr_emp {

    protected:
        virtual void showData() const{}
    public:
        employee();
        employee(const string & fn, const string & ln, const string & j);

        virtual ~employee(){}

        virtual void showAll() const;
        virtual void setAll();

};

//-----------------------------------------
class manager : virtual public abstr_emp{
    private:
        int inchargeof;
    protected:
        int getInchargeof() const {return inchargeof;}
        void setInchargeOf(int value){inchargeof = value;}
        void showData() const;
    public:
        manager();
        manager(const string & fn, const string & ln, const string & j, int ico = 0);
        manager(const abstr_emp & e, int ico);
        manager(const manager & m);
        virtual ~manager(){}

        virtual void showAll() const;
        virtual void setAll();
};

//-----------------------------------------
class fink : virtual public abstr_emp {
    private:
        string reportsto;
    protected:
        const string getReportsto() const{return reportsto;}
        void setReportsto(string & r) {reportsto = r; }
        void showData() const;
        void setData();
    public:
        fink();
        fink(const string & fn,
                const string & ln,
                const string & j,
                const string & rpo);
        fink(const abstr_emp & e, const string & rpo);
        fink(const fink & e);
        virtual ~fink(){}

        virtual void showAll() const;
        virtual void setAll();
};


//-----------------------------------------
class highfink : public manager, public fink {
    protected:
        void showData() const{}
    public:
        highfink();
        highfink(const string & fn, const string & ln, const string & j, const string & rpo, int ico);
        highfink(const abstr_emp & e, const string & rpo, int ico);

        highfink(const fink & f, int ico);
        highfink(const manager & m, const string & rpo);

        highfink(const highfink & h);


        ~highfink(){}

        virtual void showAll() const;
        virtual void setAll();
};


#endif