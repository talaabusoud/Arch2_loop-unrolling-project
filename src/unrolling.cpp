// HW#1 - ARCH.2
// Loop Unrolling 
#include <immintrin.h>  // portable to all x86 compilers
#include <stdio.h>
#include <time.h>

#define DATA float

const int SIZE = 1024;
const long SIZE_1 = 1048576;
const long SIZE_2 = 16777216;

DATA A[SIZE];
DATA B[SIZE_1];
DATA C[SIZE_2];

double seconds()
{
  struct timespec now;
  clock_gettime(CLOCK_MONOTONIC, &now);
  return now.tv_sec + now.tv_nsec / 1000000000.0;
}

void initialize_array(DATA a[], int size)
{
	for (int i = 0 ;  i < size ; i++)
	{
		a[i] = rand()%2;
	}
}

// normal loop 
void normal(DATA a[],int size) 
{
    for (int i = 0 ; i < size ; i++)
    {
        a[i] = a[i] + 5;
    }
}

//unrolling degree 4
void unrolled_4(DATA a[], int size)
{
	for (int i = 0; i < size; i += 4)
	{
		a[i] = a[i] + 5;
		a[i + 1] = a[i + 1] + 5;
		a[i + 2] = a[i + 2] + 5;
		a[i + 3] = a[i + 3] + 5;
	}

}

//degree 8
void unrolled_8(DATA a[], int size)

{
	for (int i = 0; i < size; i += 8)
	{
		a[i] = a[i] + 5;
		a[i + 1] = a[i + 1] + 5;
		a[i + 2] = a[i + 2] + 5;
		a[i + 3] = a[i + 3] + 5;
		a[i + 4] = a[i + 4] + 5;
		a[i + 5] = a[i + 5] + 5;
		a[i + 6] = a[i + 6] + 5;
		a[i + 7] = a[i + 7] + 5;
	}

}

//degree 16
void unrolled_16(DATA a[], int size)
{
	for (int i = 0; i < size; i += 16)
	{
		a[i] = a[i] + 5;
		a[i + 1] = a[i + 1] + 5;
		a[i + 2] = a[i + 2] + 5;
		a[i + 3] = a[i + 3] + 5;
		a[i + 4] = a[i + 4] + 5;
		a[i + 5] = a[i + 5] + 5;
		a[i + 6] = a[i + 6] + 5;
		a[i + 7] = a[i + 7] + 5;
		a[i + 8] = a[i + 8] + 5;
		a[i + 9] = a[i + 9] + 5;
		a[i + 10] = a[i + 10] + 5;
		a[i + 11] = a[i + 11] + 5;
		a[i + 12] = a[i + 12] + 5;
		a[i + 13] = a[i + 13] + 5;
		a[i + 14] = a[i + 14] + 5;
		a[i + 15] = a[i + 15] + 5;
	}

}

//degree 64
void unrolled_64(DATA a[], int size) {
	for (int i = 0; i < size; i += 64) {
		a[i] = a[i] + 5;
		a[i + 1] = a[i + 1] + 5;
		a[i + 2] = a[i + 2] + 5;
		a[i + 3] = a[i + 3] + 5;
		a[i + 4] = a[i + 4] + 5;
		a[i + 5] = a[i + 5] + 5;
		a[i + 6] = a[i + 6] + 5;
		a[i + 7] = a[i + 7] + 5;
		a[i + 8] = a[i + 8] + 5;
		a[i + 9] = a[i + 9] + 5;
		a[i + 10] = a[i + 10] + 5;
		a[i + 11] = a[i + 11] + 5;
		a[i + 12] = a[i + 12] + 5;
		a[i + 13] = a[i + 13] + 5;
		a[i + 14] = a[i + 14] + 5;
		a[i + 15] = a[i + 15] + 5;
		a[i + 16] = a[i + 16] + 5;
		a[i + 17] = a[i + 17] + 5;
		a[i + 18] = a[i + 18] + 5;
		a[i + 19] = a[i + 19] + 5;
		a[i + 20] = a[i + 20] + 5;
		a[i + 21] = a[i + 21] + 5;
		a[i + 22] = a[i + 22] + 5;
		a[i + 23] = a[i + 23] + 5;
		a[i + 24] = a[i + 24] + 5;
		a[i + 25] = a[i + 25] + 5;
		a[i + 26] = a[i + 26] + 5;
		a[i + 27] = a[i + 27] + 5;
		a[i + 28] = a[i + 28] + 5;
		a[i + 29] = a[i + 29] + 5;
		a[i + 30] = a[i + 30] + 5;
		a[i + 31] = a[i + 31] + 5;
		a[i + 32] = a[i + 32] + 5;
		a[i + 33] = a[i + 33] + 5;
		a[i + 34] = a[i + 34] + 5;
		a[i + 35] = a[i + 35] + 5;
		a[i + 36] = a[i + 36] + 5;
		a[i + 37] = a[i + 37] + 5;
		a[i + 38] = a[i + 38] + 5;
		a[i + 39] = a[i + 39] + 5;
		a[i + 40] = a[i + 40] + 5;
		a[i + 41] = a[i + 41] + 5;
		a[i + 42] = a[i + 42] + 5;
		a[i + 43] = a[i + 43] + 5;
		a[i + 44] = a[i + 44] + 5;
		a[i + 45] = a[i + 45] + 5;
		a[i + 46] = a[i + 46] + 5;
		a[i + 47] = a[i + 47] + 5;
		a[i + 48] = a[i + 48] + 5;
		a[i + 49] = a[i + 49] + 5;
		a[i + 50] = a[i + 50] + 5;
		a[i + 51] = a[i + 51] + 5;
		a[i + 52] = a[i + 52] + 5;
		a[i + 53] = a[i + 53] + 5;
		a[i + 54] = a[i + 54] + 5;
		a[i + 55] = a[i + 55] + 5;
		a[i + 56] = a[i + 56] + 5;
		a[i + 57] = a[i + 57] + 5;
		a[i + 58] = a[i + 58] + 5;
		a[i + 59] = a[i + 59] + 5;
		a[i + 60] = a[i + 60] + 5;
		a[i + 61] = a[i + 61] + 5;
		a[i + 62] = a[i + 62] + 5;
		a[i + 63] = a[i + 63] + 5;

	}

}




