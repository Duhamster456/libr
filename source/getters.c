#include <stdio.h>
#include <stdlib.h>
#include "limits.h"

int getInt(int *path, int min, int max){
	int sres = scanf("%d", path);
	while ((sres != 1) || (*path < min) || (*path > max)){
		switch(sres){
			case EOF:
				return EOF;
			case 0:
				scanf("%*[^\n]");
				printf("Некорректный ввод. Введите число\n");
				break;
			case 1:
				printf("Некорректный ввод. Число не попадает в заданный диапазон\n");
				break;
		}
		sres = scanf("%d", path);
	}
	return 0;
}

int getLD(long double *path, long double min, long double max){
	int sres = scanf("%Lf", path);
	while ((sres != 1) || (*path <= min) || (*path >= max)){
		switch(sres){
			case EOF:
				return EOF;
			case 0:
				scanf("%*[^\n]");
				printf("Некорректный ввод. Введите число\n");
				break;
			case 1:
				printf("Некорректный ввод. Число не попадает заданный диапазон\n");
				break;
		}
		sres = scanf("%Lf", path);
	}
	return 0;
}

int inputArr(int **data, int *len) {
	printf("Введите длину массива. ");
	int intres = getInt(len, 0, INT_MAX);
	if (intres == EOF){
		return EOF;
	}
	*data = (int *) malloc((*len) * sizeof(int));
	if (!(*data)) {
		return 1;
	}
	for (int i = 0; i < (*len); i++){
		printf("data[%d] = ", i);
		intres = getInt((*data + i), INT_MIN, INT_MAX);
	}
	return 0;
}

