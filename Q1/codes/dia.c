// function to find the coordinates of point A
void find_coordinates(float Bx, float By, float Cx, float Cy, float *Ax, float *Ay) {
    *Ax = 2 * Cx - Bx;
    *Ay = 2 * Cy - By;
}

// Sample usage
#include <stdio.h>

int main() {
    float Bx = 2, By = 6;
    float Cx = 3, Cy = -1;
    float Ax, Ay;
    
    find_coordinates(Bx, By, Cx, Cy, &Ax, &Ay);

    printf("The coordinates of point A are: (%.2f, %.2f)\n", Ax, Ay);

    return 0;
}
