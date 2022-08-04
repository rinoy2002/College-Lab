#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void main(){
    FILE *inputFile,*nameFile,*defTab;
    char mne[20],opnd[20],la[20];
    inputFile=fopen("INPUT.txt","r");
    nameFile=fopen("NAMTAB.txt","w+");
    defTab=fopen("DEFTAB.txt","w+");
    fscanf(inputFile,"%s%s%s",la,mne,opnd);
    while(strcmp(mne,"MEND")!=0){
       if(strcmp(mne,"MACRO")==0){
           fprintf(nameFile,"%s\n",la);
           fprintf(defTab,"%s\t%s\t%s\n",la,mne,opnd);
       }
       else
           fprintf(defTab,"%s\t%s\t%s\n",la,mne,opnd);
    fscanf(inputFile,"%s%s%s",la,mne,opnd);
    }
    fprintf(defTab,"-\t%s",mne);
    fclose(inputFile);
    fclose(nameFile);
    fclose(defTab);
}