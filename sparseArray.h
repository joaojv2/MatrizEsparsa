#ifndef SPARSEARRAY_H
#define SPARSEARRAY_H

struct sparseArray {
	int value;
	int row, column;
	struct sparseArray *prox;
};

typedef struct sparseArray SparseArray;

SparseArray* createArray (int, int, int);

SparseArray* createSparseArray (void);

int sparseArrayVoid (SparseArray *);

void insertArray (SparseArray **, SparseArray *);

void printSparseArray (SparseArray *, int, int);

SparseArray* sumMatrix (SparseArray *, SparseArray *, int, int);

void destroySparseArray(SparseArray *);

SparseArray* mult_matrix_ikj (SparseArray *, SparseArray *, int, int, int, int);

int searchValueForIndex (SparseArray *, int, int);

SparseArray* transformMatrixInSparseArray(int **, int, int);

#endif