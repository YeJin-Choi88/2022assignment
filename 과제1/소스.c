#include <stdio.h>
# define DIM 3

void print_m(char name, int arr[DIM][DIM]);
void input_m(char name, int arr[DIM][DIM]);
void mul_arr(char name, int arr1[DIM][DIM], int arr2[DIM][DIM], int arr3[DIM][DIM]);
int i, j, k;

int main(void) {
	int A[DIM][DIM] = {0};
	int B[DIM][DIM] = { 0 };
	int C[DIM][DIM] = { 0 };

	input_m('A',A);
	input_m('B', B);
	print_m('A', A);
	print_m('B', B);
	mul_arr('C', C, A, B);
	print_m('C', C);
	return 0;
}
void input_m(char name, int arr[DIM][DIM]) {
	for (i = 0; i < DIM; i++) {
		printf("row %d of %c :", i, name);
		for (j = 0; j < DIM; j++) {
			scanf_s("%d", &arr[i][j]);
		}
	}
	printf("\n");
}

void print_m(char name, int arr[DIM][DIM]) {
	printf("matrix of %c\n", name);
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			printf("%d ", arr[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}

void mul_arr(char name, int arr1[DIM][DIM], int arr2[DIM][DIM], int arr3[DIM][DIM]) {
	for (i = 0; i < DIM; i++) {
		for (j = 0; j < DIM; j++) {
			for (k = 0; k < DIM; k++) {
				arr1[i][j] += arr2[i][k] * arr3[k][j];
			}
		}
	}
}