#ifndef GMARAY
#define GMARAY

int inputArr(int **data, int *len, int *mem);
void outputArr(int *data, int len);
int addElement(int **data, int *len, int *mem, int index, int value);
int deleteElement(int **data, int *len, int *mem, int index);
int* newSequence(int **data, int *len, int *mem, int *newlen, int *newmem);

enum GMARAY_ERRORS{
	FINE = 0,
	NULL_POINTER = 1,
	OUT_OF_BOUNDS = 2,
	WRAPPER_EXIT = 3
};

#endif
