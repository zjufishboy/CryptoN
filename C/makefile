#test
test:test.o md5.o utils.o
	gcc -o test test.o md5.o utils.o

#test.o
test.o:test.c Crypto.h
	gcc -c test.c

#md5.o
md5.o:md5.h md5.c
	gcc -c md5.c

#utils.o
utils.o:utils.c utils.h
	gcc -c utils.c

#clean
clean:
	rm test *.o