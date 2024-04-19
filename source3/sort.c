void combsort(void* base, size_t num, size_t size, int (*compare)(const void*, const void*)){
	void* tmp = malloc(size);
	void *one, *two;
	int dist = num;
	double factor = 1.2473309;
	int step = num - 1;
	while(step >= 1){
		for(int i = 0; i + step < num; i++){
			one = base + size * i;
			two = base + size * (i + step);
			if(compare(one, two) > 0){
				memcpy(tmp, one, size);
				memcpy(one, two, size);
				memcpy(two, tmp, size);
			}
		}
		step /= factor;
	}
	free(tmp);
}

void shellsort(void* base, size_t num, size_t size, int (*compare)(const void*, const void*)){
	void* tmp = malloc(size);
	void *one, *two;
	for(int d = num / 2; d > 0; d /= 2){
		for(int i = d; i < num; ++i){
			for(int j = i - d; j >=0 && compare((base + j * size),(base + (j + d) * size)) > 0; j -= d){
				one = base + size * j;
				two = base + size * (j + d);
				memcpy(tmp, one, size);
				memcpy(one, two, size);
				memcpy(two, tmp, size);
			}
		}
	}
	free(tmp);
}
