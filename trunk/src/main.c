#include "gauss.h"
#include "backsubst.h"
#include "mat_io.h"
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char ** argv) {
	int res;
	Matrix * A = readFromFile(argv[1]);
	Matrix * b = readFromFile(argv[2]);
	Matrix * x;
	
	int t=0;

	if (A == NULL) t= -1;
	if (b == NULL) t= -2;
	if (t<0){
		printf("Blad wczytywania macierzy");
		return 1;
	}

	res = eliminate(A,b);

	x = createMatrix(b->r, 1);

	if (x != NULL) {
		res = backsubst(x,A,b);
		if(res == 0)printf("OK.\n");
		else
		if(res == 1)printf("BŁĄD.\n");
		else
		if(res == 2)printf("BŁĄD.\n");
	  freeMatrix(x);
	}
       	else 
	{ 
		printf("Wystapil blad.\n");
		return 1;
	}

	freeMatrix(A);
	freeMatrix(b);

	return 0;
}
