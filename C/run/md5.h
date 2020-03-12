/**
 * author:zjufishboy
 * time  :2020-3-12
 */
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<string.h>
#ifndef CN_MD5
#define CN_MD5
#include"utils.h"
#define debug 1

char * md5(char * plaintext);
static char * md5_step1(char * plaintext,int length);
static char * md5_step2(char * plaintext,int length,int isbigEnd);
#endif


