#ifndef CD_H_
#define CD_H_

class Cd {

    private:
        char performers[50];
        char label[20];
        int selections;
        double playtime;
    public:
        Cd(char * s1, char * s2, int n, double x);
        Cd(const Cd & d);
        Cd();
        virtual ~Cd() {}
        virtual void report() const;
        Cd & operator=(const Cd & d);
};

class Classic : public Cd {
    private:
        char major[100];
    public:
        Classic(char * major, char * s1, char * s2, int n, double x);
        // Classic(const Classic & c);
        // Classic(char * m, const Classic & c);
        Classic();

        virtual ~Classic() {};
        virtual void report() const;
};

#endif