iok.a : iok.o
	ar r iok.a iok.o

iok.o : source2/iok.c
	gcc -c source2/iok.c

feather.a : feather.o
	ar r feather.a feather.o

feather.o : source3/feather.c
	gcc -c source3/feather.c

clean :
	rm *.o