#ifndef COORDIN_H_
#define COORDIN_H_

struct polar{
    double distance;
    double angle;
};

struct rect{
    double x;
    double y;
};

//弧度转换成角度的比值 = 180/PI
const double Rad_to_deg = 57.29577951;

polar rect_to_polar(rect xypos);

void show_polar(polar dapos);

#endif