#include"md5.h"

char * md5(char * plaintext,long length){
    int i=0;

    //step1:find the length of data;the length should be 512*n+448(bit);
    char * ciphertext=md5_step1(plaintext,length);
    
    return ciphertext;
}
char * md5_step1(char * plaintext,int length){
    //step1.1:get the hex of data:
    char * tempText=charBin2Hex(plaintext,length);
    char * divider=getDivider('-',96);
    if(debug==1)printf("%96s\n",divider);
    if(debug==1)printf("step%2.1f(%6s):%-80s\n",1.1,"hex",tempText);

    //step1.2:get the true length:
    int length_content=length-1;        //the length of content
    int length_1_3=length_content*8;    //the length of content in bits
    int length_1_4;  //the length of other word in 448 bits 

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
    if(debug>=1)printf("step%2.1f(%6s):%-37d=>%-10d%-10d%-17dbits\n",1.2,"length",length_1_3,length_1_4,length_1_5,(length_true-1)*4);
    int i=0;
    //step1.3:fill the 448 bit and the other 64:
    
    //copy the hex of plaintext
    for(i=0;i<clength_1_3;i++){
        copyword[i]=tempText[i];
    }

    if(debug>=1)printf("step%2.1f(%6s):%-80s\n",1.3,"hex",copyword);
    //set the 448 bits
   copyword[i]='8';
    for(i=1;i<clength_1_4;i++){
        copyword[i+clength_1_3]='0';
    }
    if(debug>=1)printf("step%2.1f(%6s):%-80s\n",1.4,"448",copyword);
    //set the length
    char * lengthString=get64Num(length_content*8);
    for(i=0;i<clength_1_5;i++){
        copyword[i+clength_1_3+clength_1_4]=lengthString[i];
    }
    copyword[length_true]='\0';
    
    if(debug>=1)printf("step%2.1f(%6s):%-80s\n",1.5,"64",copyword);
    if(debug>=1)printf("%96s\n",divider);
    
    //free the space
    free(tempText);
    free(divider);
    free(lengthString);

    return copyword;
}

char * md5_step2(char * ciphertext,int length){
    int length_1_3=(length-1)*8;        //the length of content in bits
    int length_1_4;                     //the length of other word in 448 bits 
    if(448-length_1_3%512>0)
        length_1_4=448-length_1_3%512;
    else if(448-length_1_3%512<0)
        length_1_4=448+512-length_1_3%512;
    else
        length_1_4=0;
    int length_1_5=64;                  //the length of the left 64;
    int length_true=(length_1_3+length_1_4+length_1_5);
    
    //Chaining Variable
    int A=(isbigEnd==1)?0x01234567:0x67452301;
    int B=(isbigEnd==1)?0x89ABCDEF:0xEFCDAB89; 
    int C=(isbigEnd==1)?0xFEDCBA98:0x98BADCFE;
    int D=(isbigEnd==1)?0x76543210:0x10325476;

    int i=0,j=0;
    for(i=0;i<length_true/512;i++)
        for(j=0;j<16;j++);

}