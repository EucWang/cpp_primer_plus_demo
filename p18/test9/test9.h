#ifndef TEST9_H_
#define TEST9_H_

#include <iostream>


class Cpmv{
public:
    struct Info{
        std::string qcode;
        std::string zcode;
    };
private:
    Info * pi;
public:
    Cpmv();
    Cpmv(std::string q, std::string z);
    Cpmv(const Cpmv * cp);
    Cpmv(Cpmv && mv);
    ~Cpmv();
    Cpmv &operator=(const Cpmv & cp);
    Cpmv &operator=(Cpmv && mv);
    Cpmv operator+(const Cpmv & ojb) const;
    void display() const;
};


int main_p18test1();
int main_p18test2();
int main_p18test3();
int main_p18test4();

#endif