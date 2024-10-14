void dgemm6_ijk(double *C,double *A,double *B,int n)
{
     // complete the missing code here
     int i, j, k;
     for (i=0; i<n; i++) {
          for (j=0; j<n; j++) {
               register double r = C[i*n+j];
               for (k=0; k<n; k++) {
                    r += A[i*n+k] * B[k*n+j];
               }
               C[i*n+j] = r;
          }
     }

}

void dgemm6_ijk2(double *C,double *A,double *B,int n)
{
     // complete the missing code here
     
}