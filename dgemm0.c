void dgemm0(double *C,double *A,double *B,int n)
{
    // complete the missing code here
    int i, j, k;
    for(i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (k = 0; k < n; k++) {
                C[i * n + j] += A[i * n + k] * B[k * n + j];
            }
        }
    }

}