#include "tm4c123gh6pm.h"
#include "stdint.h"
#include <stdbool.h>
#include <math.h>
#include <stdio.h>
#include "UART.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>
char data_array[37]={0};


	 // check if the data true
      bool GPS_ckeck()
{
  char D = UART_input();


  if (D == '$')
  { data_array[0]=D;
    D = UART_input();
    if (D == 'G')
    { data_array[1]=D;
      D= UART_input();


      if (D == 'P')

      { data_array[2]=D;
        D = UART_input();

        if (D == 'G')
        { data_array[2]=D;
          D = UART_input();

          if (D == 'L')
          {data_array[4]=D;
            D= UART_input();

             if (D == 'L')
             { data_array[5]=D;
              D= UART_input();

              if (D == ',')
              {data_array[6]=D;
                D= UART_input();
                if (D == ',')
                {
                  return false;
                }
                else
                {
                  return true;
                }
              }
            }
          }
        }
      }
    }
  }
   return false;
}

   // get all data



// for converting coordinats
float coordinates_Degrees(const char* nmeaPos)
{
  float n= 0;
  if(strlen(nmeaPos)>5)
  {
    char integerPart[3+1];
    int digitCount= (nmeaPos[4]=='.' ? 2 : 3);
    memcpy(integerPart, nmeaPos, digitCount);
    integerPart[digitCount]= 0;
    nmeaPos+= digitCount;
    n= atoi(integerPart) + atof(nmeaPos)/60.;
		

  }
	    return n;
}



// getting latitudes
float get_lat ()
{
	   
	     
        int i=7;
        int j=0;
	      char lat[10]={0};	
        for(i=7;i<=16;i++)
       {
             lat[j]=data_array[i];
               j++;
       }
			
        return coordinates_Degrees(lat);
}



// getting longitude
float get_lon ()
{
	
        int i=20;
         int j=0;
	      char lon[11]={0};
        for(i=20;i<=30;i++)
      {
            lon[j]=data_array[i];
             j++;
      }
       return coordinates_Degrees(lon);
		}

