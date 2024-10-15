void dgemm6_kij(double *C,double *A,double *B,int n)
{
    // complete the missing code here
    int k, i, j;
    for (k=0; k<n; k++) {
        for (i=0; i<n; i++) {
            register double r = C[k*n+i];
            for (j=0; j<n; j++) {
                r += A[k*n+j] * B[j*n+i];
            }
            C[k*n+i] = r;
        }
    }
}

void dgemm6_kij2(double *C,double *A,double *B,int n)
{
   // complete the missing code here
     
}