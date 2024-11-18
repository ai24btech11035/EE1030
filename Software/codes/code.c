#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to perform matrix multiplication: C = A * B
void matrixMultiply(double **A, double **B, double **result, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            result[i][j] = 0;
            for (int k = 0; k < n; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

// Function to perform QR decomposition (simplified for any square matrix)
void qrDecomposition(double **A, double **Q, double **R, int n) {
    // Initialize Q and R matrices
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            Q[i][j] = A[i][j];
            R[i][j] = 0;
        }
    }

    // QR Decomposition using Gram-Schmidt process
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            double dotProduct = 0;
            for (int k = 0; k < n; k++) {
                dotProduct += Q[k][i] * Q[k][j];
            }
            R[j][i] = dotProduct;
            for (int k = 0; k < n; k++) {
                Q[k][i] -= R[j][i] * Q[k][j];
            }
        }
        double norm = 0;
        for (int k = 0; k < n; k++) {
            norm += Q[k][i] * Q[k][i];
        }
        norm = sqrt(norm);
        R[i][i] = norm;
        for (int k = 0; k < n; k++) {
            Q[k][i] /= norm;
        }
    }
}

// Function to compute eigenvalues using the QR algorithm
void qrAlgorithm(double **A, double *eigenvalues, int n, int maxIterations) {
    double **Q = (double **)malloc(n * sizeof(double *));
    double **R = (double **)malloc(n * sizeof(double *));
    double **A_new = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        Q[i] = (double *)malloc(n * sizeof(double));
        R[i] = (double *)malloc(n * sizeof(double));
        A_new[i] = (double *)malloc(n * sizeof(double));
    }

    // Iterate QR decomposition process to approximate eigenvalues
    for (int iter = 0; iter < maxIterations; iter++) {
        qrDecomposition(A, Q, R, n);

        // A_new = R * Q
        matrixMultiply(R, Q, A_new, n);

        // Copy A_new to A
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                A[i][j] = A_new[i][j];
            }
        }
    }

    // Extract eigenvalues from the diagonal of A (as it becomes upper triangular)
    for (int i = 0; i < n; i++) {
        eigenvalues[i] = A[i][i];
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(Q[i]);
        free(R[i]);
        free(A_new[i]);
    }
    free(Q);
    free(R);
    free(A_new);
}

int main() {
    int n;

    // Get matrix size
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);

    // Dynamically allocate memory for the matrix
    double **A = (double **)malloc(n * sizeof(double *));
    for (int i = 0; i < n; i++) {
        A[i] = (double *)malloc(n * sizeof(double));
    }

    // Input matrix from the user
    printf("Enter the elements of the matrix row by row:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    // Array to store the eigenvalues
    double *eigenvalues = (double *)malloc(n * sizeof(double));

    // Run QR algorithm
    int maxIterations = 100;
    qrAlgorithm(A, eigenvalues, n, maxIterations);

    // Output the eigenvalues
    printf("Eigenvalues of the matrix are:\n");
    for (int i = 0; i < n; i++) {
        printf("%lf\n", eigenvalues[i]);
    }

    // Free dynamically allocated memory
    for (int i = 0; i < n; i++) {
        free(A[i]);
    }
    free(A);
    free(eigenvalues);

    return 0;
}
