#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrix.h"

int** createMatrix (int row, int column) {
	int **matrix;

	matrix = (int**) malloc(row * sizeof(int*));

	for (int i = 0; i < row; i ++) {
		*(matrix + i) = (int*) malloc(column * sizeof(int));
	}

	return matrix;
}

void generationValuesRandom (int **matrix, int row, int column) {

	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < row; j ++) {
			if(rand() % 5 == 1)
				*(*(matrix + i) + j) = rand() % 10;
			else
				*(*(matrix + i) + j) = 0;
		}
	}
}

void Matriz_fscanf (FILE *entrada, int** matriz, int row, int column) {

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
				fscanf (entrada, "%d", &matriz[i][j]);

}

void printMatrix (int **matrix, int row, int column) {
	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < column; j ++) {
			printf("%d ", *(*(matrix + i) + j));
		}
		printf("\n");
	}
	printf("\n");
}

void destroyMatrix (int **matrix, int row) {
	for (int i = 0; i < row; i ++)
		free(*(matrix + i));

	free(matrix);
}

int verificationMultMatrix (int rowA, int columnA, int rowB, int columnB) {
	if ((rowA == columnA) && (rowB == columnB) && (rowA == rowB) || columnA == rowB)
		return 1;
	else 
		return 0;
}

int verificationSumMatrix (int rowA, int columnA, int rowB, int columnB) {
	if ((rowA == columnA) && (rowB == columnB) && (rowA == rowB))
		return 1;
	else 
		return 0;
}