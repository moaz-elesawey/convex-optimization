#include "Method.hpp"


float Method::Golden(float (f) (float), float a0, float b0, float eps) {
	/*
	 * Golden Section Search Optimization Method Implementation.
	 *
	 * Parameters
	 * ----------
	 *  - f (func)   : the function to be optimized.
	 *  - a0 (float) : the starting of the function domain
	 *  - b0 (float) : the end point of the function domain.
	 *  - eps (float): the error to compare the result to.
	 *
	 * Returns
	 * -------
	 *  - minima (float): the minimum value of the function.*/

	int N = log( eps/2 ) / log(1-RO);

	float a1, b1;
	float min;

	for (int i=0; i<N; i++) {
		a1 = a0 + RO * (b0 - a0);
		b1 = b0 - RO * (b0 - a0);

		if (f(b1) > f(a1))
			b0 = b1;
		else
			a0 = a1;
	}

	min = (a0 + b0) / 2;
	
	return min;
}

float Method::BiSection(float (f) (float), float (df) (float), float a0, float b0, int epochs){
	/*
	 * BiSection Optimization Method Implementation.
	 *
	 * Parameters
	 * ----------
	 *  - f (func)    : the function to be optimized.
	 *  - df (func)   : the first derivative of function to be optimized.
	 *  - a0 (float)  : the starting of the function domain
	 *  - b0 (float)  : the end point of the function domain.
	 *  - epochs (int): number of iteration to run the algo.
	 *
	 * Returns
	 * -------
	 *  - minima (float): the minimum value of the function.*/

	float center;

	for (int i=0; i<epochs; i++) {
		center = (a0 + b0) / 2;

		if(df(center) > 0)
			b0 = center;
		else
			a0 = center;
	}

	return center;
}

float Method::Newton(float (f) (float), float (df) (float), float (ddf) (float), float x0, float eps){
	/*
	 * Newton Optimization Method Implementation.
	 *
	 * Parameters
	 * ----------
	 *  - f (func)    : the function to be optimized.
	 *  - df (func)   : the first derivative of function to be optimized.
	 *  - ddf (func)  : the second derivative of function to be optimized.
	 *  - x0 (float)  : the starting point of the function domain
	 *  - eps (float) : the error to compare the result to.
	 *
	 * Returns
	 * -------
	 *  - minima (float): the minimum value of the function.*/

	float xk;

	while (true) {
		xk = x0 - (df(x0)/ddf(x0));
		if((xk - x0) < eps) break;
		x0 = xk;
	}

	return xk;
}

float Method::Secant(float (f) (float), float (df) (float), float x0, float x1, float eps){
	/*
	 * Secant Optimization Method Implementation.
	 *
	 * Parameters
	 * ----------
	 *  - f (func)    : the function to be optimized.
	 *  - df (func)   : the first derivative of function to be optimized.
	 *  - x0 (float)  : the starting point of the function domain
	 *  - x1 (float)  : the next point of the function domain.
	 *  - eps (float) : the error to compare the result to.
	 *
	 * Returns
	 * -------
	 *  - minima (float): the minimum value of the function.*/

	float xk;

	while(true) {
		xk = (df(x1)*x0 - df(x0)*x1) / (df(x1) - df(x0));
		if((xk - x1 < eps)) break;
		x0 = x1;
		x1 = xk;
	}

	return xk;
}
