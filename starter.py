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


some_integer = 1

# For dgemm6_ijk
print(f"srun main dgemm6_ijk 2048 {some_integer}")
os.system(f"srun main dgemm6_ijk 2048 {some_integer}")

# For dgemm6_ikj
print(f"srun main dgemm6_ikj 2048 {some_integer}")
os.system(f"srun main dgemm6_ikj 2048 {some_integer}")

# For dgemm6_jik
print(f"srun main dgemm6_jik 2048 {some_integer}")
os.system(f"srun main dgemm6_jik 2048 {some_integer}")

# For dgemm6_jki
print(f"srun main dgemm6_jki 2048 {some_integer}")
os.system(f"srun main dgemm6_jki 2048 {some_integer}")

# For dgemm6_kij
print(f"srun main dgemm6_kij 2048 {some_integer}")
os.system(f"srun main dgemm6_kij 2048 {some_integer}")

# For dgemm6_kji
print(f"srun main dgemm6_kji 2048 {some_integer}")
os.system(f"srun main dgemm6_kji 2048 {some_integer}")

# For dgemm6_ijk2
print(f"srun main dgemm6_ijk2 2048 {some_integer}")
os.system(f"srun main dgemm6_ijk2 2048 {some_integer}")

# For dgemm6_ikj2
print(f"srun main dgemm6_ikj2 2048 {some_integer}")
os.system(f"srun main dgemm6_ikj2 2048 {some_integer}")

# For dgemm6_jik2
print(f"srun main dgemm6_jik2 2048 {some_integer}")
os.system(f"srun main dgemm6_jik2 2048 {some_integer}")

# For dgemm6_jki2
print(f"srun main dgemm6_jki2 2048 {some_integer}")
os.system(f"srun main dgemm6_jki2 2048 {some_integer}")

# For dgemm6_kij2
print(f"srun main dgemm6_kij2 2048 {some_integer}")
os.system(f"srun main dgemm6_kij2 2048 {some_integer}")

# For dgemm6_kji2
print(f"srun main dgemm6_kji2 2048 {some_integer}")
os.system(f"srun main dgemm6_kji2 2048 {some_integer}")

for i in range(0,4):
    print(f"srun main dgemm7 2048 with -O{i}")
    os.system("gcc main.c -o main -O"+str(i))
    os.system("srun main dgemm7 2048 1")