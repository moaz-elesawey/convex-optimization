#include "Methods.h"
#include "Global.h"

#include <stdio.h>
#include <stdlib.h>

#define QUIT_TYPE      0

#define GOLDEN_TYPE    1
#define BISECTION_TYPE 2
#define NEWTON_TYPE    3
#define SECANT_TYPE    4


int main(int argc, char **argv) {

    int type = QUIT_TYPE;
    int epochs;

    float eps, a0, b0, x0, x1;

    do {
        printf("Enter the type you want : \n");
        printf("  1) Golden Section Method\n");
        printf("  2) BiSection Method\n");
        printf("  3) Newton Method\n");
        printf("  4) Secant Method\n");
        printf("  0) Quit\n");
        printf(">>> ");
        scanf("%i", &type);

        switch(type) {
            case GOLDEN_TYPE   :
                printf("Using Golden Method\n");
                printf("Now Entery the a0, b0, and eps separated with space\n>>> ");
                scanf("%f %f %f", &a0, &b0, &eps);
                GoldenMinimize(f, a0, b0, eps);
                break;
            case BISECTION_TYPE:
                printf("Using BiSection Method\n");
                printf("Now Entery the a0, b0, and number of iterations separated with space\n>>> ");
                scanf("%f %f %d", &a0, &b0, &epochs);
                BiSectionMinimize(f, df, a0, b0, epochs);
                break;
            case NEWTON_TYPE   :
                printf("Using Newton Method\n");
                printf("Now Enter the x1 and eps separated with space\n>>> ");
                scanf("%f %f", &x0, &eps);
                NewtonMinimize(f, df, ddf, x0, eps);
                break;
            case SECANT_TYPE   :
                printf("Using Secant Method\n");
                printf("Now Enter the x1, x2, and eps separated with space\n>>> ");
                scanf("%f %f %f", &x0, &x1, &eps);
                SecantMinimize(f, df, x0, x1, eps);
                break;
            case QUIT_TYPE:
                printf("bye bye\n");
                exit(EXIT_SUCCESS);
                break;
        }
    } while(type != 0);


    return EXIT_SUCCESS;
}

