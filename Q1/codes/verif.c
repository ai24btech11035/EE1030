#include <stdio.h>
#include <stdlib.h>

// Function declarations from your reference
double **createMat(int m, int n); // Create m x n matrix array
double **Matscale(double **a, int m, int n, double k); // Scale matrix
double **Matadd(double **a, double **b, int m, int n); // Add two matrices
double **Matsec(double **a, double **b, int m, double k); // Section formula
void printMat(double **p, int m, int n); // Print matrix

// Main function
int main() {
    // Define points A and B
    double **A = createMat(2, 1); // Point A
    double **B = createMat(2, 1); // Point B
    
    // Coordinates of A (4, -8) and B (2, 6)
    A[0][0] = 4;
    A[1][0] = -8;
    
    B[0][0] = 2;
    B[1][0] = 6;

    // Using section formula to find midpoint (ratio 1:1)
    double **C = Matsec(A, B, 2, 1.0); // Midpoint of A and B
    
    // Output the center point
    printf("The center of the circle (midpoint of A and B) is: \n");
    printMat(C, 2, 1);

    // Free allocated memory
    free(A);
    free(B);
    free(C);

    return 0;
}

// Create m x n matrix array
double **createMat(int m, int n) {
    double **a = (double **)malloc(m * sizeof(double *));
    for (int i = 0; i < m; i++) {
        a[i] = (double *)malloc(n * sizeof(double));
    }
    return a;
}

// Scale matrix
double **Matscale(double **a, int m, int n, double k) {
    double **c = createMat(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = k * a[i][j];
        }
    }
    return c;
}

// Add two matrices
double **Matadd(double **a, double **b, int m, int n) {
    double **c = createMat(m, n);
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            c[i][j] = a[i][j] + b[i][j];
        }
    }
    return c;
}

// Section formula: divide a line segment AB in ratio k:1
double **Matsec(double **a, double **b, int m, double k) {
    double **temp = createMat(m, 1);
    temp = Matscale(Matadd(a, Matscale(b, m, 1, k), m, 1), m, 1, 1 / (k + 1));
    return temp;
}

// Print matrix
void printMat(double **p, int m, int n) {
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%lf ", p[i][j]);
        }
        printf("\n");
    }
}
