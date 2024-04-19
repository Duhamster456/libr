#ifndef IOK
#define IOK

#include <stdio.h>

int getLD(long double *path, long double min, long double max);
int getDouble(double *path, double min, double max);
int getInt(int *path, int min, int max);
int getIntFragile(int *path, int min, int max);
int fgetIntFragile(FILE *file, int *path, int min, int max);

#endif
