#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
void main(){
    int LOCCTR;
    int start,num,symbol=0,vopcode,len,i=0,n=0;
    FILE *fp1,*fp2,*fp3,*fp4;
    char label[20],opcode[20],operand[20];
    char OPTAB[30][20];
    char SYMTAB[20][20];
    double temp;
    fp1=fopen("INPUT.TXT","r");
    fp2=fopen("SYMTAB.TXT","w");
    fp3=fopen("OPTAB.TXT","r");
    fp4=fopen("INTMFILE.TXT","w");
    while(!feof(fp3)){
            fscanf(fp3,"%s\t%s",opcode,operand);
            strcpy(OPTAB[i++],opcode);
    }
    fscanf(fp1,"%s\t%s",label,opcode);
    if(strcmp(opcode,"START")==0){
        fscanf(fp1,"%X",&LOCCTR);
        fprintf(fp4,"%X\t%s\t%s\t%X\n",LOCCTR,label,opcode,LOCCTR);
    }else{
        LOCCTR=0;
    }
    start=LOCCTR;
    while(!feof(fp1)){
        fscanf(fp1,"%s\t%s\t%s",label,opcode,operand);
        if(strcmp(opcode,"END")!=0){
            if(strcmp(label,"//")!=0){
                for(i=0;i<30;i++){
                    if(strcmp(opcode,OPTAB[i])==0){
                        vopcode=0;
                        break;
                    }
                    vopcode=1;
                }
                if(strcmp(label,"-")!=0){
                    for(i=0;i<n;i++){
                        if(strcmp(label,SYMTAB[i])==0){
                            symbol=1;
                            break;
                        }
                        symbol=0;
                    }
                    if(symbol==0){
                        fprintf(fp2,"%s\t%X\n",label,LOCCTR);
                        strcpy(SYMTAB[n++],label);
                    }
                }
                fprintf(fp4,"%X\t%s\t%s\t%s\n",LOCCTR,label,opcode,operand);
                if(symbol==1)
                    fprintf(fp4,"ERROR:SYMBOL ALREADY DEFINED\n");
                if(vopcode==1)
                    fprintf(fp4,"ERROR:WRONG OPCODE\n");
                num=atoi(operand);
                if(strcmp(opcode,"RESW")==0)
                    LOCCTR=LOCCTR+(num*3);
                else if(strcmp(opcode,"RESB")==0)
                    LOCCTR=LOCCTR+num;
                else if(strcmp(opcode,"BYTE")==0){
                    if(operand[0]=='C'){
                        num=strlen(operand)-3;
                        LOCCTR=LOCCTR+num;
                   }else if(operand[0]=='X'){
                        temp=ceil(( (double) strlen(operand)-3)/2);
                        num=(int)temp;
                        LOCCTR=LOCCTR+num;
                    }
                }
                else if(strcmp(opcode,"WORD")==0)
                    LOCCTR=LOCCTR+3;
                else
                    LOCCTR=LOCCTR+3;
            }
        }
    }
    fprintf(fp4,"%X\t%s\t%s\t%s\n",LOCCTR,label,opcode,operand);
    len=LOCCTR-start;
    fprintf(fp4,"PROGRAM LENGTH %X",len);
    fprintf(fp2,"-");
    fclose(fp1);
    fclose(fp2);
    fclose(fp4);
}
