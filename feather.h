#ifndef FEATHER
#define FEATHER

int fea_strlen(const char *str);
char* fea_cpy(void *where, const void *what, int n);
int fea_bufferInput(char **str);
int f_fea_bufferInput(FILE *file, char **str);
void fea_writeMult(char *inp, char *out, int counter);
char* fea_dup(char *str);
char* fea_tok(char *str, const char* delim);
int fea_spn(const char* str1, const char* str2);
int fea_cspn(const char* str1, const char* str2);
int fea_contains(const char* str, const char x);
int fea_str_comp(const char* str1, const char* str2);
char *fea_cat(char *str1, const char *str2);

#endif
