/**
 * author:zjufishboy
 * time  :2020-3-12
 */
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
 * function   :leftmove
 * input      :number,length
 * output     :void
 * description:this is a tool function to left move the data.
 */
unsigned int leftmove(unsigned int number,int length){
    int i=0;
    for(i=0;i<length;i++)
        number=(number<<1)+((number&(1<<31))>>31);
    return number;
}
/**
 * function   :Hex2Int
 * input      :hex,length
 * output     :int
 * description:this is a tool function to change hex char into int.
 */

unsigned int *Hex2Int(char * hex, int length){
    unsigned int * ints=(unsigned int*)malloc(sizeof(unsigned int)*(length/8));
    int i=0;
    for(i=0;i<length/8;i++){
        ints[i]=0;
        ints[i]+=(hex[6+i*8]-(hex[6+i*8]>='A'?'A'-10:'0'))*16*16*16*16*16*16*16;
        ints[i]+=(hex[7+i*8]-(hex[7+i*8]>='A'?'A'-10:'0'))*16*16*16*16*16*16   ;
        ints[i]+=(hex[4+i*8]-(hex[4+i*8]>='A'?'A'-10:'0'))*16*16*16*16*16      ;
        ints[i]+=(hex[5+i*8]-(hex[5+i*8]>='A'?'A'-10:'0'))*16*16*16*16         ;
        ints[i]+=(hex[2+i*8]-(hex[2+i*8]>='A'?'A'-10:'0'))*16*16*16            ;
        ints[i]+=(hex[3+i*8]-(hex[3+i*8]>='A'?'A'-10:'0'))*16*16               ;
        ints[i]+=(hex[0+i*8]-(hex[0+i*8]>='A'?'A'-10:'0'))*16                  ;
        ints[i]+=(hex[1+i*8]-(hex[1+i*8]>='A'?'A'-10:'0'))                     ;
    }
    return ints;
}
/**
 * function   :Int2Hex
 * input      :num
 * output     :hex
 * description:this is a tool function to change int into hex char.
 */

char *Int2Hex(unsigned int number){
    char*hex=(char*)malloc(sizeof(char)*8);
    int i=7;
    int temp;
    char tempc;
    for(i=7;i>=0;i--){
        temp=number%16;
        if(temp>=10)
            hex[i]='A'+temp-10;
        else
            hex[i]='0'+temp;
        number/=16;
    }
    for(i=0;i<2;i++){
        tempc=hex[i*2];
        hex[i*2]=hex[7-i*2-1];
        hex[7-i*2-1]=tempc;
        tempc=hex[i*2+1];
        hex[i*2+1]=hex[7-i*2];
        hex[7-i*2]=tempc;
    }
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
    char temp;
    for(i=0;i<16;i++){
        number[i]=getHexSingleNumber((length&(operator<<((15-i)*4)))>>((15-i)*4));
    }
    for(i=0;i<4;i++){
        temp=number[i*2];
        number[i*2]=number[15-i*2-1];
        number[15-i*2-1]=temp;
        temp=number[i*2+1];
        number[i*2+1]=number[15-i*2];
        number[15-i*2]=temp;
    }
    number[16]='\0';
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
void testEnvBigEnd(int *isBigEnd)
{
    int a = 0x12345678;//十六进制值为0x12345678
    char *p = (char*)&a;//强转地址，使得指针p仅可以解引用到一个字节大小的值
    if(*p == 0x78)
    {
        *isBigEnd=0;
    }
    else
    {
        *isBigEnd=1;
    }
    return;
}