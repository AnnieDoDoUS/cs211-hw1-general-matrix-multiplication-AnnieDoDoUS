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
    int i, ii, j, jj, k, kk;
    int b = 1;
    for (k=0; k<n; k+=b) {
        for (i=0; i<n; i+=b) {
            for (j=0; j<n; j+=b) {
                for (kk=k; kk<k+b; kk++) {
                        for (ii=i; ii<i+b; ii++) {
                            register double r = C[kk*n+ii];
                            for (jj=j; jj<j+b; jj++) {
                                r += A[kk*n+jj] * B[jj*n+ii];
                            }
                            C[kk*n+ii] = r;
                        }
                }
            }
        }
    }

}