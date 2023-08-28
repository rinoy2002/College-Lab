#include <stdio.h>
#include <string.h>

struct transition_nfa {
	char state1[3];
	char input;
	char state2[3];
};

struct state {
	int len;
	char states[10][3];
	int flag;
};

struct transition_dfa {
	struct state state1;
	char input;
	struct state state2;
};

// NFA data
char states_nfa[10][3], start_nfa[3], final_nfa[10][3], alpha[5];
struct transition_nfa table_nfa[30];

// DFA data
struct state states_dfa[100], start_dfa, final_dfa[100];
struct transition_dfa table_dfa[300];

void copyState(struct state* state1,struct state state2) {
	state1->len = state2.len;
	state1->flag = state2.flag;
	
	for(int i = 0; i < state2.len; i++) {
		strcpy(state1->states[i], state2.states[i]);
	}
}

int compareState(struct state state1,struct state state2) {
	if(state1.len != state2.len)
		return 0;
	
	int count = 0;
	
	for(int i = 0; i < state1.len; i++) {
		for(int j = 0; j < state2.len; j++) {
			if(!strcmp(state1.states[i], state2.states[j]))
				count++;
		}
	}
	
	if(count == state1.len)
		return 1;
	else
		return 0;
}

int containsState(struct state st, char state[]) {
	int flag = 0;
	
	for(int i = 0; i < st.len; i++) {
		if(!strcmp(st.states[i], state))
			flag = 1;
	}
	
	return flag;
}

void insertTransition(struct transition_dfa* table,struct state* state1, char input,struct state* state2, int i) {
	table[i].state1.len = state1->len;
	table[i].state1.flag = state1->flag;
	
	for(int j = 0; j < state1->len; j++) {
		strcpy(table[i].state1.states[j], state1->states[j]);
	}

	table[i].state2.len = state2->len;
	table[i].state2.flag = state2->flag;
	
	for(int j = 0; j < state2->len; j++) {
		strcpy(table[i].state2.states[j], state2->states[j]);
	}
	
	table[i].input = input;
}

void main() {
	int n, f, m, l;
	
	// Reading the NFA
	printf("Enter the no of states: ");
	scanf("%d", &n);
	
	printf("Enter the states:\n");
	for(int i = 0; i < n; i++) {
		scanf("%s", states_nfa[i]);
	}
	
	printf("Enter the start state: ");
	scanf("%s", start_nfa);
	
	printf("Enter the number of final states: ");
	scanf("%d", &f);
	
	printf("Enter the final states\n");
	for(int i = 0; i < f; i++) {
		scanf("%s", final_nfa[i]);
	}
	
	printf("Enter the number of alphabets: ");
	scanf("%d", &l);
	
	printf("Enter the alphabets\n");
	for(int i = 0; i < l; i++) {
		scanf(" %c", &alpha[i]);
	}
	
	printf("Enter the number of transitions: ");
	scanf("%d", &m);
	
	printf("Enter the transition table:\n");
	for(int i = 0; i < m; i++) {
		scanf("%s %c %s", table_nfa[i].state1, &table_nfa[i].input, table_nfa[i].state2);
	}
	
	// Converting to DFA
	int n1 = 0, f1 = 0, m1 = 0;
	
	// Finding start state of DFA
	strcpy(start_dfa.states[0], start_nfa); 
	start_dfa.len = 1;
	start_dfa.flag = 1;
	
	copyState(&states_dfa[n1], start_dfa); 
	n1++;
	
	struct state temp;
	
	copyState(&temp, start_dfa);
	
	int flag, isDead = 0;
	struct state dead;
	
	while(1) {
		for(int i = 0; i < l; i++) {
			struct state temp1;
			temp1.len = 0;
			temp1.flag = 0;
			
			// Process of creating DFA transition table
			for(int j = 0; j < temp.len; j++) {
				for(int k = 0; k < m; k++) {
					if(!strcmp(temp.states[j], table_nfa[k].state1) && alpha[i] == table_nfa[k].input && !containsState(temp1, table_nfa[k].state2)) {
						strcpy(temp1.states[temp1.len++], table_nfa[k].state2);
					}
				}
			}
			
			struct state state1, state2;
			
			copyState(&state1, temp);
			
			// Checking for dead state
			if(temp1.len == 0) {
				isDead = 1;
				dead.len = 1;
				dead.flag = 1;
				strcpy(dead.states[0], "q-");
				copyState(&state2, dead);
			} else {
				copyState(&state2, temp1);
				
				flag = 0;
				
				for(int k = 0; k < n1; k++) {
					if(compareState(states_dfa[k], temp1))
						flag = 1;
				}
				
				if(!flag)
					copyState(&states_dfa[n1++], temp1);
			}
			
			// Insertion into DFA transition table
			insertTransition(table_dfa, &state1, alpha[i], &state2, m1++);
		}
		
		flag = 0;
		
		for(int i = 0; i < n1; i++) {
			if(states_dfa[i].flag == 0) {
				flag = 1;
				copyState(&temp, states_dfa[i]);
				states_dfa[i].flag = 1;
				break;
			}
		}
		
		// Insertion of dead state into transition table

		if(!flag) {
			if(isDead) {
				for(int i = 0; i < l; i++)
					insertTransition(table_dfa, &dead, alpha[i], &dead, m1++);
			}
			break;
		}
	}

	// Finding final states of DFA
	
	for(int i = 0; i < f; i++) {
		for(int j = 0; j < n1; j++) {
			for(int k = 0; k < states_dfa[j].len; k++) {
				if(!strcmp(final_nfa[i], states_dfa[j].states[k])) {
					copyState(&final_dfa[f1++], states_dfa[j]);
					break;
				}
			}
		}
	}
	
	printf("\nStates of DFA\n");
	for(int i = 0; i < n1; i++) {
		printf("{");
		for(int j = 0; j < states_dfa[i].len; j++) {
			printf(" %s ", states_dfa[i].states[j]);
		}
		printf("}\n");
	}

	printf("\nStart state of DFA\n");
	printf("{");
	printf(" %s ", start_dfa.states[0]);
	printf("}\n");
	
	printf("\nFinal states of DFA\n");
	for(int i = 0; i < f1; i++) {
		printf("{");
		for(int j = 0; j < final_dfa[i].len; j++) {
			printf(" %s ", final_dfa[i].states[j]);
		}
		printf("}\n");
	}
	
	
	printf("\nTransition table of DFA\n");
	for(int i = 0; i < m1; i++) {
		printf("{");
		for(int j = 0; j < table_dfa[i].state1.len; j++) {
			printf(" %s ", table_dfa[i].state1.states[j]);
		}
		printf("}");

		printf(" %c ", table_dfa[i].input);		

		printf("{");
		for(int j = 0; j < table_dfa[i].state2.len; j++) {
			printf(" %s ", table_dfa[i].state2.states[j]);
		}
		printf("}\n");
	}
}