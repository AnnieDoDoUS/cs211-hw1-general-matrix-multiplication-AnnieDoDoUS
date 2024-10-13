# CS211 HW1 General Matrix Multiplication WenLing Yang

Name: Wen-Ling Yang (Annie Yang) <br>
Student ID: 862465675 <br>
Email: wyang106@ucr.edu <br> 
Github: https://github.com/AnnieDoDoUS/cs211-hw1-general-matrix-multiplication-AnnieDoDoUS <br>

* Q1:
  (a)
    ```
    void dgemm0(double *C,double *A,double *B,int n)
    {
        int i, j, k;
        for(i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    C[i * n + j] += A[i * n + k] * B[k * n + j];  
                    // C requires n multiplications and n−1 additions
                }
            }
        }
    }
    ```
    
    ```
    void dgemm1(double *C,double *A,double *B,int n)
    {
         // complete the missing code here
         int i, j, k;
         for(i = 0; i < n; i++) {
              for (j = 0; j < n; j++) {
    
                   register double r = C[i * n + j];
                   for (k = 0; k < n; k++) {
                        A[i * n + k] * B[k * n + j];
                   }
                   C[i * n + j] = r;
              }
         }
    }
    ```

    So, Total Execution time for dgemm0 and dgemm1 is :
    
$$
\frac{(n^2 (n + (n-1))}{4} * \frac{1}{freqency} ≈ \frac {2n^3}{4} * \frac{1}{freqency} = \frac{0.5 * 1000^3}{2 * 10^9} = 0.25 s
$$

* Q1:
  (b)
    ```
    void dgemm0(double *C,double *A,double *B,int n)
    {
        int i, j, k;
        for(i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    C[i * n + j] += A[i * n + k] * B[k * n + j];
                    // Reads = n^2 (n+n+1) = 2n^3 + n
                    // Writes = n^2
                    // Total = 2n^3 + 2n^2
                }
            }
        }
    }
    ```
    
    ```
    void dgemm1(double *C,double *A,double *B,int n)
    {
         // complete the missing code here
         int i, j, k;
         for(i = 0; i < n; i++) {
              for (j = 0; j < n; j++) {
    
                   register double r = C[i * n + j];
                   for (k = 0; k < n; k++) {
                        A[i * n + k] * B[k * n + j];
                   }
                   C[i * n + j] = r;
              }
         }
    }
    ```
    
    
    Total Memory Access Time for dgemm1:
    
$$
\frac{2n^3 + 2n^2 = 2 \times (1000^3) + 2 \times (1000^2)}{2 \times 10^9} \times 100 = 100.1 s
$$

* Q2
  
    
    
