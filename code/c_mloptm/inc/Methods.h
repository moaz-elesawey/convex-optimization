#ifndef _METHODS_H_
#define _METHODS_H_

/*
 * This is a Implementation of four of the Most 
 * Famous Optimization Methods which are:
 *
 *  - Golden Section Search Method.
 *  - BiSection Method.
 *  - Newton Method.
 *  - Secant Method.
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define RO 0.3819660112501051


float GoldenMinimize(float (*f)(float), float a0, float b0, float eps);

float BiSectionMinimize(float (*f)(float), float(*df)(float), float a0, float b0, int epochs);

float NewtonMinimize(float (*f)(float), float (*df)(float), float (*ddf)(float), float x0, float eps);

float SecantMinimize(float (*f)(float), float (*df)(float), float x0, float x1, float eps);


#endif /*_METHODS_H_*/
