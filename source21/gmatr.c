#include <stdio.h>
#include "../iok.h"
#include "limits.h"
#include <stdlib.h>
#include "../gmatr.h"

int inpLine(Line *ln){
	ln->n = 0;
	ln->a = NULL;
	char endline[1];
	while(scanf("%1[\n]", endline) < 1){
		int number;
		int gires = getIntFragile(&number, INT_MIN, INT_MAX);
		if(gires == EOF){
			return EOF;
		}
		if(gires == 0){
			ln->n++;
			ln->a = (int*)realloc(ln->a, ln->n * sizeof(int));
			ln->a[ln->n - 1] = number;
		}
	}
	return 0;
}

int outLine(Line ln){
	for(int i = 0; i < ln.n; i++){
		printf("%d ", ln.a[i]);
	}
	printf("\n");
}

int inpMatrix(Matrix* rm){
	rm->m = 0;
	rm->matr = NULL;
	Line ln;
	int lres = inpLine(&ln);
	while(lres != EOF){
		rm->m++;
		rm->matr = (Line*)realloc(rm->matr, rm->m * sizeof(Line));
		rm->matr[rm->m - 1] = ln;
		lres = inpLine(&ln);
	}
	return 0;
}

int outMatrix(Matrix rm){
	for(int i = 0; i < rm.m; i++){
		outLine(rm.matr[i]);
	}
	printf("\n");
}

int proc(Line *res, Matrix rm){
	res->n = rm.m;
	res->a = malloc(rm.m * sizeof(int));
	for(int i = 0; i < rm.m; i++){
		res->a[i] = 0;
		int prev = i - 1;
		if(prev == -1){
			prev = rm.m - 1;
		}
		int prevn = rm.matr[prev].n;
		for(int j = 0; j < rm.matr[i].n; j++){
			if(j < prevn){
				if(rm.matr[i].a[j] <= rm.matr[prev].a[j]){
					continue;
				}
			}
			res->a[i] += rm.matr[i].a[j];
		}
	}
	return 0;
}

int cleanLine(Line ln){
	free(ln.a);
}

int cleanMatrix(Matrix rm){
	for(int i = 0; i < rm.m; i++){
		cleanLine(rm.matr[i]);
	}
	free(rm.matr);
}
