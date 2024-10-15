void dgemm6_ikj(double *C,double *A,double *B,int n)
{
    // complete the missing code here
    int i, k, j;
    for (i=0; i<n; i++) {
        for (k=0; k<n; k++) {
            register double r = C[i*n+k];
            for (j=0; j<n; j++) {
                r += A[i*n+j] * B[j*n+k];
            }
            C[i*n+k] = r;
        }
    }

}

void dgemm6_ikj2(double *C,double *A,double *B,int n)
{
    // complete the missing code here
     
}