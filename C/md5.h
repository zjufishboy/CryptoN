
#include<stdio.h>
#include<stdlib.h>
#ifndef CN_MD5
#define CN_MD5
#include"utils.h"
#define debug 2
#define isbigEnd 1

char * md5(char * plaintext,long length);
static char * md5_step1(char * plaintext,int length);
static char * md5_step2(char * plaintext,int length);
#endif


