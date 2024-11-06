#include <stdio.h>
#include <stdlib.h>
#include <math.h>   // For cos, sin, sqrt, etc.                                       
#include "libs/matfun.h"
#include "libs/geofun.h"		    

int main() {
    double **A = createMat(2, 1);
    double **B = createMat(2, 1);

    A[0][0] = 4;
    A[1][0] = -8;

    B[0][0] = 2;
    B[1][0] = 6;

    double **C = Matsec(A, B, 2, 1.0);

    printf("The center of the circle (midpoint of A and B) is: \n");
    printMat(C, 2, 1);

    free(A);
    free(B);
    free(C);

    return 0;
}
