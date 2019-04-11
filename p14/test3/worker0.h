#ifndef WORKER_0_H_
#define WORKER_0_H_

#include <string>

using std::string;

class Worker0 {
private:
    string fullname;
    long id;
public:
    Worker0() : fullname("no one"), id(0L) {}
    Worker0(const string & s, long n) : fullname(s), id(n) {}

    virtual ~Worker0() = 0;
    virtual void set();
    virtual void show() const;
};

class Waiter0 : public Worker0 {
private:
    int panache;
public:
    Waiter0():Worker0(), panache(0) {}
    Waiter0(const string & s, long n, int p =0): Worker0(s, n), panache(p) {}
    Waiter0(const Worker0 & wk, int p = 0) : Worker0(wk), panache(p) {}
    void set();
    void show() const;
};

class Singer0 : public Worker0 {
protected:
    enum {other, alto, contralto, soprano, bass, baritone, tenor};
    enum { Vtypes = 7};
private:
    static char * pv[Vtypes];
    int voice;
public:
    Singer0() : Worker0(), voice(other) {}
    Singer0(const string & s, long n, int v=other) : Worker0(s, n), voice(v) {}
    void set();
    void show() const;
};



#endif