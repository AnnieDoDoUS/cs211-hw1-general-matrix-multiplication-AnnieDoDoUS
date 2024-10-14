void dgemm3(double *C, double *A, double *B, int n) {
    int i, j, k;
    for (i = 0; i < n; i += 4) {
        for (j = 0; j < n; j += 4) {
            // Register allocation for a 4x4 block of C
            register double C00 = C[i*n + j], C01 = C[i*n + j + 1], C02 = C[i*n + j + 2], C03 = C[i*n + j + 3];
            register double C10 = C[(i+1)*n + j], C11 = C[(i+1)*n + j + 1], C12 = C[(i+1)*n + j + 2], C13 = C[(i+1)*n + j + 3];
            register double C20 = C[(i+2)*n + j], C21 = C[(i+2)*n + j + 1], C22 = C[(i+2)*n + j + 2], C23 = C[(i+2)*n + j + 3];
            register double C30 = C[(i+3)*n + j], C31 = C[(i+3)*n + j + 1], C32 = C[(i+3)*n + j + 2], C33 = C[(i+3)*n + j + 3];

            for (k = 0; k < n; k += 4) {
                // Load 4x4 block of A and B into registers
                register double A00 = A[i*n + k], A01 = A[i*n + k + 1], A02 = A[i*n + k + 2], A03 = A[i*n + k + 3];
                register double A10 = A[(i+1)*n + k], A11 = A[(i+1)*n + k + 1], A12 = A[(i+1)*n + k + 2], A13 = A[(i+1)*n + k + 3];
                register double A20 = A[(i+2)*n + k], A21 = A[(i+2)*n + k + 1], A22 = A[(i+2)*n + k + 2], A23 = A[(i+2)*n + k + 3];
                register double A30 = A[(i+3)*n + k], A31 = A[(i+3)*n + k + 1], A32 = A[(i+3)*n + k + 2], A33 = A[(i+3)*n + k + 3];

                register double B00 = B[k*n + j], B01 = B[k*n + j + 1], B02 = B[k*n + j + 2], B03 = B[k*n + j + 3];
                register double B10 = B[(k+1)*n + j], B11 = B[(k+1)*n + j + 1], B12 = B[(k+1)*n + j + 2], B13 = B[(k+1)*n + j + 3];
                register double B20 = B[(k+2)*n + j], B21 = B[(k+2)*n + j + 1], B22 = B[(k+2)*n + j + 2], B23 = B[(k+2)*n + j + 3];
                register double B30 = B[(k+3)*n + j], B31 = B[(k+3)*n + j + 1], B32 = B[(k+3)*n + j + 2], B33 = B[(k+3)*n + j + 3];

                // Compute block multiplication and accumulate into C registers
                C00 += A00 * B00 + A01 * B10 + A02 * B20 + A03 * B30;
                C01 += A00 * B01 + A01 * B11 + A02 * B21 + A03 * B31;
                C02 += A00 * B02 + A01 * B12 + A02 * B22 + A03 * B32;
                C03 += A00 * B03 + A01 * B13 + A02 * B23 + A03 * B33;

                C10 += A10 * B00 + A11 * B10 + A12 * B20 + A13 * B30;
                C11 += A10 * B01 + A11 * B11 + A12 * B21 + A13 * B31;
                C12 += A10 * B02 + A11 * B12 + A12 * B22 + A13 * B32;
                C13 += A10 * B03 + A11 * B13 + A12 * B23 + A13 * B33;

                C20 += A20 * B00 + A21 * B10 + A22 * B20 + A23 * B30;
                C21 += A20 * B01 + A21 * B11 + A22 * B21 + A23 * B31;
                C22 += A20 * B02 + A21 * B12 + A22 * B22 + A23 * B32;
                C23 += A20 * B03 + A21 * B13 + A22 * B23 + A23 * B33;

                C30 += A30 * B00 + A31 * B10 + A32 * B20 + A33 * B30;
                C31 += A30 * B01 + A31 * B11 + A32 * B21 + A33 * B31;
                C32 += A30 * B02 + A31 * B12 + A32 * B22 + A33 * B32;
                C33 += A30 * B03 + A31 * B13 + A32 * B23 + A33 * B33;
            }

            // Store the results back into the C matrix
            C[i*n + j] = C00;
            C[i*n + j + 1] = C01;
            C[i*n + j + 2] = C02;
            C[i*n + j + 3] = C03;

            C[(i+1)*n + j] = C10;
            C[(i+1)*n + j + 1] = C11;
            C[(i+1)*n + j + 2] = C12;
            C[(i+1)*n + j + 3] = C13;

            C[(i+2)*n + j] = C20;
            C[(i+2)*n + j + 1] = C21;
            C[(i+2)*n + j + 2] = C22;
            C[(i+2)*n + j + 3] = C23;

            C[(i+3)*n + j] = C30;
            C[(i+3)*n + j + 1] = C31;
            C[(i+3)*n + j + 2] = C32;
            C[(i+3)*n + j + 3] = C33;
        }
    }
}
