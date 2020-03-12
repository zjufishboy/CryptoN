#include"md5.h"
/**
 * author:zjufishboy
 * time  :2020-3-12
 */
char * md5(char * plaintext){
    int i=0;
    int length=strlen(plaintext)+1;
    //step1:fill the data
    char * ciphertext=md5_step1(plaintext,length);
    int isbigEnd=0;
    testEnvBigEnd(&isbigEnd);

    //step2:circle calculation
    ciphertext=md5_step2(ciphertext,length,isbigEnd);
    return ciphertext;
}

// tool function
unsigned int F(unsigned int X,unsigned int Y,unsigned int Z){
    return (X & Y) | ((~X) & Z);
}
unsigned int G(unsigned int X,unsigned int Y,unsigned int Z){
    return (X & Z) | (Y & (~Z)); 
}
unsigned int H(unsigned int X,unsigned int Y,unsigned int Z){
    return X ^ Y ^ Z;
}
unsigned int I(unsigned int X,unsigned int Y,unsigned int Z){
    return Y ^ (X | (~Z));
}

void FF(unsigned int *a,unsigned int *b,unsigned int *c,unsigned int *d,unsigned int Mj,int s,unsigned int ti){
    *a=*b+leftmove((*a+F(*b,*c,*d)+Mj+ti),s);
}
void GG(unsigned int *a,unsigned int *b,unsigned int *c,unsigned int *d,unsigned int Mj,int s,unsigned int ti){
    *a=*b+leftmove((*a+G(*b,*c,*d)+Mj+ti),s);
}
void HH(unsigned int *a,unsigned int *b,unsigned int *c,unsigned int *d,unsigned int Mj,int s,unsigned int ti){
    *a=*b+leftmove((*a+H(*b,*c,*d)+Mj+ti),s);
}
void II(unsigned int *a,unsigned int *b,unsigned int *c,unsigned int *d,unsigned int Mj,int s,unsigned int ti){
    *a=*b+leftmove((*a+I(*b,*c,*d)+Mj+ti),s);
}

char * md5_step1(char * plaintext,int length){
    //step1.1:get the hex of data:
    char * tempText=charBin2Hex(plaintext,length);
    //step1.2:get the true length:
    int length_content=length-1;        //the length of content
    int length_1_3=length_content*8;    //the length of content in bits
    int length_1_4;                     //the length of other word in 448 bits 

    if(448-length_1_3%512>0)
        length_1_4=448-length_1_3%512;
    else if(448-length_1_3%512<0)
        length_1_4=448+512-length_1_3%512;
    else
        length_1_4=512;
    
    int length_1_5=64;                  //the length of the left 64;

    int clength_1_3=length_1_3/4;
    int clength_1_4=length_1_4/4;
    int clength_1_5=length_1_5/4;
    

    int length_true=(length_1_3+length_1_4+length_1_5)/4+1;
    char * copyword= (char *)malloc(length_true*sizeof(char));
    int i=0;
    //step1.3:fill the 448 bit and the other 64:
    
    //copy the hex of plaintext
    for(i=0;i<clength_1_3;i++){
        copyword[i]=tempText[i];
    }

    //set the 448 bits
   copyword[i]='8';
    for(i=1;i<clength_1_4;i++){
        copyword[i+clength_1_3]='0';
    }

    //set the length
    char * lengthString=get64Num(length_content*8);
    for(i=0;i<clength_1_5;i++){
        copyword[i+clength_1_3+clength_1_4]=lengthString[i];
    }
    copyword[length_true]='\0';
    
    //free the space
    free(tempText);
    free(lengthString);

    return copyword;
}

