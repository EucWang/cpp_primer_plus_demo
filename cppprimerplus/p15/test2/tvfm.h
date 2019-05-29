#ifndef TVFM_H_
#define TVFM_H_

//前置申明 
class Tv2;

//声明 
class Remote2{
    public:
        enum State{OFF, ON};
        enum {MinVal, MaxVal=20};
        enum {Antenna, Cable};
        enum {TV, DVD};
    private:
        int mode;
    public:
        Remote2(int m=TV):mode(m){}

        bool volup(Tv2 & t);
        bool voldown(Tv2 & t);
        void onoff(Tv2 & t);
        void chanup(Tv2 & t);
        void chandown(Tv2 & t);
        void set_mode(Tv2 & t);
        void set_input(Tv2 & t);
        void set_chan(Tv2 & t, int c);        
};

//申明
class Tv2{
    private:
        int state;
        int volume;
        int maxchannel;
        int channel;
        int mode;
        int input;
    public:
        friend void Remote2::set_chan(Tv2 & t, int c);

        enum State{OFF, ON};
        enum {MinVal, MaxVal = 20};
        enum {Antenna, Cable};
        enum {TV, DVD};

        Tv2(int s=OFF, int mc=125):state(s),volume(5),maxchannel(mc),channel(2), mode(Cable),input(TV){}
        
        void onoff(){state= (state==ON)?OFF:ON;};
        bool ison() const{return state==ON;}
        bool volup();
        bool voldown();
        void chanup();
        void chandown();
        void set_mode(){mode=(mode==Antenna)?Cable:Antenna;}
        void set_input(){input=(input==TV)?DVD:TV;}
        void settings() const;
};

inline bool Remote2::volup(Tv2 & t){return t.volup();}
inline bool Remote2::voldown(Tv2 & t) {return t.voldown();}

inline void Remote2::onoff(Tv2 & t) {t.onoff();}
inline void Remote2::chanup(Tv2 & t) {t.chanup();}
inline void Remote2::chandown(Tv2 & t){t.chandown();}
inline void Remote2::set_mode(Tv2 & t){t.set_mode();}
inline void Remote2::set_input(Tv2 & t) {t.set_input();}
inline void Remote2::set_chan(Tv2 & t, int c){t.channel = c;}




#endif