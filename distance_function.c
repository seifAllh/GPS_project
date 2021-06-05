#include <math.h>
#define PI   3.14159265
#define R    6378.1370

unsigned char distance_m(unsigned char latitude1, unsigned char longitude1, unsigned char latitude2,unsigned char longitude2)
{
    // Converting latitudes and longitudes from degree to radian
    unsigned char latitude1_rad = latitude1*(PI/180);
    unsigned char longitude1_rad = longitude1*(PI/180);
    unsigned char latitude2_rad = latitude2*(PI/180);
    unsigned char longitude2_rad = longitude2*(PI/180);
     
    
