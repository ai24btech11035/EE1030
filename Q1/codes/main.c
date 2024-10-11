#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#include "libs/matfun.h"
#include "libs/geofun.h"
void find_coordinates(float, float, float, float, float*, float*);

int main(void)
{
    float Ax, Ay;
    find_coordinates(2, 6, 3, -1, &Ax, &Ay);
    printf("The coordinates of point A are: (%.2f, %.2f)\n", Ax, Ay);
    return 0;
}

void find_coordinates(float Bx, float By, float Cx, float Cy, float *Ax, float *Ay)
{
    *Ax = 2 * Cx - Bx;
    *Ay = 2 * Cy - By;
}

