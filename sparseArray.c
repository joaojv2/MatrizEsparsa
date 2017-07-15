#include <stdio.h>
#include <stdlib.h>
#include "sparseArray.h"

SparseArray* createSparseArray (void) {
	SparseArray *sparseArray;
	sparseArray = (SparseArray*) malloc(sizeof(SparseArray));

	if (sparseArray != NULL)
		sparseArray = NULL;

	return sparseArray;
}


SparseArray* createArray (int value, int row, int column) {
	SparseArray *array;
	array = (SparseArray*) malloc(sizeof(SparseArray));

	array->value = value;
	array->row = row;
	array->column = column;
	array->prox = NULL;

	return array;

}

void insertArray (SparseArray **sparseArray, SparseArray *array) {
	if (sparseArrayVoid(*sparseArray)){
		*sparseArray = array;
	}
	else{
		SparseArray *sparseArrayAux = (*sparseArray);
		
		while (sparseArrayAux->prox != NULL)
			sparseArrayAux = sparseArrayAux->prox;

		sparseArrayAux->prox = array;
	}
}

int sparseArrayVoid (SparseArray *sparseArray) {
	return (sparseArray == NULL);
}

void printSparseArray (SparseArray *sparseArray, int row, int column) {

	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < column; j ++) {
			if (searchValueForIndex(sparseArray, i, j) == 0)
				printf(" ");
			else
				printf("%d ", searchValueForIndex(sparseArray, i, j));
		}
		printf("\n");
	}
	printf("\n");
}

void destroySparseArray(SparseArray *sparseArray) {
	SparseArray *sparseArrayAux;

	for (sparseArrayAux = sparseArray ; sparseArrayAux != NULL ; sparseArrayAux = sparseArrayAux->prox) {
		free(sparseArrayAux);
	}
}

SparseArray* sumMatrix (SparseArray *sparseArrayA, SparseArray *sparseArrayB, int row, int verification) {
	if (verification == 0){
		printf("Nao eh possivel somar as matrizes\n");
		return NULL;
	}

	SparseArray *sparseArrayResult, *matrixA, *matrixB;

	sparseArrayResult = createSparseArray();

	matrixA = sparseArrayA;
	matrixB = sparseArrayB;

	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < row; j ++) {	
			if (matrixA->column == -1 && matrixB->column == -1){
				break;
			}
			else if ((j == matrixA->column) && (j == matrixB->column)){
				insertArray(&sparseArrayResult, createArray(matrixA->value + matrixB->value, i, j));
				matrixA = matrixA->prox;
				matrixB = matrixB->prox;
			}
			else if (j == matrixA->column) {
				insertArray(&sparseArrayResult, createArray(matrixA->value, i, j));
				matrixA = matrixA->prox;
			}
			else if (j == matrixB->column) {
				insertArray(&sparseArrayResult, createArray(matrixB->value, i, j));
				matrixB = matrixB->prox;
			}	
		}
		matrixA= matrixA->prox;
		matrixB = matrixB->prox;

		insertArray(&sparseArrayResult, createArray(-1, -1, -1));
	}
	return sparseArrayResult;
}

SparseArray* mult_matrix_ikj (SparseArray *sparseArrayA , SparseArray *sparseArrayB, int row, int columnA, int columnB, int verification) {
	if (verification == 0){
		printf("Nao eh possivel multiplicar essas matrizes\n");
		return NULL;
	}

	SparseArray *sparseArrayResult, *matrixA, *matrixB;

	sparseArrayResult = createSparseArray();

	int total = 0;

	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < columnB; j ++) {
			total = 0;
			for (int k = 0; k < columnA; k ++) {
				total += searchValueForIndex(sparseArrayA, i, k) * searchValueForIndex(sparseArrayB, k, j);
			}

			if(total) {
				insertArray(&sparseArrayResult, createArray(total, i, j));
			}
		}

		insertArray(&sparseArrayResult, createArray(-1, -1, -1));
	}

	return sparseArrayResult;
}

int searchValueForIndex (SparseArray *sparseArray, int i, int j) {
	SparseArray *sparseArrayAux;

	for (sparseArrayAux = sparseArray ; sparseArrayAux != NULL ; sparseArrayAux = sparseArrayAux->prox) {
		if ((sparseArrayAux->column == j) && (sparseArrayAux->row == i)){
			return sparseArrayAux->value;
		}

	}

	return 0;
}

SparseArray* transformMatrixInSparseArray(int **matrix, int row, int column) {
	SparseArray *sparseArray;

	sparseArray = createSparseArray();

	for (int i = 0; i < row; i ++) {
		for (int j = 0; j < column; j ++) {
			if (*(*(matrix + i) + j) != 0) {
				insertArray(&sparseArray, createArray(*(*(matrix + i) + j), i, j));
			}
		}
		insertArray(&sparseArray, createArray(-1, -1, -1));
	}

	return sparseArray;
}