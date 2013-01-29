#ifndef TRIG_H
#define TRIG_H
#include <iostream>
#include <cmath>
#endif
double radians (double d) {
return d * M_PI / 180;
}
double degrees (double r) {
return r * 180/ M_PI;
}

int main()
{

radians();
degrees();
return 0;
}
