#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main()
{
    int states, syms, transitions[10][10][10] = {'\0'}, new_trans[10][10], fin_states[10], fin_st_ct, init_state;
    printf("Enter number of states\n");
    scanf("%d", &states);
    printf("Enter number of symbols\n");
    scanf("%d", &syms);
    printf("Enter number of final states\n");
    scanf("%d", &fin_st_ct);

    for (int i = 0; i < fin_st_ct; i++)
    {
        int fin_state;
        printf("Enter final state\n");
        scanf("%d", &fin_state);
        fin_states[fin_state] = 1;
    }

    printf("Enter initial state\n");
    scanf("%d", &init_state);

    int from, to, alph;
    do
    {
        printf("Enter from state,to state and transition symbol or-1 to exit\n");
        scanf("%d", &from);
        if (from == -1)
            break;
        scanf("%d", &to);
        scanf("%d", &alph);
        transitions[from][alph][to] = 1;
    } while (1);

    char new_states[20][10] = {'\0'};
    int k = 0;
    memset(new_states[k], (char)(init_state + 48), sizeof(char));

    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            new_trans[i][j] = -1;
        }
    }
    for (int i = 0; i <= k; i++)
    {
        int temp = i;
        for (int s = 0; s < syms; s++)
        {
            char str[20] = {'\0'};
            printf("\n\n\n%s for %d\n", new_states[i], s);
            for (int j = 0; j < strlen(new_states[i]); j++)
            {
                int state = (int)(new_states[i][j]) - 48;
                // printf("\n%s for %d\n", new_states[i], state);
                for (int l = 0; l < states; l++)
                {

                    if (transitions[state][s][l] == 1)
                    {
                        printf("%d for %d to %d under %s\n", state, s, l, new_states[i]);
                        int flag = 0;
                        char st = (char)(l + 48);
                        for (int t = 0; t < strlen(str); t++)
                        {
                            // printf("%c %c\n", str[t], st);
                            if (str[t] == st)
                            {
                                flag = 1;
                            }
                        }
                        if (flag == 0)
                        {
                            strncat(str, &st, 1);
                        }
                    }
                }
            }
            if (strlen(str) > 0)
            {
                int flag = -1;
                for (int i = 0; i <= k; i++)
                {
                    if (strcmp(str, new_states[i]) == 0)
                    {
                        flag = i;
                        break;
                    }
                }
                if (flag == -1)
                {
                    memmove(new_states[++k], str, strlen(str));
                    new_trans[temp][s] = k;
                }
                else
                {
                    new_trans[temp][s] = flag;
                }
            }
        }
    }
    for (int i = 0; i <= k; i++)
    {
        printf("\n\n%s\n", new_states[i]);
        for (int j = 0; j < syms; j++)
        {
            if (new_trans[i][j] == -1)
            {
                printf("%d -> %s\n", j, "dead state");
            }
            else
            {
            printf("%d -> %s\n", j, new_states[new_trans[i][j]]);
            }
        }
    }
}  