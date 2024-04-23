#include <stdio.h>

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

int getUns(unsigned *path, unsigned min, unsigned max){
	int sres = scanf("%u", path);
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
		sres = scanf("%u", path);
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

int fgetIntFragile(FILE* file, int *path, int min, int max){
	int sres = fscanf(file, "%d", path);
	while ((sres != 1) || (*path < min) || (*path > max)){
		switch(sres){
			case EOF:
				return EOF;
			case 0:
				fscanf(file, "%*[^\n]");
				return 1;
			case 1:
				printf("Некорректный ввод. Число не попадает в заданный диапазон\n");
				break;
		}
		sres = fscanf(file, "%d", path);
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

int getDouble(double *path, double min, double max){
	int sres = scanf("%lf", path);
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
		sres = scanf("%lf", path);
	}
	return 0;
}
