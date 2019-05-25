//
// Created by 王新年 on 2019-05-25.
//

#include "test9.h"
#include <utility>


//class Cpmv{
//public:
//    struct Info{
//        std::string qcode;
//        std::string zcode;
//    };
//private:
//    Info * pi;
//public:
Cpmv::Cpmv(){
    std::cout << "Cpmv constructor ()"<< std::endl;
    this->pi = new Info();
}

Cpmv::Cpmv(std::string q, std::string z){
    std::cout << "Cpmv constructor (q, z)"<< std::endl;
    this->pi = new Info();
    this->pi->qcode = q;
    this->pi->zcode = z;
}

Cpmv::Cpmv(const Cpmv * cp){
    std::cout << "Cpmv copy constructor (Cpmv *)"<< std::endl;
    this->pi = new Info();
    this->pi->qcode = cp->pi->qcode;
    this->pi->zcode = cp->pi->zcode;
}

Cpmv::Cpmv(Cpmv && mv) {
    std::cout << "Cpmv move constructor (Cpmv &&)"<< std::endl;
    this->pi = new Info();
    this->pi->qcode = mv.pi->qcode;
    this->pi->zcode = mv.pi->zcode;

    mv.pi = nullptr;
}

Cpmv::~Cpmv(){
    std::cout << "~Cpmv()" << std::endl;
    delete this->pi;
}

Cpmv & Cpmv::operator=(const Cpmv & cp) {
    std::cout << "operator=(const Cpmv &)" << std::endl;
    this->pi = new Info();
    this->pi->qcode = cp.pi->qcode;
    this->pi->zcode = cp.pi->zcode;
    return *this;
}

Cpmv & Cpmv::operator=(Cpmv && mv){
    std::cout << "operator=(const Cpmv &&)" << std::endl;
    this->pi = new Info();
    this->pi->qcode = mv.pi->qcode;
    this->pi->zcode = mv.pi->zcode;

    mv.pi = nullptr;
    return *this;
}

Cpmv Cpmv::operator+(const Cpmv & obj) const{
    std::cout << "operator+(const Cpmv &)" << std::endl;
    Cpmv retVal;
    retVal.pi->zcode = this->pi->zcode + "_"+ obj.pi->zcode;
    retVal.pi->qcode = this->pi->qcode + "_"+ obj.pi->qcode;

    return retVal;
}

void Cpmv::display() const{
    if (this->pi != nullptr){
        std::cout << "display info [qcode : " << this->pi->qcode
            << ", zcode : " << pi->zcode << "]\n";
    } else {
        std::cout << "display fail, pi is nullptr" << std::endl;
    }
}

int main_p18test2() {
    Cpmv cpmv1;
    std::cout << "display cpmv1 " << std::endl;
    cpmv1.display();
    std::cout << std::endl;

    Cpmv cpmv2("123", "456");
    std::cout << "display cpmv2 " << std::endl;
    cpmv2.display();
    std::cout << std::endl;

    Cpmv cpmv3(&cpmv2);
    std::cout << "display cpmv3 " << std::endl;
    cpmv3.display();
    std::cout << std::endl;

    Cpmv cpmv4(std::move(cpmv3));
    std::cout << "display cpmv4 " << std::endl;
    cpmv4.display();
    std::cout << std::endl;
    std::cout << "display cpmv3 again " << std::endl;
    cpmv3.display();
    std::cout << std::endl;

    Cpmv cpmv5 = cpmv4 + cpmv2;
    std::cout << "display cpmv5 " << std::endl;
    cpmv5.display();
    std::cout << std::endl;

    return 0;
}