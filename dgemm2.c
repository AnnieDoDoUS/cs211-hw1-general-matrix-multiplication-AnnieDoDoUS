void dgemm2(double *C,double *A,double *B,int n)
{
    // Complete the missing Code here
    int i, j, k;
    for (i = 0; i < n; i+=2) {
        for (j = 0; j < n; j+=2) {
            register int t = i*n+j; register int tt = t+n;
            register double C00 = C[t]; register double C01 = C[t+1]; register double C10 = C[tt]; register double C11 = C[tt+1];

            for (k = 0; k < n; k+=2) {
                register int tA = i*n+k; register int ttA = tA+n; register int tB = k*n+j; register int ttB = tB+n;
                register double A00 = A[tA]; register double A01 = A[tA+1]; register double A10 = A[ttA]; register double A11 = A[ttA+1];
                register double B00 = B[tB]; register double B01 = B[tB+1]; register double B10 = B[ttB]; register double B11 = B[ttB+1];
                C00 += A00*B00 + A01*B10;
                C01 += A00*B01 + A01*B11;
                C10 += A10*B00 + A11*B10;
                C11 += A10*B01 + A11*B11;
            }

            C[t] = C00;
            C[t+1] = C01;
            C[tt] = C10;
            C[tt+1] = C11;
        }
    }
     
}