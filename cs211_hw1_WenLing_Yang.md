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

* Q4 <br>
Cache lines: 60 <br>
Line size: 10 doubles <br>
Total cache size:  60×10=600 doubles <br>
Total cache size in bytes:  600×8 bytes (since a double is 8 bytes) = 4800 bytes <br>

Reads: <br>

$$
A = B = C = n^2 = 10^2 = 100
$$

Cache Misses: <br>

Each access to 
A and B will be a cache miss for the first access of each element in a row or column, leading to higher misses. <br>
For C, since we access it in a linear fashion, the cache may keep the previous accesses, resulting in fewer misses. <br>

Overall reads: 100+100+100=300 reads. <br>
Overall misses: 10+10+10=30 misses. <br>
Overall miss rate: 30/300=0.1=10%

| Loop Order | # of Reads (A) | # of Misses (A) | # of Reads (B) | # of Misses (B) | # of Reads (C) | # of Misses (C) | Overall Miss Rate |
|------------|----------------|-----------------|----------------|-----------------|----------------|-----------------|------------------|
| ijk        | 100            | 10              | 100            | 10              | 100            | 10              | 30%              |
| ikj        | 100            | 10              | 100            | 10              | 100            | 10              | 30%              |
| jik        | 100            | 10              | 100            | 10              | 100            | 10              | 30%              |
| jki        | 100            | 10              | 100            | 10              | 100            | 10              | 30%              |
| kij        | 100            | 10              | 100            | 10              | 100            | 10              | 30%              |
| kji        | 100            | 10              | 100            | 10              | 100            | 10              | 30%              |


Reads: <br>

$$
A = B = C = n^2 = 10000^2 = 100,000,000
$$

Cache Misses: <br>

Each access to 
A and B will be a cache miss for the first access of each element in a row or column, leading to higher misses. <br>
For C, since we access it in a linear fashion, the cache may keep the previous accesses, resulting in fewer misses. <br>

Overall reads: 100,000,000+100,000,000+100,000,000=300,000,000 reads. <br>
Overall misses: 10,000+10,000+10,000=30,000 misses. <br>
Overall miss rate: 30,000/300,000,000=0.0001=0.01%

| Loop Order | # of Reads (A)  | # of Misses (A)  | # of Reads (B)  | # of Misses (B)  | # of Reads (C)  | # of Misses (C)  | Overall Miss Rate |
|------------|-----------------|------------------|-----------------|------------------|-----------------|------------------|-------------------|
| ijk        | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 0.01%             |
| ikj        | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 0.01%             |
| jik        | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 0.01%             |
| jki        | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 0.01%             |
| kij        | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 0.01%             |
| kji        | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 100,000,000     | 10,000           | 0.01%             |

* Q5

Reads: <br>

$$
A = B = C = n^2 = 10000^2 = 100,000,000
$$

Cache Misses: <br>

Each access to 
A and B will be a cache miss for the first access of each element in a row or column, leading to higher misses. <br>
For C, since we access it in a linear fashion, the cache may keep the previous accesses, resulting in fewer misses. <br>

10000/10×1000=1,000,000 misses.

Overall reads: 100,000,000+100,000,000+100,000,000=300,000,000 reads. <br>
Overall misses: 1,000,000+1,000,000+1,000,000=3,000,000 misses. <br>
Overall miss rate: 3,000,000/300,000,000=1% <br>

| Loop Order | # of Reads (A)  | # of Misses (A)  | # of Reads (B)  | # of Misses (B)  | # of Reads (C)  | # of Misses (C)  | Overall Miss Rate |
|------------|-----------------|------------------|-----------------|------------------|-----------------|------------------|-------------------|
| ijk-ijk    | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 1%                |
| ikj-ikj    | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 1%                |
| jik-jik    | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 1%                |
| jki-jki    | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 1%                |
| kij-kij    | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 1%                |
| kji-kji    | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 100,000,000     | 1,000,000        | 1%                |

Cache Misses for Specific Elements in kji-kji Loop Order: <br>
  * A[0][0]:
    * Accesses: Multiple accesses occur throughout the algorithm, but the first time it’s accessed, it will incur a cache miss.
    * Since kji processes A in block size steps, after the first block load, there won’t be additional misses unless the element is evicted from cache.
  * A[17][21]:
    * Accesses: The element lies in the second row and third column of block(2,3).
    * During the first access, it will miss, but subsequent accesses within the block will hit unless evicted.
  * B[100][130]:
    * Accesses: The element lies in block(10,13).
    * The first access to the block containing A[100][130] will miss, but as long as it stays in cache, further accesses within the block will hit.
  * B[101][134]:
    * Accesses: The element lies in block(10,13).
    * The first access to the block containing A[101][134] will miss, but as long as it stays in cache, further accesses within the block will hit.
  * C[68][90]:
    * Accesses: The element lies in block(6,9).
    * The first access to the block will miss, but as long as it stays in cache, further accesses within the block will hit.
  * C[2000][1297]:
    * Accesses: The element lies in block(200,129).
    * The first access to the block will miss, but as long as it stays in cache, further accesses within the block will hit.
   
* Q6 Comaprision between B=1 and B=16 <br>

|              | B=1            | B=16             | B=32             |
|--------------|----------------|------------------|------------------|
| dgemm6_ijk   | 128.988007s     | 119.609518s      | 122.072120s      |
| dgemm6_ikj   | 128.898859s     | 120.963045s      | 141.959694s      |
| dgemm6_jik   | 126.398836s     | 143.299494s      | 126.030516s      |
| dgemm6_jki   | 143.906027s     | 123.782810s      | 120.327437s      |
| dgemm6_kij   | 135.502527s     | 126.305426s      | 129.727163s      |
| dgemm6_kji   | 142.615004s     | 136.297260s      | 117.516099s      |
| dgemm6_ijk2  | 329.795878s     | 26.171977s       | 24.557966s       |
| dgemm6_ikj2  | 356.067277s     | 25.938468s       | 24.177801s       |
| dgemm6_jik2  | 306.577190s     | 26.350476s       | 26.291500s       |
| dgemm6_jki2  | 332.990690s     | 25.964630s       | 24.214335s       |
| dgemm6_kij2  | 366.695189s     | 25.901513s       | 24.245034s       |
| dgemm6_kji2  | 316.064129s     | 26.019614s       | 24.207078s       |


For the block version, moderate performance improvements are observed as block size increases, but gains are limited due to inefficient cache usage, especially for larger matrices. In addition, cache misses remain higher, resulting in longer execution times compared to the blocked version, especially for larger block sizes. <br>

For the non-block version, significant performance gains are achieved by optimizing cache and register blocking, with dramatic speedups as block size increases from B=1 to B=16. Furthermore, efficient cache utilization greatly reduces memory access times, making the blocked version much faster, with further optimization seen at B=32.



