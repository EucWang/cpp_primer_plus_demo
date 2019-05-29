#ifndef EMP_H_
#define EMP_H_

#include <iostream>
#include <string>
#include <fstream>

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
        virtual void writeAll(std::ofstream &);
        void setFirstName(string name){fname = name;}
        void setLastName(string name) {lname= name;}
        void setJob(string j) {job = j;}

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
        virtual void writeAll(std::ofstream &);

};

//-----------------------------------------
class manager : virtual public abstr_emp{
    private:
        int inchargeof;
    protected:
        int getInchargeof() const {return inchargeof;}
       
        void showData() const;
    public:
        manager();
        manager(const string & fn, const string & ln, const string & j, int ico = 0);
        manager(const abstr_emp & e, int ico);
        manager(const manager & m);
        virtual ~manager(){}
        void setInchargeOf(int value){inchargeof = value;}

        virtual void showAll() const;
        virtual void setAll();
        virtual void writeAll(std::ofstream &);
        virtual void writeSelf(std::ofstream &);

};

//-----------------------------------------
class fink : virtual public abstr_emp {
    private:
        string reportsto;
    protected:
        const string getReportsto() const{return reportsto;}
       
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
         void setReportsto(string & r) {reportsto = r; }

        virtual void showAll() const;
        virtual void setAll();
        virtual void writeAll(std::ofstream &);
        virtual void writeSelf(std::ofstream &);
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

        void setReportsto(string & r) {fink::setReportsto(r); }
        void setInchargeOf(int value){manager::setInchargeOf(value);}

        ~highfink(){}

        virtual void showAll() const;
        virtual void setAll();
        virtual void writeAll(std::ofstream &);
        virtual void writeSelf(std::ofstream &);
};


#endif