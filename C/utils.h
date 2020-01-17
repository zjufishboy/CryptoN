#include<stdio.h>
#include<stdlib.h>
#ifndef CN_UTILS
#define CN_UTILS

void testEnv();
char *charBin2Hex(char * word, int length);
char* getDivider(char dividerChar,int length);
char * get64Num(long length);
static char getHexSingleNumber(int number);
int len(char *stringStart);

#endif
