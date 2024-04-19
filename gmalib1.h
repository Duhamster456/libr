#ifndef GMALIB_1
#define GMALIB_1

int getLD(long double *path, long double min, long double max);
int getInt(int *path, int min, int max);
int inputArr(int **data, int *len);
void outputArr(int *data, int len);
int addElement(int **data, int *len, int index, int value);
int deleteElement(int **data, int *len, int index);

#endif
