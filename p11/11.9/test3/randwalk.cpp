#include <iostream>
#include <cstdlib>
#include <ctime>
#include "vector.h"

using namespace std;
using VECTOR::Vector;
using VECTOR::Mode;


int main()
{
    srand(time(0));
    double direction;
    Vector step;
    Vector result(0.0, 0.0);
    unsigned long steps = 0;
    double target;

    double dstep;
    int ntimes;  //

    cout << "Enter target distance (q to quit):";
    while(cin >> target) {
        cout << "Enter step length: ";
        if(!(cin >> dstep)) {
            break;
        }
        cout << "Enter test times : ";
        if(!(cin >> ntimes)) {
            break;
        }
        int max_step = 0;
        int min_step = INT32_MAX;
        int average_step = 0;
        for(int i=0; i<ntimes; i++) {
            steps = 0;
            result.reset(0.0, 0.0);
            while(result.magval() < target) {
                direction = rand() %360;
                step.reset(dstep, direction, Mode::POL);
                result = result + step;
                steps++;
            }

            if(steps > max_step) {
                max_step = steps;
            }
            if(steps < min_step) {
                min_step = steps;
            }
            average_step += steps;
        }

        cout << "=======\nAfter test " << ntimes << " times" 
            << "\nmax step is " << max_step 
            << "\nmin step is " << min_step
            << "\naverage step is "<< average_step/ntimes 
            << "\n======="<< endl;

        // cout << "After " << steps << " steps, the subject "
        //     << "has the following location: \n";
        cout << result << endl;
        result.polar_mode();
        cout << " or\n" << result << endl;
        cout << "Average outward distance per step = "
            << result.magval()/steps << endl;
        steps = 0;
        result.reset(0.0, 0.0);
        cout << "Enter target distance (q to quit):";
    }
    cout << "Bye!\n";
    cin.clear();
    while(cin.get() != '\n') {
        continue;
    }
    return 0;

    return 0;
}
