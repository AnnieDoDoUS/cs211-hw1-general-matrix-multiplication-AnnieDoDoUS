void name_check(char *func_name)
{
    bool valid_name=false;
    valid_name|=(strcmp("dgemm0",func_name)==0);
    valid_name|=(strcmp("dgemm1",func_name)==0);
    valid_name|=(strcmp("dgemm2",func_name)==0);
    valid_name|=(strcmp("dgemm3",func_name)==0);
    valid_name|=((strcmp("dgemm6_ijk",func_name)==0) || (strcmp("dgemm6_ijk2",func_name)==0));
    valid_name|=((strcmp("dgemm6_ikj",func_name)==0) || (strcmp("dgemm6_ikj2",func_name)==0));
    valid_name|=((strcmp("dgemm6_jik",func_name)==0) || (strcmp("dgemm6_jik2",func_name)==0));
    valid_name|=((strcmp("dgemm6_jki",func_name)==0) || (strcmp("dgemm6_jki2",func_name)==0));
    valid_name|=((strcmp("dgemm6_kij",func_name)==0) || (strcmp("dgemm6_kij2",func_name)==0));
    valid_name|=((strcmp("dgemm6_kji",func_name)==0) || (strcmp("dgemm6_kji2",func_name)==0));
    valid_name|=(strcmp("dgemm7",func_name)==0);
    if (!valid_name)
    {
        printf("Invalid function name\n");
        exit(0);
    }
}