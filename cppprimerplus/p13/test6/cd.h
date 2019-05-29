#ifndef CD_H_
#define CD_H_

class Cd6 {

    private:
        char * performers;
        char * label;
        // char performers[50];
        // char label[20];
        int selections;
        double playtime;
    public:
        Cd6(char * s1, char * s2, int n, double x);
        Cd6(const Cd6 & d);
        Cd6();
        virtual ~Cd6();
        virtual void report() const;
        Cd6 & operator=(const Cd6 & d);
};

class Classic6 : public Cd6 {
    private:
        // char major[100];
        char * major;
    public:
        Classic6(char * major, char * s1, char * s2, int n, double x);
        Classic6(const Classic6 & c);
        // Classic6(char * m, const Classic6 & c);
        Classic6();

        Classic6 & operator=(const Classic6 & c);

        virtual ~Classic6() {};
        virtual void report() const;
};

#endif