int main()
{


	DATA r;
    double x,y,z,w, s, avgx, avgy, avgz, avgw, avgs;
	double before,after;
	double before_unrolled_4, after_unrolled_4;
	double before_unrolled_8, after_unrolled_8;
	double before_unrolled_16, after_unrolled_16;
	double before_unrolled_64, after_unrolled_64;
	avgx = 0; avgy = 0; avgz = 0; avgw = 0; avgs = 0;

	//equations for each unrolling
		//size 1024
	initialize_array(A, SIZE);

	for (int i = 0; i < 100; i++)
	{
		before = seconds();
		normal(A, SIZE);
		after = seconds();

		x = after - before;
		avgx = avgx + x;
	}
	avgx = avgx / 100.0;

	printf("Size of 1024\n");
	printf("Normal Time:%12.8lf\n", avgx);

	for (int i = 0; i < 100; i++)
	{
		before_unrolled_4 = seconds();
		unrolled_4(A, SIZE);
		after_unrolled_4 = seconds();

		y = after_unrolled_4 - before_unrolled_4;
		avgy = avgy + y;
	}
	avgy = avgy / 100.0;

	printf("UNROLLED-4 TIME:%12.8lf\n", avgy);


	for (int i = 0; i < 100; i++)
	{
		before_unrolled_8 = seconds();
		unrolled_8(A, SIZE);
		after_unrolled_8 = seconds();

		z = after_unrolled_8 - before_unrolled_8;
		avgz = avgz + z;
	}
	avgz = avgz / 100.0;

	printf("UNROLLED-8 TIME:%12.8lf\n", avgz);


	for (int i = 0; i < 100; i++)
	{
		before_unrolled_16 = seconds();
		unrolled_16(A, SIZE);
		after_unrolled_16 = seconds();

		w = after_unrolled_16 - before_unrolled_16;
		avgw = avgw + w;
	}
	avgw = avgw / 100.0;

	printf("UNROLLED-16 TIME:%12.8lf\n", avgw);


	for (int i = 0; i < 100; i++)
	{
		before_unrolled_64 = seconds();
		unrolled_64(A, SIZE);
		after_unrolled_64 = seconds();

		s = after_unrolled_64 - before_unrolled_64;
		avgs = avgs + s;
	}
	avgs = avgs / 100.0;

	printf("UNROLLED-64 TIME:%12.8lf\n", avgs);

	printf("\n");
	printf("\n");

	//for size  1024*1024
	double x1, y1, z1, w1, s1, avgx1, avgy1, avgz1, avgw1, avgs1;
	double before_1st, after_1st;
	double before_unrolled_4_1st, after_unrolled_4_1st;
	double before_unrolled_8_1st, after_unrolled_8_1st;
	double before_unrolled_16_1st, after_unrolled_16_1st;
	double before_unrolled_64_1st, after_unrolled_64_1st;
	avgx1 = 0; avgy1 = 0; avgz1 = 0; avgw1 = 0; avgs1 = 0;

	initialize_array(B, SIZE_1);
	for (int i = 0; i < 10; i++)
	{
		before_1st = seconds();
		normal(B, SIZE_1);
		after_1st = seconds();

		x1 = after_1st - before_1st;
		avgx1 = avgx1 + x1;
	}
	avgx1 = avgx1 / 10.0;
	printf("Size of 1024*1024\n");
	printf("Normal Time:%f\n", avgx1);

	for (int i = 0; i < 10; i++) {
		before_unrolled_4_1st = seconds();
		unrolled_4(B, SIZE_1);
		after_unrolled_4_1st = seconds();

		y1 = after_unrolled_4_1st - before_unrolled_4_1st;
		avgy1 = avgy1 + y1;
	}
	avgy1 = avgy1 / 10.0;
	printf("UNROLLED-4 TIME:%f\n", avgy1);

	for (int i = 0; i < 10; i++) {
		before_unrolled_8_1st = seconds();
		unrolled_8(B, SIZE_1);
		after_unrolled_8_1st = seconds();

		z1 = after_unrolled_8_1st - before_unrolled_8_1st;
		avgz1 = avgz1 + z1;
	}
	avgz1 = avgz1 / 10.0;
	printf("UNROLLED-8 TIME:%f\n", avgz1);

	for (int i = 0; i < 10; i++) {
		before_unrolled_16_1st = seconds();
		unrolled_16(B, SIZE_1);
		after_unrolled_16_1st = seconds();

		w1 = after_unrolled_16_1st - before_unrolled_16_1st;
		avgw1 = avgw1 + w1;
	}
	avgw1 = avgw1 / 10.0;
	printf("UNROLLED-16 TIME:%f\n", avgw1);

	for (int i = 0; i < 10; i++) {
		before_unrolled_64_1st = seconds();
		unrolled_64(B, SIZE_1);
		after_unrolled_64_1st = seconds();

		s1 = after_unrolled_64_1st - before_unrolled_64_1st;
		avgs1 = avgs1 + s1;
	}
	avgs1 = avgs1 / 10.0;
	printf("UNROLLED-64 TIME:%f\n", avgs1);

	printf("\n");
	printf("\n");


	//for size  16*1024*1024
	double x2, y2, z2, w2, s2, avgx2, avgy2, avgz2, avgw2, avgs2;
	double before_2nd, after_2nd;
	double before_unrolled_4_2nd, after_unrolled_4_2nd;
	double before_unrolled_8_2nd, after_unrolled_8_2nd;
	double before_unrolled_16_2nd, after_unrolled_16_2nd;
	double before_unrolled_64_2nd, after_unrolled_64_2nd;
	avgx2 = 0; avgy2 = 0; avgz2 = 0; avgw2 = 0; avgs2 = 0;

	initialize_array(C, SIZE_2);

	for (int i = 0; i < 10; i++) {
		before_2nd = seconds();
		normal(C, SIZE_2);
		after_2nd = seconds();

		x2 = after_2nd - before_2nd;
		avgx2 = avgx2 + x2;
	}
	avgx2 = avgx2 / 10.0;
	printf("Size of 16*1024*1024\n");
	printf("Normal TIME:%f\n", avgx2);

	for (int i = 0; i < 10; i++) {
		before_unrolled_4_2nd = seconds();
		unrolled_4(C, SIZE_2);
		after_unrolled_4_2nd = seconds();

		y2 = after_unrolled_4_2nd - before_unrolled_4_2nd;
		avgy2 = avgy2 + y2;
	}
	avgy2 = avgy2 / 10.0;
	printf("UNROLLED-4 TIME:%f\n", avgy2);

	for (int i = 0; i < 10; i++) {
		before_unrolled_8_2nd = seconds();
		unrolled_8(C, SIZE_2);
		after_unrolled_8_2nd = seconds();

		z2 = after_unrolled_8_2nd - before_unrolled_8_2nd;
		avgz2 = avgz2 + z2;
	}
	avgz2 = avgz2 / 10.0;
	printf("UNROLLED-8 TIME:%f\n", avgz2);

	for (int i = 0; i < 10; i++) {
		before_unrolled_16_2nd = seconds();
		unrolled_16(C, SIZE_2);
		after_unrolled_16_2nd = seconds();

		w2 = after_unrolled_16_2nd - before_unrolled_16_2nd;
		avgw2 = avgw2 + w2;
	}
	avgw2 = avgw2 / 10.0;
	printf("UNROLLED-16 TIME:%f\n", avgw2);

	for (int i = 0; i < 10; i++) {
		before_unrolled_64_2nd = seconds();
		unrolled_64(C, SIZE_2);
		after_unrolled_64_2nd = seconds();

		s2 = after_unrolled_64_2nd - before_unrolled_64_2nd;
		avgs2 = avgs2 + s2;
	}
	avgs2 = avgs2 / 10.0;
	printf("UNROLLED-64 Time:%f\n", avgs2);

    return 0;
}
