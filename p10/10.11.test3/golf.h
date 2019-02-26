#ifndef GOLF_H
#define GOLF_H

// const int LEN = 40;

// struct golf{
//     char fullname[LEN];
//     int handicap;
// };

// void setgolf(golf & g, const char * name, int hc);

// int setgolf(golf & g);

// void handicap(golf & g, int hc);

// void showgolf(const golf & g);

class Golf{
    private:
        static const int LEN = 40;
        char mFullname[LEN];
        int mHandicap;
    public:
        Golf(){mFullname[0]='\0'; mHandicap = 0;};
        Golf(const char * name, int hc);
        int setgolf();
        void handicap(int hc);
        void showgolf() const;
};

#endif