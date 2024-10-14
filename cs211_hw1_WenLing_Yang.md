# CS211 HW1 General Matrix Multiplication WenLing Yang

Name: Wen-Ling Yang (Annie Yang) <br>
Student ID: 862465675 <br>
Email: wyang106@ucr.edu <br> 
Github: https://github.com/AnnieDoDoUS/cs211-hw1-general-matrix-multiplication-AnnieDoDoUS <br>

* Q1:
  (a) Execution Time
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
  (a) Memory Access Time
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

* Q1 
  (b) Execution Time
  
| Execution Time | 64 | 128 | 256 | 512 | 1024 | 2048 |
|---|----|-----|-----|-----|------|------|
| dgemm0 | 0.001075s | 0.009661s | 0.084302s | 1.193762s | 8.766151s | 221.226112s |
| dgemm1 | 0.000728s | 0.006139s | 0.053353s | 0.790494s | 5.929604s | 127.803676s |

* Q1 
  (b) Performance
  
$$
Performance = \frac{2n^3}{Execution Time * 10^9}
$$


| Performance | 64 | 128 | 256 | 512 | 1024 | 2048 |
|---|----|-----|-----|-----|------|------|
| dgemm0 | 0.4877Gflops | 0.2171Gflops | 0.1989Gflops | 0.1124Gflops | 0.1224Gflops | 0.0388Gflops |
| dgemm1 | 0.7202Gflops | 0.3416Gflops | 0.3144Gflops | 0.1698Gflops | 0.1811Gflops | 0.0672Gflops |

* Q2 Execution Time

| Execution Time | 64 | 128 | 256 | 512 | 1024 | 2048 |
|---|----|-----|-----|-----|------|------|
| dgemm2 | 0.000240s | 0.002010s | 0.017444s | 0.229982s | 1.765096s | 37.342902s |

* Q2 Performance

| Performance | 64 | 128 | 256 | 512 | 1024 | 2048 |
|---|----|-----|-----|-----|------|------|
| dgemm2 | 2.18Gflops | 1.04Gflops | 0.96Gflops | 0.58Gflops | 0.61Gflops | 0.23Gflops |

* Q3 Execution Time

| Execution Time | 64 | 128 | 256 | 512 | 1024 | 2048 |
|---|----|-----|-----|-----|------|------|
| dgemm3 | 0.000205s | 0.001575s | 0.015630s | 0.139561s | 1.087911s | 18.238840s |

* Q3 Performance

| Performance | 64 | 128 | 256 | 512 | 1024 | 2048 |
|---|----|-----|-----|-----|------|------|
| dgemm0 | 0.4877Gflops | 0.2171Gflops | 0.1989Gflops | 0.1124Gflops | 0.1224Gflops | 0.0388Gflops |
| dgemm1 | 0.7202Gflops | 0.3416Gflops | 0.3144Gflops | 0.1698Gflops | 0.1811Gflops | 0.0672Gflops |
| dgemm2 | 2.18Gflops | 1.04Gflops | 0.96Gflops | 0.58Gflops | 0.61Gflops | 0.23Gflops |
| dgemm3 | 2.558Gflops | 2.663Gflops | 2.147Gflops | 1.923Gflops | 1.923Gflops | 0.942Gflops |

The iterative improvements in register utilization and algorithm optimization from dgemm0 to dgemm3 lead to significant performance gains in floating-point operations, demonstrating the importance of efficient coding practices in high-performance computing.
