void func_call(char *func_name,double *C,double *A,double *B,int n)
{
    if (strcmp(func_name,"dgemm0")==0)  dgemm0(C,A,B,n);
    if (strcmp(func_name,"dgemm1")==0)  dgemm1(C,A,B,n);
    if (strcmp(func_name,"dgemm2")==0)  dgemm2(C,A,B,n);
    if (strcmp(func_name,"dgemm3")==0)  dgemm3(C,A,B,n);
    if (strcmp(func_name,"dgemm6_ijk")==0)  dgemm6_ijk(C,A,B,n);
    if (strcmp(func_name,"dgemm6_ikj")==0)  dgemm6_ikj(C,A,B,n);
    if (strcmp(func_name,"dgemm6_jik")==0)  dgemm6_jik(C,A,B,n);
    if (strcmp(func_name,"dgemm6_jki")==0)  dgemm6_jki(C,A,B,n);
    if (strcmp(func_name,"dgemm6_kij")==0)  dgemm6_kij(C,A,B,n);
    if (strcmp(func_name,"dgemm6_kji")==0)  dgemm6_kji(C,A,B,n);
    if (strcmp(func_name,"dgemm6_ijk2")==0) dgemm6_ijk2(C,A,B,n);
    if (strcmp(func_name,"dgemm6_ikj2")==0) dgemm6_ikj2(C,A,B,n);
    if (strcmp(func_name,"dgemm6_jik2")==0) dgemm6_jik2(C,A,B,n);
    if (strcmp(func_name,"dgemm6_jki2")==0) dgemm6_jki2(C,A,B,n);
    if (strcmp(func_name,"dgemm6_kij2")==0) dgemm6_kij2(C,A,B,n);
    if (strcmp(func_name,"dgemm6_kji2")==0) dgemm6_kji2(C,A,B,n);
    if (strcmp(func_name,"dgemm7")==0)  dgemm7(C,A,B,n);
}