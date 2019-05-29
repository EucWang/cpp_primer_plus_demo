#ifndef TVFM_H_
#define TVFM_H_

#include <iostream>

//前置申明 
class Tv3;

//声明 
class Remote3{
    public:
        enum State{OFF, ON};
        enum {MinVal, MaxVal=20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        enum {NORMAL, BUZZ};
    private:
        int mode;
        int isBuzz; //正常模式，还是互动模式，buzz模式
    public:
        friend class Tv3;

        Remote3(int m=TV):mode(m), isBuzz(NORMAL){}

        bool volup(Tv3 & t);
        bool voldown(Tv3 & t);
        void onoff(Tv3 & t);
        void chanup(Tv3 & t);
        void chandown(Tv3 & t);
        void set_mode(Tv3 & t);
        void set_input(Tv3 & t);
        void set_chan(Tv3 & t, int c);   

        char * showBuzz();
};

//申明
class Tv3{
    private:
        int state;
        int volume;
        int maxchannel;
        int channel;
        int mode;
        int input;
    public:
        friend class Remote3;

        enum State{OFF, ON};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};
        enum {NORMAL, BUZZ};

        Tv3(int s=OFF, int mc=125):state(s),volume(5),maxchannel(mc),channel(2), mode(Cable),input(TV){}
        
        void onoff(){state= (state==ON)?OFF:ON;};
        bool ison() const{return state==ON;}
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode(){mode=(mode==Antenna)?Cable:Antenna;}
        void set_input(){input=(input==TV)?DVD:TV;}
        void settings() const;

        void buzz(Remote3 & r);
};



inline bool Remote3::volup(Tv3 & t){return t.volup();}
inline bool Remote3::voldown(Tv3 & t) {return t.voldown();}

inline void Remote3::onoff(Tv3 & t) {t.onoff();}
inline void Remote3::chanup(Tv3 & t) {t.chanup();}
inline void Remote3::chandown(Tv3 & t){t.chandown();}
inline void Remote3::set_mode(Tv3 & t){t.set_mode();}
inline void Remote3::set_input(Tv3 & t) {t.set_input();}
inline void Remote3::set_chan(Tv3 & t, int c){t.channel = c;}

inline char * Remote3::showBuzz() {
    if(isBuzz ==NORMAL) {
        std::cout << "Remote3 is now normal\n";
    }else {
         std::cout << "Remote3 is now buzz\n";
    }
}

inline void Tv3::buzz(Remote3 & r) {
    if(state==ON){
        r.isBuzz = (r.isBuzz ==NORMAL?BUZZ:NORMAL);
        std::cout << "changed remote buzz now.\n";
    } else {
        std::cout << "tv is off, cannot change remote buzz\n";
    }
}

#endif