char * md5_step2(char * ciphertext,int length,int isbigEnd){
    int len=strlen(ciphertext);         
    unsigned int *data=Hex2Int(ciphertext,len);
    int length_true=len*4;
    
    //Chaining Variable
    unsigned int A=(isbigEnd==1)?0x01234567:0x67452301;
    unsigned int B=(isbigEnd==1)?0x89ABCDEF:0xEFCDAB89; 
    unsigned int C=(isbigEnd==1)?0xFEDCBA98:0x98BADCFE;
    unsigned int D=(isbigEnd==1)?0x76543210:0x10325476;
    unsigned int M[16];
    unsigned int a,b,c,d;
    int i=0,j=0;
    for(i=0;i<length_true/512;i++){//512位一组
            for(j=0;j<16;j++)
                M[j]=data[i*16+j];
            if(i==0){
                a=A;
                b=B;
                c=C;
                d=D;
            }
            else{
                A=a;
                B=b;
                C=c;
                D=d;
            }
            FF(&a,&b,&c,&d,M[ 0], 7,0xd76aa478);
            FF(&d,&a,&b,&c,M[ 1],12,0xe8c7b756);
            FF(&c,&d,&a,&b,M[ 2],17,0x242070db);
            FF(&b,&c,&d,&a,M[ 3],22,0xc1bdceee);
            FF(&a,&b,&c,&d,M[ 4], 7,0xf57c0faf);
            FF(&d,&a,&b,&c,M[ 5],12,0x4787c62a);
            FF(&c,&d,&a,&b,M[ 6],17,0xa8304613);
            FF(&b,&c,&d,&a,M[ 7],22,0xfd469501);
            FF(&a,&b,&c,&d,M[ 8], 7,0x698098d8);
            FF(&d,&a,&b,&c,M[ 9],12,0x8b44f7af);
            FF(&c,&d,&a,&b,M[10],17,0xffff5bb1);
            FF(&b,&c,&d,&a,M[11],22,0x895cd7be);
            FF(&a,&b,&c,&d,M[12], 7,0x6b901122);
            FF(&d,&a,&b,&c,M[13],12,0xfd987193);
            FF(&c,&d,&a,&b,M[14],17,0xa679438e);
            FF(&b,&c,&d,&a,M[15],22,0x49b40821);

            GG(&a,&b,&c,&d,M[1 ], 5,0xf61e2562);
            GG(&d,&a,&b,&c,M[6 ], 9,0xc040b340);
            GG(&c,&d,&a,&b,M[11],14,0x265e5a51);
            GG(&b,&c,&d,&a,M[0 ],20,0xe9b6c7aa);
            GG(&a,&b,&c,&d,M[5 ], 5,0xd62f105d);
            GG(&d,&a,&b,&c,M[10], 9,0x02441453);
            GG(&c,&d,&a,&b,M[15],14,0xd8a1e681);
            GG(&b,&c,&d,&a,M[4 ],20,0xe7d3fbc8);
            GG(&a,&b,&c,&d,M[9 ], 5,0x21e1cde6);
            GG(&d,&a,&b,&c,M[14], 9,0xc33707d6);
            GG(&c,&d,&a,&b,M[3 ],14,0xf4d50d87);
            GG(&b,&c,&d,&a,M[8 ],20,0x455a14ed);
            GG(&a,&b,&c,&d,M[13], 5,0xa9e3e905);
            GG(&d,&a,&b,&c,M[2 ], 9,0xfcefa3f8);
            GG(&c,&d,&a,&b,M[7 ],14,0x676f02d9);
            GG(&b,&c,&d,&a,M[12],20,0x8d2a4c8a);


            HH(&a,&b,&c,&d,M[5 ], 4,0xfffa3942);
            HH(&d,&a,&b,&c,M[8 ],11,0x8771f681);
            HH(&c,&d,&a,&b,M[11],16,0x6d9d6122);
            HH(&b,&c,&d,&a,M[14],23,0xfde5380c);
            HH(&a,&b,&c,&d,M[1 ], 4,0xa4beea44);
            HH(&d,&a,&b,&c,M[4 ],11,0x4bdecfa9);
            HH(&c,&d,&a,&b,M[7 ],16,0xf6bb4b60);
            HH(&b,&c,&d,&a,M[10],23,0xbebfbc70);
            HH(&a,&b,&c,&d,M[13], 4,0x289b7ec6);
            HH(&d,&a,&b,&c,M[0 ],11,0xeaa127fa);
            HH(&c,&d,&a,&b,M[3 ],16,0xd4ef3085);
            HH(&b,&c,&d,&a,M[6 ],23,0x04881d05);
            HH(&a,&b,&c,&d,M[9 ], 4,0xd9d4d039);
            HH(&d,&a,&b,&c,M[12],11,0xe6db99e5);
            HH(&c,&d,&a,&b,M[15],16,0x1fa27cf8);
            HH(&b,&c,&d,&a,M[2 ],23,0xc4ac5665);


            II(&a,&b,&c,&d,M[ 0], 6,0xf4292244);
            II(&d,&a,&b,&c,M[ 7],10,0x432aff97);
            II(&c,&d,&a,&b,M[14],15,0xab9423a7);
            II(&b,&c,&d,&a,M[ 5],21,0xfc93a039);
            II(&a,&b,&c,&d,M[12], 6,0x655b59c3);
            II(&d,&a,&b,&c,M[ 3],10,0x8f0ccc92);
            II(&c,&d,&a,&b,M[10],15,0xffeff47d);
            II(&b,&c,&d,&a,M[ 1],21,0x85845dd1);
            II(&a,&b,&c,&d,M[ 8], 6,0x6fa87e4f);
            II(&d,&a,&b,&c,M[15],10,0xfe2ce6e0);
            II(&c,&d,&a,&b,M[ 6],15,0xa3014314);
            II(&b,&c,&d,&a,M[13],21,0x4e0811a1);
            II(&a,&b,&c,&d,M[ 4], 6,0xf7537e82);
            II(&d,&a,&b,&c,M[11],10,0xbd3af235);
            II(&c,&d,&a,&b,M[ 2],15,0x2ad7d2bb);
            II(&b,&c,&d,&a,M[ 9],21,0xeb86d391);
            a+=A;
            b+=B;
            c+=C;
            d+=D;
        }
    char* ciphertextFinal=(char*)malloc(sizeof(char)*33);
    strcpy(ciphertextFinal+0 ,Int2Hex(a));
    strcpy(ciphertextFinal+8 ,Int2Hex(b));
    strcpy(ciphertextFinal+16,Int2Hex(c));
    strcpy(ciphertextFinal+24,Int2Hex(d));
    ciphertextFinal[32]='\0';
    //free the space
    free(ciphertext);
    return ciphertextFinal;
}