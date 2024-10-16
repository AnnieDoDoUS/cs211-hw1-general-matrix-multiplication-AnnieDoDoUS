#define min(a,b) (((a)<(b))?(a):(b))

void dgemm7(double *C,double *A,double *B,int n)
{
    // complete the missing code here
    int i, j, k, ii, jj, kk;
    int block_size = 64;  // Cache block size, tweak for best performance.
    int reg_block_size = 4; // Register block size, adjust as needed.
    
    for (i = 0; i < n; i += block_size) {
        for (j = 0; j < n; j += block_size) {
            for (k = 0; k < n; k += block_size) {
                for (ii = i; ii < min(i + block_size, n); ii += reg_block_size) {
                    for (jj = j; jj < min(j + block_size, n); jj += reg_block_size) {
                        // Registers for a 4x4 block of C
                        register double C00, C01, C02, C03;
                        register double C10, C11, C12, C13;
                        register double C20, C21, C22, C23;
                        register double C30, C31, C32, C33;

                        // Initialize C registers from memory
                        C00 = C[ii*n + jj]; C01 = C[ii*n + jj + 1]; C02 = C[ii*n + jj + 2]; C03 = C[ii*n + jj + 3];
                        C10 = C[(ii+1)*n + jj]; C11 = C[(ii+1)*n + jj + 1]; C12 = C[(ii+1)*n + jj + 2]; C13 = C[(ii+1)*n + jj + 3];
                        C20 = C[(ii+2)*n + jj]; C21 = C[(ii+2)*n + jj + 1]; C22 = C[(ii+2)*n + jj + 2]; C23 = C[(ii+2)*n + jj + 3];
                        C30 = C[(ii+3)*n + jj]; C31 = C[(ii+3)*n + jj + 1]; C32 = C[(ii+3)*n + jj + 2]; C33 = C[(ii+3)*n + jj + 3];

                        for (kk = k; kk < min(k + block_size, n); kk += reg_block_size) {
                            // Load 4x4 block of A and B into registers
                            register double A00 = A[ii*n + kk], A01 = A[ii*n + kk + 1], A02 = A[ii*n + kk + 2], A03 = A[ii*n + kk + 3];
                            register double A10 = A[(ii+1)*n + kk], A11 = A[(ii+1)*n + kk + 1], A12 = A[(ii+1)*n + kk + 2], A13 = A[(ii+1)*n + kk + 3];
                            register double A20 = A[(ii+2)*n + kk], A21 = A[(ii+2)*n + kk + 1], A22 = A[(ii+2)*n + kk + 2], A23 = A[(ii+2)*n + kk + 3];
                            register double A30 = A[(ii+3)*n + kk], A31 = A[(ii+3)*n + kk + 1], A32 = A[(ii+3)*n + kk + 2], A33 = A[(ii+3)*n + kk + 3];

                            register double B00 = B[kk*n + jj], B01 = B[kk*n + jj + 1], B02 = B[kk*n + jj + 2], B03 = B[kk*n + jj + 3];
                            register double B10 = B[(kk+1)*n + jj], B11 = B[(kk+1)*n + jj + 1], B12 = B[(kk+1)*n + jj + 2], B13 = B[(kk+1)*n + jj + 3];
                            register double B20 = B[(kk+2)*n + jj], B21 = B[(kk+2)*n + jj + 1], B22 = B[(kk+2)*n + jj + 2], B23 = B[(kk+2)*n + jj + 3];
                            register double B30 = B[(kk+3)*n + jj], B31 = B[(kk+3)*n + jj + 1], B32 = B[(kk+3)*n + jj + 2], B33 = B[(kk+3)*n + jj + 3];

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
                        C[ii*n + jj] = C00; C[ii*n + jj + 1] = C01; C[ii*n + jj + 2] = C02; C[ii*n + jj + 3] = C03;
                        C[(ii+1)*n + jj] = C10; C[(ii+1)*n + jj + 1] = C11; C[(ii+1)*n + jj + 2] = C12; C[(ii+1)*n + jj + 3] = C13;
                        C[(ii+2)*n + jj] = C20; C[(ii+2)*n + jj + 1] = C21; C[(ii+2)*n + jj + 2] = C22; C[(ii+2)*n + jj + 3] = C23;
                        C[(ii+3)*n + jj] = C30; C[(ii+3)*n + jj + 1] = C31; C[(ii+3)*n + jj + 2] = C32; C[(ii+3)*n + jj + 3] = C33;
                    }
                }
            }
        }
    }
}
