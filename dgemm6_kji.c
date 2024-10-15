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
    int i, ii, j, jj, k, kk;
    int b = 1;
    for (k=0; k<n; k+=b) {
        for (j=0; j<n; j+=b) {
            for (i=0; i<n; i+=b) {
                for (kk=k; kk<k+b; kk++) {
                        for (jj=j; jj<j+b; jj++) {
                            register double r = C[kk*n+jj];
                            for (ii=i; ii<i+b; ii++) {
                                r += A[kk*n+ii] * B[ii*n+jj];
                            }
                            C[kk*n+jj] = r;
                        }
                }
            }
        }
    }

}