#include <iostream>
#include "test3.h"

using namespace std;

struct Student{
    Student(bool g, int a) : gender(g), age(a){}
    bool gender;
    int age;
};

/**
 *  这里把 匿名非受限联合体成为类 Singer 的 “变长成员” .
 */ 
class Singer{
public:
    enum Type{STUDENT, NATIVE, FOREIGNER};
    Singer(bool g, int a) : s(g, a) { t = STUDENT;}
    Singer(int i) : id(i){ t = NATIVE;}
    Singer(const char * n , int s){
        int size = (s > 9) ? 9 : s;
        memcpy(name, n, size);
        name[s] = '\0';
        t = FOREIGNER;
    }
    ~Singer(){}
private:
    Type t;
    union {   //匿名的联合体
        Student s;
        int id;
        char name[10];
    };
};

void testp3_17(){
    cout << __func__ << "() called.\n";

    Singer(true, 13);
    Singer(323413);
    Singer("J Michael", 9);

    cout << __func__ << "() called. done. \n";
}