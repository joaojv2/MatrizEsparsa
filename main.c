#include <stdio.h>
#include <stdlib.h>
#include "sparseArray.h"
#include "matrix.h"

int main (void) {
	int rowA, columnA, rowB, columnB;
	FILE  *entrada, *saida;

	entrada = fopen( "entrada.txt", "r" );

	fscanf(entrada, "%d %d", &rowA, &columnA );
	fscanf(entrada, "%d %d", &rowB, &columnB );

	SparseArray *sparseArrayA, *sparseArrayB, *sparseArrayResult, *sparseArrayResult2;

	int **matrixA, **matrixB;

	matrixA = createMatrix(rowA, columnA);
	Matriz_fscanf( entrada, matrixA, rowA, columnA);
	printf("Matriz A lida do arquivo\n");
	printMatrix(matrixA, rowA, columnA);

	matrixB = createMatrix(rowB, columnB);
	Matriz_fscanf( entrada, matrixB, rowB, columnB);
	printf("Matriz B lida do arquivo\n");
	printMatrix(matrixB, rowB, columnB);

	sparseArrayA = transformMatrixInSparseArray(matrixA, rowA, columnA);
	sparseArrayB = transformMatrixInSparseArray(matrixB, rowB, columnB);

	sparseArrayResult = mult_matrix_ikj(sparseArrayA, sparseArrayB, rowA , columnA, columnB, verificationMultMatrix(rowA, columnA, rowB, columnB));
	sparseArrayResult2 = sumMatrix(sparseArrayA, sparseArrayB, rowA , verificationSumMatrix(rowA, columnA, rowB, columnB));

	printf("Resultado da multiplicacao\n");
	printSparseArray(sparseArrayResult, rowA, columnA);

	printf("Resultado da soma\n");
	printSparseArray(sparseArrayResult2, rowB, columnB);

	destroyMatrix(matrixA, rowA);
	destroyMatrix(matrixB, rowB);

	destroySparseArray(sparseArrayA);
	destroySparseArray(sparseArrayB);
	destroySparseArray(sparseArrayResult);

	return 0;
}
