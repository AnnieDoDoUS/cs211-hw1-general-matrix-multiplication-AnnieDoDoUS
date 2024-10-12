main: dgemm0.c dgemm1.c dgemm2.c dgemm3.c dgemm7.c \
	dgemm6_ijk.c dgemm6_ikj.c dgemm6_jik.c dgemm6_jki.c dgemm6_kij.c dgemm6_kji.c \
	main.c makefile
	rm -f main
	gcc main.c -o main