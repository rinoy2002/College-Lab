#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int states, syms, init_state, fin_st_ct, fin_states[10] = {0}, my_tb[100][100] = {0}, new_states[10] = {0}, trans[100][100] = {0};
    printf("Enter the number of states : ");
    scanf("%d", &states);
    printf("Enter the number of alphabets : ");
    scanf("%d", &syms);
    printf("Enter the initial state : ");
    scanf("%d", &init_state);
    printf("Enter the number of final states : ");
    scanf("%d", &fin_st_ct);
    printf("Enter the final states : ");
    for(int i=0;i<fin_st_ct;i++){
        int k;
        scanf("%d",&k);
        fin_states[k]=1;
    }
    
    printf("Enter the transitions (state alphabet state) :\n");
    for (int i=0;i<states;i++){
        for (int j = 0; j < syms; j++){
            printf("%d %d ", i, j);
            scanf("%d", &trans[i][j]);
        }
    }

    for (int i=0;i<states;i++){
        for (int j=0;j<states;j++){
            if (fin_states[j]==1 && fin_states[i]!=1){
                my_tb[i][j] = 1;
            }
            if (fin_states[i] == 1 && fin_states[j] != 1){
                my_tb[i][j] = 1;
            }
        }
    }
    
    int count;
    do{
        count = 0;
        for (int i = 0; i<states; i++){
            for (int j=0; j<states; j++){
                if (my_tb[i][j]!= 1){
                    for (int k=0; k<syms; k++){
                        if (my_tb[trans[i][k]][trans[j][k]] == 1){
                            count++;
                            my_tb[i][j] = 1;
                        }
                    }
                }
            }
        }
    } while(count != 0);
     
    printf("\nStates to be combined :\n");
    for(int i=0; i<states; i++){
        for (int j = i+1; j < states; j++){
            if (my_tb[i][j] == 0){
                printf("( %d %d )\n", i, j);
            }
        }
    }
}