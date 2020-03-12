/**
 * author:zjufishboy
 * time  :2020-3-12
 */
#include<stdio.h>
#include"CryptoN.h"
#define PT_LENGTH 32
int main(){
    testEnv();
    char plaintext[]="this is a test text for CryptoNthis is a test text for CryptoNthis is a test text for CryptoNthis is a test text for CryptoN";
    printf("CRYPTO:%8s:%-80s\n","TXT",plaintext);
    printf("CRYPTO:%8s:%-80s\n","MD5" ,md5(plaintext));
    // printf("CRYPTO:%8s:%-80s\n","DES" ,plaintext);
    // printf("CRYPTO:%8s:%-80s\n","AES" ,plaintext);
    // printf("CRYPTO:%8s:%-80s\n","ECC" ,plaintext);
    // printf("CRYPTO:%8s:%-80s\n","RSA" ,plaintext);
}