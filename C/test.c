#include<stdio.h>
#include"test.h"
#include"Crypto.h"

#define PT_LENGTH 32
int main(){
    testEnv();
    char plaintext[PT_LENGTH]="this is a test text for CryptoN";
    printf("CRYPTO:%8s:%-80s\n","TEXT",plaintext);
    printf("CRYPTO:%8s:%-80s\n","MD5" ,md5(plaintext,PT_LENGTH));
    printf("CRYPTO:%8s:%-80s\n","DES" ,plaintext);
    printf("CRYPTO:%8s:%-80s\n","AES" ,plaintext);
    printf("CRYPTO:%8s:%-80s\n","ECC" ,plaintext);
    printf("CRYPTO:%8s:%-80s\n","RSA" ,plaintext);
}