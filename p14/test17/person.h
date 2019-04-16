//
// Created by 王新年 on 2019-04-11.
//

#ifndef CPP_PRIMER_PLUS_DEMO_PERSON_H
#define CPP_PRIMER_PLUS_DEMO_PERSON_H

#include <string>
#include <iostream>
using std::string;
using std::cout;


class Person2 {
    private:
        string firstname;
        string lastname;
    protected:
        virtual void showdata();
        virtual void setdata(string tag);
    public:
        explicit Person2(string f="",string l=""):firstname(f),lastname(l){};
        virtual ~Person2(){cout << "Person2 being freed.";}
        virtual void show();
        virtual void set();
};

class Gunslinger : virtual public Person2 {
    private:
        int markcount;
    protected:
         void showdata();
         void setdata(string tag);
    public:
        explicit  Gunslinger(string f="",string l="", int m=0):Person2(f,l),markcount(m){}
    virtual ~Gunslinger(){cout << "Gunslinger being freed.";}
        double draw(); //枪手的拔枪时间
        void show();
        void set();
};

class PokerPlayer : virtual public Person2{
    private:
    protected:
        void showdata();
        void setdata(string tag);
    public:
        explicit PokerPlayer(string f="",string l=""):Person2(f,l){}
    virtual  ~PokerPlayer(){cout << "PokerPlayer being freed.";}
         int draw();  //返回1 ～ 52之间的随机数
         void show();
         void set();
};

class BadDude : public Gunslinger, public PokerPlayer {
    private:

    protected:
        void showdata();
        void setdata(string tag);

    public:
        BadDude(string f="",string l="", int m=0):Person2(f,l),PokerPlayer(f,l), Gunslinger(f,l, m){}
    virtual  ~BadDude(){cout << "BadDude being freed.";}
        double gdraw();
        int cdraw();

        void show();
        void set();
};

#endif //CPP_PRIMER_PLUS_DEMO_PERSON_H
