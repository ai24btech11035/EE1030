// function to find the coordinates of point A
void find_coordinates(float Bx, float By, float Cx, float Cy, float *Ax, float *Ay) {
    *Ax = 2 * Cx - Bx;
    *Ay = 2 * Cy - By;
}

// Sample usage
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "libs/matfun.h"
#include "libs/geofun.h"
int main() {
    float Bx = 2, By = 6;
    float Cx = 3, Cy = -1;
    float Ax, Ay;
    
    find_coordinates(Bx, By, Cx, Cy, &Ax, &Ay);

    printf("The coordinates of point A are: (%.2f, %.2f)\n", Ax, Ay);

    return 0;
}
