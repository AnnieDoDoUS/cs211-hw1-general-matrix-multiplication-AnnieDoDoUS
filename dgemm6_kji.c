void dgemm6_kji(double *C,double *A,double *B,int n)
{
    // complete the missing code here
    int k, j, i;
    for (k=0; k<n; k++) {
        for (j=0; j<n; j++) {
            register double r = C[k*n+j];
            for (i=0; i<n; i++) {
                r += A[k*n+i] * B[i*n+j];
            }
            C[k*n+j] = r;
        }
    }
}

void dgemm6_kji2(double *C,double *A,double *B,int n)
{
    // complete the missing code here
     
}