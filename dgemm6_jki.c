void dgemm6_jki(double *C,double *A,double *B,int n)
{
    // complete the missing code here
    int j, k, i;
    for (j=0; j<n; j++) {
        for (k=0; k<n; k++) {
            register double r = C[j*n+k];
            for (i=0; i<n; i++) {
                r += A[j*n+i] * B[i*n+k];
            }
            C[j*n+k] = r;
        }
    }
}

void dgemm6_jki2(double *C,double *A,double *B,int n)
{
    // complete the missing code here
    int i, ii, j, jj, k, kk;
    int b = 1;
    for (j=0; j<n; j+=b) {
        for (k=0; k<n; k+=b) {
            for (i=0; i<n; i+=b) {
                for (jj=j; jj<j+b; jj++) {
                        for (kk=k; kk<k+b; kk++) {
                            register double r = C[jj*n+kk];
                            for (ii=i; ii<i+b; ii++) {
                                r += A[jj*n+ii] * B[ii*n+kk];
                            }
                            C[jj*n+kk] = r;
                        }
                }
            }
        }
    }

}