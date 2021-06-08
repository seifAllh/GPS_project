#include <math.h>
#define PI   3.14159265
#define R    6378.1370

long double distance_m(long double latitude1, long double longitude1, long double latitude2,long double longitude2)
{
    // Converting latitudes and longitudes from degree to radian
  long double latitude1_rad = latitude1*(PI/180);
    long double longitude1_rad = longitude1*(PI/180);
    long double latitude2_rad = latitude2*(PI/180);
    long double longitude2_rad = longitude2*(PI/180);

    // Haversine Formula
  long double dlongitude = longitude2_rad - longitude1_rad;
    long double dlatitude = latitude2_rad - latitude1_rad;
   long double ans = pow(sin(dlatitude / 2), 2) +  cos(latitude1) * cos(latitude2) * pow(sin(dlongitude / 2), 2);

              ans = 2 * asin(sqrt(ans));

    // Radius of Earth in meter, R = 6371

         return (ans * R);  //distance in meters
}
