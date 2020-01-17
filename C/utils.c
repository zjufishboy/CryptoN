#include"utils.h"

/**
 * function   :charBin2Hex
 * input      :word,length
 * output     :hex
 * description:this is a tool function to change word into hex.
 */

char *charBin2Hex(char * word, int length){
    char * hex=(char*)malloc((length*2-1)*sizeof(char));
    int i=0;
    for(i=0;i<length-1;i++){
        hex[2*i]=word[i]/16;
        hex[2*i+1]=word[i]%16;
        hex[2*i]+=hex[2*i]>=10?'A'-10:'0';
        hex[2*i+1]+=hex[2*i+1]>=10?'A'-10:'0';    
    }
    hex[2*i]='\0';
    return hex;
}

/**
 * function   :getDivider
 * input      :dividerChar,length
 * output     :divider
 * description:this is a tool function to get the divider of fixed length of fixed char.
 */

char* getDivider(char dividerChar,int length){
    char * divider =(char *)malloc(sizeof(char)*(length+1));
    int i=0;
    for(i=0;i<length;i++){
        divider[i]=dividerChar;
    }
    divider[i]='\0';
    return divider;
}

/**
 * function   :get64Num
 * input      :int length
 * output     :the length word
 * description:this is a tool function to get the length in 64bit and hex.
 */

char * get64Num(long length){
    long operator=15;
    char * number=(char *)malloc(sizeof(char)*(1+64/4));
    int i=0;
    for(i=0;i<16;i++){
        number[i]=getHexSingleNumber((length&(operator<<((15-i)*4)))>>((15-i)*4));
    }
    number[i]='\0';
    return number;
}

/**
 * function   :getHexSingleNumber
 * input      :int number
 * output     :the number char
 * description:this is a tool function to get the number in hex.
 */

char getHexSingleNumber(int number){
    return number>9?number-10+'A':number+'0';
}

/**
 * function   :testEnv
 * input      :int number
 * output     :the number char
 * description:this is a tool function to get the number in hex.
 */
void testEnv(){
    printf("%96s\n",getDivider('-',96));
    printf("Integer:%4ld bytes=%4ld bits\n",sizeof(int),8*sizeof(int));
    printf("Long   :%4ld bytes=%4ld bits\n",sizeof(long),8*sizeof(long));
    printf("Char   :%4ld bytes=%4ld bits\n",sizeof(char),8*sizeof(char));
    printf("Double :%4ld bytes=%4ld bits\n",sizeof(double),8*sizeof(double));
    printf("Float  :%4ld bytes=%4ld bits\n",sizeof(float),8*sizeof(float));
    printf("%96s\n",getDivider('-',96));
}

/**
 * function   :len
 * input      :stringStart
 * output     :the length
 * description:this is a tool function to get the length of a string.
 * info       :this is a dangerous function, beacuse it may cause IndexOutOfBoundsException
 */
int len(char *stringStart){
    int i=0;
    while(*stringStart!='\0'){
        i++;
        stringStart++;
    }
    return i;
}