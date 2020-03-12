/**
 * author:zjufishboy
 * time  :2020-3-12
 */
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
void testEnvBigEnd(int*isBigEnd);
unsigned int *Hex2Int(char * hex, int length);
char *Int2Hex(unsigned int number);
unsigned int leftmove(unsigned int number,int length);
#endif
