#include <iostream>
#include <cstring>

using namespace std;

struct car 
{
    char manifacture[64];
    int year;
};

char * get_name22(){
    char tmp[256];
    cin.getline(tmp, 256);
    char * ret_val = new char(strlen(tmp) + 1);
    strcpy(ret_val, tmp);
    return ret_val;
}


int main31(){

    const char * tip1 = "How many cars do you wish to catalog?";
    const char * tip2 = "Please enter the make: ";
    const char * tip3 = "Plase enter the year made: ";
    const char * tip4 = "Here is your collection:\n";

    cout << tip1;
    int count;
    cin >> count;
    cout << count << endl;
    cin.get();
    struct car * cars = new car[count];
    for(int i = 0; i < count; i++)
    {
        cout << "Car #" << (i+1) << endl << tip2;
        // cin.getline(cars[i].manifacture, 64).get();
        // strcpy(cars[i].manifacture, get_name22());
        cin.getline(cars[i].manifacture, 64);

        cout << tip3;
        cin >> cars[i].year;
        cin.get();
    }
    
    cout << tip4;
    for(size_t i = 0; i < count; i++)
    {
        cout << cars[i].year << " " << cars[i].manifacture << endl;
    }

    return 0;
}