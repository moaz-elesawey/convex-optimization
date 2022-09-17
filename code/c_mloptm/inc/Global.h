#ifndef _GLOBAL_H_
#define _GLOBAL_H_

// This file include the user define function and their corrosponding derivatives.

#include <stdio.h>
#include <math.h>

float f(float x){ return pow(x, 4); }
float df(float x){ return 4*pow(x, 3); }
float ddf(float x){ return 12*pow(x, 2); }


#endif /*_GLOBAL_H_*/
