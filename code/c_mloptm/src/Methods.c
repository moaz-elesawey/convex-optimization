#include "Methods.h"


float GoldenMinimize(float (*f)(float), float a0, float b0, float eps){
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

    int N = ceil( log(eps/2) / log(1-RO) );

    float a1, b1;

    /* Print Header */
    printf("\nUsing Golden Method with [%d] Iteration\n", N);
    printf("--------------------------------------------\n");
    printf("%8s %8s %8s %8s %8s\n", "a0", "b0", "a1", "b1", "Minima");
    printf("--------------------------------------------\n");

    for (int i=0; i<N; i++) {
        a1 = a0 + RO * (b0 - a0);
        b1 = b0 - RO * (b0 - a0);

        if(f(b1) > f(a1))
            b0 = b1;
        else
            a0 = a1;

        /* Print Steps */
        printf("%8.4f %8.4f %8.4f %8.4f %8.4f\n", a0, b0, a1, b1, (a0+b0)/2);
    }
    printf("--------------------------------------------\n\n");

    float minima = (a0 + b0) / 2.0;
    printf("Minima is -> {%8.5f}\n\n", minima);

    return minima;
}

float BiSectionMinimize(float (*f)(float), float(*df)(float), float a0, float b0, int epochs){
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

    float minima;

    /* Print Header */
    printf("\nUsing BiSection Method\n");
    printf("-------------------------------------------\n");
    printf("%8s %8s %10s %14s\n", "a0", "b0", "(a0+b0)/2", "f'((a0+b0)/2)");
    printf("-------------------------------------------\n");


    for(int i=0; i<epochs; i++) {
        minima = (a0 + b0) / 2;

        if(df(minima) > 0)
            b0 = minima;
        else
            a0 = minima;

        /* Print Steps */
        printf("%8.4f %8.4f %10.4f %14.4f\n", a0, b0, (a0+b0)/2, df((a0+b0)/2));
    }
    printf("-------------------------------------------\n");
    printf("Minima is -> {%8.5f}\n\n", minima);

    return minima;
}

float NewtonMinimize(float (*f)(float), float (*df)(float), float (*ddf)(float), float x0, float eps){
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

    /* Print Header */
    printf("\nUsing Newton Method\n");
    printf("---------------------------------------\n");
    printf("%8s %8s %10s %10s\n", "xk", "xk+1", "f'(xk+1)", "f''(xk+1)");
    printf("---------------------------------------\n");

    while (1) {
        xk = x0 - ( df(x0) / ddf(x0) );

        if(xk - x0 < eps)
            break;

        x0 = xk;

        /* Print Steps */
        printf("%8.4f %8.4f %10.4f %10.4f\n", x0, xk, df(xk), ddf(xk));
    }
    printf("---------------------------------------\n");
    printf("Minima is -> {%8.5f}\n\n", xk);

    return xk;
}

float SecantMinimize(float (*f)(float), float (*df)(float), float x0, float x1, float eps){
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

    /* Print Header */
    printf("\nUsing Secant Method\n");
    printf("---------------------------------------\n");
    printf("%8s %8s %10s %10s\n", "xk", "xk+1", "f(xk+1)", "f'(xk+1)");
    printf("---------------------------------------\n");


    while (1) {
        xk = ( df(x1)*x0 - df(x0)*x1 ) / (df(x1) - df(x0));

        if(xk - x1 < eps)
            break;

        x0 = x1;
        x1 = xk;

        /* Print Steps */
        printf("%8.4f %8.4f %10.4f %10.4f\n", x1, xk, f(xk), df(xk));
    }
    printf("---------------------------------------\n");
    printf("Minima is -> {%8.5f}\n\n", xk);

    return xk;
}

