#include <stdio.h>
#include <stdlib.h>

int fea_strlen(const char *str){
	int i = 0;
	while(str[i] != '\0') i++;
	return i;
}

char* fea_cpy(void *where, const void *what, int n){
	for(int i = 0; i < n; i++){
		((unsigned char*)where)[i] = ((unsigned char*)what)[i];
	}
	return where;
}

int fea_bufferInput(char **str){
	*str = NULL;
	int scan_res = 1;
	int len = 0;
	char buffer[11];
	scan_res = scanf("%10[^\n]", buffer);
	while(scan_res > 0){
		int buf_len = fea_strlen(buffer);
		*str = (char *) realloc(*str, (len + 1 + buf_len) * sizeof(char));
		fea_cpy(*str + len, buffer, buf_len * sizeof(char));
		len += buf_len;
		(*str)[len] = '\0';
		scan_res = scanf("%10[^\n]", buffer);
	}
	if(scan_res == EOF){
		return EOF;
	}
	else{
		if(len == 0){
			*str = (char *) calloc(1, sizeof(char));
		}
		scanf("%*1[\n]");
		return 0;
	}
}

int f_fea_bufferInput(FILE *file, char **str){
	*str = NULL;
	int scan_res = 1;
	int len = 0;
	char buffer[11];
	scan_res = fscanf(file, "%10[^\n]", buffer);
	while(scan_res > 0){
		int buf_len = fea_strlen(buffer);
		*str = (char *) realloc(*str, (len + 1 + buf_len) * sizeof(char));
		fea_cpy(*str + len, buffer, buf_len * sizeof(char));
		len += buf_len;
		(*str)[len] = '\0';
		scan_res = fscanf(file, "%10[^\n]", buffer);
	}
	if(scan_res == EOF){
		return EOF;
	}
	else{
		if(len == 0){
			*str = (char *) calloc(1, sizeof(char));
		}
		fscanf(file, "%*1[\n]");
		return 0;
	}
}

void fea_writeMult(char *inp, char *out, int counter){
	for(int i = 0; i < counter; i++){
		printf("Введённая строка: \"%s\"\n", inp);
		printf("Результат преобразования: \"%s\"\n", out);
		inp += fea_strlen(inp) + 1;
		out += fea_strlen(out) + 1;
	}
}

int fea_contains(const char* str, const char x){
	int i = 0;
	char ch = str[i];
	while(ch != '\0'){
		if(ch == x){
			return 1;
		}
		i++;
		ch = str[i];
	}
	return 0;
}

int fea_cspn(const char* str1, const char* str2){
	int i = 0;
	char ch = str1[i];
	while(ch != '\0'){
		if(fea_contains(str2, ch) == 1){
			break;
		}
		i++;
		ch = str1[i];
	}
	return i;
}

int fea_spn(const char* str1, const char* str2){
	int i = 0;
	char ch = str1[i];
	while(ch != '\0'){
		if(fea_contains(str2, ch) == 0){
			break;
		}
		i++;
		ch = str1[i];
	}
	return i;
}

char* fea_tok(char *str, const char* delim){
	static char *nextword;
	if(str){
		nextword = str;
	}
	if(!nextword){
		return NULL;
	}
	nextword += fea_spn(nextword, delim);
	if(*nextword == '\0'){
		return NULL;
	}
	char *res = nextword;
	nextword += fea_cspn(nextword, delim);
	*nextword = '\0';
	nextword++;
	return res;
}

char* fea_dup(char *str){
	int len = fea_strlen(str) + 1;
	char *dup = (char*) calloc(len + 1, sizeof(char));
	for(int i = 0; i < len; i++){
		dup[i] = str[i];
	}
	return dup;
}


int fea_str_comp(const char* str1, const char* str2){
	int res = 0;
	int i = 0;
	while(res == 0){
		res = str1[i] - str2[i];
		if(str1[i] == '\0' || str2[i] == '\0'){
			break;
		}
		i++;
	}
	return res;
}

char *fea_cat(char *str1, const char *str2){
	int len_1 = fea_strlen(str1);
	int len_2 = fea_strlen(str2);
	str1 = realloc(str1, len_1 + len_2 + 1);
	fea_cpy(str1 + len_1, str2, len_2 + 1);
	return str1;
}
