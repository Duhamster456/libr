#include <stdlib.h>
#include <stdio.h>
#include "math.h"
#include "../iok.h"
#include "limits.h"

void gralloc(int **data, int *len, int *mem){
	if((*mem) <= 0){
		free(*data);
		*data = NULL;
		*mem = (*len) * 2;
	}
	else{
		if((*mem) < (*len)){
			*mem = (*len) * 2;
		}
		else{
			if((*len) < (((*mem) / 2) + ((*mem) % 2))){
				*mem = (*len) / 2;
			}
			else{
				return;
			}
		}
	}
	*data = (int *) realloc(*data, (*mem) * sizeof(int));
}

int addElement(int **data, int *len, int *mem, int index, int value){
	(*len)++;
	gralloc(data, len, mem);
	if(index < *len){
		for(int i = (*len) - 1; i > index; i--){
			(*data)[i] = (*data)[i - 1];
		}
		(*data)[index] = value;
	}
	else{
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

int* newSequence(int **data, int *len, int *mem, int *newlen, int *newmem){
	*newmem = 0;
	*newlen = 0;
	int copy, fits, *new;
	for(int i = 0; i < *len; i++){
		copy = fabs((*data)[i]);
		fits = 1;
		int digit = -1;
		while(copy > 0){
			if((copy % 10) <= digit){
				fits = 0;
				break;
			}
			digit = copy % 10;
			copy = copy / 10;
		}
		if(fits == 1){
			addElement(&new, newlen, newmem, *newlen, (*data)[i]);
			deleteElement(data, len, mem, i);
			i--;
		}
	}
	return new;
}
