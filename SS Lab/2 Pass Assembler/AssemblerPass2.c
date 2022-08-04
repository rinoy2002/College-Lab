#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    char a[20],ad[20],label[20],opcode[20],operand[20],symbol[20],ch;
    int st,diff,i=0,address,add,len,actual_len,finaddr,prevaddr,j=0,length,tlen=0,l=0,flag1,flag2,flag3,m;
    char mnemonic[30][20],txtrec[2048],temp[5];
    char code[30][20];
    FILE *fp1,*fp2,*fp3,*fp4,*fp5;

    fp1=fopen("ASSMLIST.TXT","w");
    fp2=fopen("SYMTAB.TXT","r");
    fp3=fopen("INTMFILE.TXT","r");
    fp4=fopen("OBJCODE.TXT","w");
    fp5=fopen("OPTAB.TXT","r");

    fscanf(fp5,"%s\t%s",opcode,operand);
    while(strcmp(opcode,"RESW")!=0){
            strcpy(mnemonic[i],opcode);
            strcpy(code[i],operand);
            fscanf(fp5,"%s\t%s",opcode,operand);
            i++;
    }

    fscanf(fp3,"%X\t%s\t%s\t%s",&address,label,opcode,operand);
    length=address;
    while(strcmp(opcode,"END")!=0){
        prevaddr=address;
        fscanf(fp3,"%X\t%s\t%s\t%s",&address,label,opcode,operand);
    }
    finaddr=address;
    length=finaddr-length;
    fclose(fp3);
    fp3=fopen("INTMFILE.TXT","r");
    fscanf(fp3,"%X\t%s\t%s\t%s",&address,label,opcode,operand);
    if(strcmp(opcode,"START")==0){
        fprintf(fp1,"\t%s\t%s\t%s\n",label,opcode,operand);
        fprintf(fp4,"H^%-6s^00%s^%06X\n",label,operand,length);
        fscanf(fp3,"%X\t%s\t%s\t%s",&address,label,opcode,operand);
        st=address;
        diff=prevaddr-st;
      //  sprintf(txtrec,"T^%06x^  ",address);
    }
    while(strcmp(opcode,"END")!=0){
        if(strcmp(opcode,"BYTE")==0){
           fprintf(fp1,"%X\t%s\t%s\t%s\t",address,label,opcode,operand);
            len=strlen(operand);
            actual_len=len-3;
            if(tlen==0){
                sprintf(txtrec,"T^%06X^  ",address);
            }else if(tlen+actual_len<=30){

            }else{
                sprintf(temp,"%X",tlen);
                for(l=0;l<2;l++){
                    txtrec[l+9]=temp[l];
                }
                fprintf(fp4,"%s\n",txtrec);
                strcpy(txtrec,"");
                sprintf(txtrec+strlen(txtrec),"T^%06X^  ",address);
                tlen=0;
            }
            tlen=tlen+actual_len;
            sprintf(txtrec+strlen(txtrec),"^");
            for(i=2;i<(actual_len+2);i++){
                itoa(operand[i],ad,16);
                fprintf(fp1,"%s",ad);
                sprintf(txtrec+strlen(txtrec),"%s",ad);
            }
            fprintf(fp1,"\n");
        }else if(strcmp(opcode,"WORD")==0){
           len=strlen(operand);
            itoa(atoi(operand),a,10);
            fprintf(fp1,"%X\t%s\t%s\t%s\t%06s\n",address,label,opcode,operand,a);
            if(tlen==0){
                strcpy(txtrec,"");
                sprintf(txtrec+strlen(txtrec),"T^%06X^  ",address);
            }else if(tlen+3<=30){

            }else{
                sprintf(temp,"%X",tlen);
                for(l=0;l<2;l++){
                    txtrec[l+9]=temp[l];
                }
                fprintf(fp4,"%s\n",txtrec);
                strcpy(txtrec,"");
                sprintf(txtrec+strlen(txtrec),"T^%06X^  ",address);
                tlen=0;
            }
            tlen=tlen+3;
            sprintf(txtrec+strlen(txtrec),"^%06s",a);
        }else if((strcmp(opcode,"RESB")==0)||(strcmp(opcode,"RESW")==0)){
            fprintf(fp1,"%X\t%s\t%s\t%s\t-\n",address,label,opcode,operand);
            sprintf(temp,"%02X",tlen);
            for(l=0;l<2;l++){
                txtrec[l+9]=temp[l];
            }
            fprintf(fp4,"%s\n",txtrec);
            strcpy(txtrec,"");
            tlen=0;
        }else{
            if(tlen==0){
                sprintf(txtrec,"T^%06X^  ",address);
            }
           else if(tlen+3<=30){

            }else{
                sprintf(temp,"%X",tlen);
                for(l=0;l<2;l++){
                    txtrec[l+9]=temp[l];
                }
                fprintf(fp4,"%s\n",txtrec);
                tlen=0;
            }
            j=0;
            while(strcmp(opcode,mnemonic[j])!=0){
                j++;
            }
            flag3=0;
            fp2=fopen("SYMTAB.TXT","r");
            if(strcmp(opcode,mnemonic[j])==0){
                while(!feof(fp2)){
                    flag1=0;
                    flag2=0;
                    fscanf(fp2,"%s\t%X",symbol,&add);
                    for(m=0;m<strlen(operand);m++){
                            if(operand[m]==',')
                                flag1=1;
                            if(operand[m]=='X')
                                flag2=1;
                    }
                    if(flag1==1&&flag2==1){
                           operand[strlen(operand)-2]='\0';
                           flag3=1;
                    }
                    if(strcmp(operand,symbol)==0){
                        if(flag3==1){
                            add=add|32768;
                        }
                        if(strcmp(code[j],"4C")==0){
                            add=0;
                        }
                        fprintf(fp1,"%X\t%s\t%s\t%s\t%s%04X\n",address,label,opcode,operand,code[j],add);
                        sprintf(txtrec+strlen(txtrec),"^%s%04X",code[j],add);
                        tlen=tlen+3;
                    }
                }
            }
        }
        fscanf(fp3,"%X\t%s\t%s\t%s",&address,label,opcode,operand);
    }
    fprintf(fp1,"%X\t%s\t%s\t%s\n",address,label,opcode,operand);
    fprintf(fp4,"\nE^%06X",st);
}
