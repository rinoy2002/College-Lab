#include<stdio.h>
#include<string.h>
#include<stdlib.h>
    
void main(){
  FILE *inputFile,*nameFile,*defFile,*argFile,*outputFile;
  int i,len;
  char mne[20],opnd[20],la[20],name[20],mne1[20],opnd1[20],la1[20],arg[20];
  inputFile = fopen("INPUT.txt","r");
  nameFile=fopen("NAMTAB.txt","r");
  defFile=fopen("DEFTAB.txt","r");
  argFile=fopen("ARGTAB.txt","w+");
  outputFile=fopen("OUTPUT.txt","w");

  fscanf(inputFile,"%s%s%s",la,mne,opnd);
  while(strcmp(mne,"END")!=0){
     if(strcmp(mne,"MACRO")==0){ 
         fscanf(inputFile,"%s%s%s",la,mne,opnd);
         while(strcmp(mne,"MEND")!=0)
            fscanf(inputFile,"%s%s%s",la,mne,opnd);
     }
     else{
         fscanf(nameFile,"%s",name);  
         if(strcmp(mne,name)==0){     
            len=strlen(opnd);
            for(i=0;i<len;i++){  
                if(opnd[i]!=',')
                     fprintf(argFile,"%c",opnd[i]);
                else
                     fprintf(argFile,"\n");
            }
            fseek(nameFile,SEEK_SET,0);
            fseek(argFile,SEEK_SET,0);
            fscanf(defFile,"%s%s%s",la1,mne1,opnd1);
            fprintf(outputFile,".\t%s\t%s\t%s\n",la1,mne1,opnd); 
            fscanf(defFile,"%s%s%s",la1,mne1,opnd1);
            while(strcmp(mne1,"MEND")!=0){
                if((opnd1[0]=='&')){
                    fscanf(argFile,"%s",arg);
                    fprintf(outputFile,"-\t%s\t%s\n",mne1,arg);
                }
                else
                     fprintf(outputFile,"-\t%s\t%s\n",mne1,opnd1);
                fscanf(defFile,"%s%s%s",la1,mne1,opnd1);
            }
            fseek(defFile,SEEK_SET,0);
            fseek(argFile,SEEK_SET,0);
         }
         else
            fprintf(outputFile,"%s\t%s\t%s\n",la,mne,opnd);
    }
    fscanf(inputFile,"%s%s%s",la,mne,opnd); // Read Next Input line
  }
  fprintf(outputFile,"%s\t%s\t%s\n",la,mne,opnd);
  fclose(inputFile);
  fclose(nameFile);
  fclose(defFile);
  fclose(argFile);
  fclose(outputFile);
}