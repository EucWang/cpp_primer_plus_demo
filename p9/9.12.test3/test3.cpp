#include <iostream>
#include <cstring>
using namespace std;


struct chaff{
    char dross[20];
    int slag;
};

void set_chaff(chaff & c, char * dr, int slag);

void show_chaff(chaff & c);

char buffer[128];

int main()
{
    chaff * c = new (buffer) chaff[2];
    set_chaff(*c, "WAHAHA", 1);
    set_chaff(*(c+1), "PERPESY", 2);
    for(int i=0; i<2;i++) {
        show_chaff(*(c+i));
    }

    return 0;
}


void set_chaff(chaff & c, char * dr, int slag){
    strcpy(c.dross, dr);
    c.slag = slag;
}

void show_chaff(chaff & c){
    cout << "=======chaff info=======" << endl;
    cout << "DROSS : " << c.dross << endl;
    cout << "SLAG : " << c.slag << endl;
}