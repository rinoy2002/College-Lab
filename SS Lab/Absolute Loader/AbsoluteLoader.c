/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main(){
    char rec[2048];
    int address,1;
    FILE *fp1,*fp2;
    fp1=fopen("OBJCODE.TXT","r");
    fp2=fopen("MEMORY.TXT","w");
    fscanf(fp,"%s",rec);
    for(i=9;i<15;i++){

    }
    for(i=0;i<strlen(rec);i++){

    }
}*/
    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    void main()
    {
      FILE *fp;
      int i,addr1,l,j,staddr1;
      char name[10],line[2048],name1[10],addr[10],rec[10],ch,staddr[10];
      fp=fopen("OBJCODE.TXT","r");
      fscanf(fp,"%s",line);
      fscanf(fp,"%s",line);
      while(!feof(fp)){
          fscanf(fp,"%s",line);
          printf("%s\n",line);
          if(line[0]=='T'){
              for(i=2,j=0;i<8,j<6;i++,j++)
                  staddr[j]=line[i];
              staddr[j]='\0';
              printf("%s",staddr);
              staddr1=atoi(staddr);
              i=12;
             /* while(line[i]!='\n'){
                  if(line[i]!='^'){
                      printf("00%d \t %c%c\n", staddr1,line[i],line[i+1]);
                      staddr1++;
                      i=i+2;
                  }
                  else i++;
              }*/
          }
        else if(line[0]=='E'){
            break;
        }
      }
    }

