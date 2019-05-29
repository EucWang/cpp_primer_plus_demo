#ifndef PLORG_H_
#define PLORG_H_

class Plorg{
    private:
        char mName[20];
        int mCI;
    public:
        Plorg(const char * name="Plorga", int ci=50);
        void set_ci(int ci);
        void show() const;
};

#endif