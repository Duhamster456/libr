#include <stdlib.h>
#include <stdio.h>

int addElement(int **data, int *len, int index, int value){
	if(index < *len){
		(*len)++;
		*data = (int *) realloc(*data, (*len) * sizeof(int));
		for(int i = (*len) - 1; i > index; i--){
			(*data)[i] = (*data)[i - 1];
		}
		(*data)[index] = value;
	}
	else{
		(*len)++;
		*data = (int *) realloc(*data, (*len) * sizeof(int));
		(*data)[(*len) - 1] = value;
	}
	if(!data){
		return 1;
	}
	return 0;
}

int deleteElement(int **data, int *len, int index){
	if(index < *len){
		for(int i = index; i < (*len) - 1; i++){
			(*data)[i] = (*data)[i + 1];
		}
		(*len)--;
		*data = (int *) realloc(*data, (*len) * sizeof(int));
	}
	else{
		return 2;
	}
	if(!data){
		return 1;
	}
	return 0;
}

void outputArr(int *data, int len){
	for(int i = 0; i < len; i++){
		printf("Элемент массива номер %d: %d\n", i, data[i]);
	}
}
