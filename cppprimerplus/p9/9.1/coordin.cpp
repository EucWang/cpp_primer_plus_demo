#include <iostream>
#include <cmath>

#include "coordin.h"

using namespace std;

polar rect_to_polar0(rect xypos) {
    polar answer;
    answer.distance = sqrt(xypos.x * xypos.x + xypos.y * xypos.y);
    answer.angle =  atan2(xypos.y, xypos.x);
    return answer;
}

void show_polar0(polar dapos) {
    cout << "distance = " << dapos.distance;
    cout << ", angle = " << dapos.angle * Rad_to_deg;
    cout << " degress\n";
}