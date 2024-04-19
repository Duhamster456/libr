#include <stdlib.h>
#include <stdio.h>
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

int getIntFragile(int *path, int min, int max){
	int sres = scanf("%d", path);
	while ((sres != 1) || (*path < min) || (*path > max)){
		switch(sres){
			case EOF:
				return EOF;
			case 0:
				scanf("%*[^\n]");
				return 1;
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

void gralloc(int **data, int *len, int *mem){
	if((*mem) <= 0){
		*mem = (*len) * 2;
		*data = (int *) malloc((*mem) * sizeof(int));
		return;
	}
	if((*mem) < (*len)){
		(*mem) *= 2;
		*data = (int *) realloc(*data, (*mem) * sizeof(int));
		return;
	}
	if((*len) < (((*mem) / 2) + ((*mem) % 2))){
		(*mem) = (*mem) / 2;
		*data = (int *) realloc(*data, (*mem) * sizeof(int));
		return;
	}
}

int addElement(int **data, int *len, int *mem, int index, int value){
	if(index < *len){
		(*len)++;
		gralloc(data, len, mem);
		for(int i = (*len) - 1; i > index; i--){
			(*data)[i] = (*data)[i - 1];
		}
		(*data)[index] = value;
	}
	else{
		(*len)++;
		gralloc(data, len, mem);
		(*data)[(*len) - 1] = value;
	}
	if(!data){
		return 1;
	}
	return 0;
}

int deleteElement(int **data, int *len, int *mem, int index){
	if(index < *len){
		for(int i = index; i < (*len) - 1; i++){
			(*data)[i] = (*data)[i + 1];
		}
		(*len)--;
		gralloc(data, len, mem);
	}
	else{
		return 2;
	}
	if(!data){
		return 1;
	}
	return 0;
}

int inputArr(int **data, int *len, int *mem) {
	printf("Инициализация массива. Введите любую букву, чтобы закончить инициализацию\n");
	int res = 0;
	int value;
	int i = 0;
	char k[1];
	*len = 0;
	*mem = 1;
	free(*data);
	*data = (int *) malloc(sizeof(int));
	if (!(*data)) {
		return 1;
	}
	while (res == 0){
		printf("data[%d] = ", i);
		int res = getIntFragile(&value, INT_MIN, INT_MAX);
		switch(res){
			case 0:
				addElement(data, len, mem, i, value);
				break;
			case EOF:
				return EOF;
			case 1:
				printf("Массив проинициализирован\n");
				return 0;
		}
		i++;
	}
	return 0;
}

void outputArr(int *data, int len){
	for(int i = 0; i < len; i++){
		printf("Элемент массива номер %d: %d\n", i, data[i]);
	}
}
