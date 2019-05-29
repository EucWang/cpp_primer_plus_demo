#include <iostream>
#include <cstring>
#include "cow.h"

Cow::Cow(){
    std::cout << " default constructor Cow" << std::endl;
    name[0] = '\0';
    hobby = NULL;
    weight = 0;
}

Cow::Cow(const char * nm, const char * ho, double wt) {
    std::cout << "construcotr Cow " << std::endl;
    int len = strlen(nm);
    if(len > 20) {
        strncpy(name, nm, 20);
    }else {
        strcpy(name, nm);
    }

    len = strlen(ho);
    hobby = new char[len + 1];
    strcpy(hobby, ho);
    weight = wt;
}

Cow::Cow(const Cow & c) {
    std::cout << "copy constructor Cow" << std::endl;
    strcpy(name, c.name);
    if(c.hobby != NULL) {
        int len = strlen(c.hobby);
        hobby = new char[len + 1];
        strcpy(hobby, c.hobby);
    }
    weight = c.weight;
}

Cow & Cow::operator=(const Cow & c) {
    std::cout << "operator=" << std::endl;
    if(this == (&c)) {
        return *this;
    }

    delete [] hobby;

    strcpy(name, c.name);
    if(c.hobby != NULL) {
        int len = strlen(c.hobby);
        hobby = new char[len + 1];
        strcpy(hobby, c.hobby);
    }
    weight = c.weight;

    return *this;
}

void Cow::showCow() const {
    std::cout << "Cow[name=" << name << ", hobby:" << hobby << ",weight:" <<weight << "]"<< std::endl;
}

Cow::~Cow(){
    std::cout << "~Cow"<<std::endl;
    delete [] hobby;
    weight = 0;
}