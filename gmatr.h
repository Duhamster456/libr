#ifndef GMATR
#define GMATR

typedef struct Line{
	int n;
	int *a;
}Line;

typedef struct Matrix{
	int m;
	Line *matr;
}Matrix;

int inpLine(Line *ln);
int outLine(Line ln);
int inpMatrix(Matrix* rm);
int outMatrix(Matrix rm);
int proc(Line *res, Matrix rm);
int cleanLine(Line ln);
int cleanMatrix(Matrix rm);

#endif
