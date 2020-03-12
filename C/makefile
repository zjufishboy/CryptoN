#test
test:test.o Crypto.o
	gcc -o tst test.o

#test.o
test.o:test.c Crypto.o utils.o md5.o
	gcc -c test.c

#Crypto.o
CryptoN.o:Crypto.c Crypto.h utils.o md5.o
	gcc -c Crypto.c 

#md5.o
md5.o:md5.h md5.c
	gcc -c md5.c

#utils.o
utils.o:utils.c utils.h
	gcc -c utils.c

#clean
clean:
	rm tst *.o

#lib(create the static library)
static:Crypto.o md5.o utils.o
	ar cr libCryptoN.a Crypto.o md5.o utils.o
	test -d bin || mkdir -p bin
	cp libCryptoN.a ./bin/libCryptoN.a
	cp Crypto.h  ./bin/CryptoN.h
	test -d run || mkdir -p run
	mv libCryptoN.a ./run/libCryptoN.a
	cp Crypto.h  ./run/CryptoN.h
	cp md5.h  ./run/md5.h
	cp utils.h  ./run/utils.h
	rm tst *.o
	
#run(test the program)
run:
	tst