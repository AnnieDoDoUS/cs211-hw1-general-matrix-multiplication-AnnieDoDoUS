void dgemm6_jik(double *C,double *A,double *B,int n)
{
    // complete the missing code here
    int j, i, k;
    for (j=0; j<n; j++) {
        for (i=0; i<n; i++) {
            register double r = C[j*n+i];
            for (k=0; k<n; k++) {
                r += A[j*n+k] * B[k*n+i];
            }
            C[j*n+i] = r;
        }
    }

}

void dgemm6_jik2(double *C,double *A,double *B,int n)
{
    // complete the missing code here
    int i, ii, j, jj, k, kk;
    int b = 64;
    for (j=0; j<n; j+=b) {
        for (i=0; i<n; i+=b) {
            for (k=0; k<n; k+=b) {
                for (jj=j; jj<j+b; jj++) {
                        for (ii=i; ii<i+b; ii++) {
                            register double r = C[jj*n+ii];
                            for (kk=k; kk<k+b; kk++) {
                                r += A[jj*n+kk] * B[kk*n+ii];
                            }
                            C[jj*n+ii] = r;
                        }
                }
            }
        }
    }

}