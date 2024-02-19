/***********************************************************************/
/* UDFs for specifying time dependant velocity profile boundary condition
/***********************************************************************/

#include "udf.h"//file that contains definitions for defined functions and fluent operations
#define PI 3.141592654

DEFINE_PROFILE(inlet_velocity,th,i)
{
	face_t f;
	begin_f_loop(f,th)
		double t = (CURRENT_TIME*2-floor(CURRENT_TIME*2))/2; //t is the local time within each period

	{
		if(t <= 0.218)
			F_PROFILE(f,th,i) = 0.5*sin(4*PI*(t+0.016));
		else
			F_PROFILE(f,th,i) = 0.1;
	}
	end_f_loop(f,th);
}
