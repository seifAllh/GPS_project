#include <math.h>
#define PI   3.14159265
#define R    6378.1370
#include "GPS_module.h"


long double distance_m(long double lat1, long double lat2, long double lon1, long double lon2)
{

	 long double total_distance=0;



	 long double ans=0;
    // Converting latitudes and longitudes from degree to radian
    long double latitude1_rad = lat1*(PI/180);
    long double longitude1_rad = lon1*(PI/180);
    long double latitude2_rad = lat2*(PI/180);
    long double longitude2_rad =lon2*(PI/180);

    // Haversine Formula
    long double dlongitude = longitude2_rad - longitude1_rad;
    long double dlatitude = latitude2_rad - latitude1_rad;
	if (dlongitude <0)
	{
		dlongitude*= -1;
	}
	if (dlatitude <0)
	{
		dlatitude*= -1;
	}

    ans = pow(sin(dlatitude / 2), 2) +  cos(lat1) * cos(lat2) * pow(sin(dlongitude / 2), 2);

             // ans = 2 * asin(sqrt(ans));

	         ans = 2 * asin(sqrt(ans));

    // Radius of Earth in Km, R = 6371

         ans=(ans * R*1000);  //distance in meters
	       total_distance=total_distance+ans;

	       return total_distance;

}
