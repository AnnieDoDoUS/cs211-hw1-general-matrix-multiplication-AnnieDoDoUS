import os

os.system("make")
for i in range(6,11):
   os.system("srun main dgemm0 "+str(2**i)+" 1")
for i in range(6,11):
   os.system("srun main dgemm1 "+str(2**i)+" 1")
for i in range(6,12):
    os.system("srun main dgemm2 "+str(2**i)+" 1")
for i in range(6,12):
    os.system("srun main dgemm3 "+str(2**i)+" 1")
os.system("srun main dgemm6_ijk 2048 1")
os.system("srun main dgemm6_ikj 2048 1")
os.system("srun main dgemm6_jik 2048 1")
os.system("srun main dgemm6_jki 2048 1")
os.system("srun main dgemm6_kij 2048 1")
os.system("srun main dgemm6_kji 2048 1")
os.system("srun main dgemm6_ijk2 2048 1")
os.system("srun main dgemm6_ikj2 2048 1")
os.system("srun main dgemm6_jik2 2048 1")
os.system("srun main dgemm6_jki2 2048 1")
os.system("srun main dgemm6_kij2 2048 1")
os.system("srun main dgemm6_kji2 2048 1")
for i in range(0,4):
    os.system("gcc main.c -o main -O"+str(i))
    os.system("srun main dgemm7 2048 1")