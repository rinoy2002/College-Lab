#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool isFunction = false;
bool isComment = false;
int line=1;
bool isDelimiter(char ch) {
	if (ch == ' ' || ch == '\t' || ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '!' || ch == '|' || ch == '&' || ch == ',' || ch == ';' || ch == '>' || ch == '<' || ch == '=' || ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == '\'' || ch == '\"'){
         return true;
    }
	return false;
}

bool isOperator(char ch) {
	if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '>' || ch == '<' || ch == '=' || ch == '|' || ch == '&' || ch == '!'){
        return true;
    }
	return false;
}

bool separatorCheck(char* str) {
	if(!strcmp(str, "(") || !strcmp(str, ")") || !strcmp(str, "{") || !strcmp(str, "}") || !strcmp(str, ",") || !strcmp(str, ";")){
        return true;
    }
	return false;
}

bool operatorCheck(char* str){
	if(!strcmp(str,"%") || !strcmp(str, "+") || !strcmp(str, "-") || !strcmp(str, "*") || !strcmp(str, "/") || !strcmp(str, "=") || !strcmp(str, "<") || !strcmp(str, ">") || !strcmp(str, "<=") || !strcmp(str, ">=") || !strcmp(str, "==") || !strcmp(str, "!=") || !strcmp(str, "!") || !strcmp(str, "||") || !strcmp(str, "&&") || !strcmp(str, "|") || !strcmp(str, "&") || !strcmp(str, "++") || !strcmp(str, "--") || !strcmp(str, "+=") || !strcmp(str, "-=") || !strcmp(str, "*=") || !strcmp(str, "/=") || !strcmp(str, "|=") || !strcmp(str, "&=") || !strcmp(str, "[") || !strcmp(str, "]")){
		return true;
    }
	return false;
	
}

bool keywordCheck(char* str) {
if (!strcmp(str, "auto") || !strcmp(str, "break") || !strcmp(str, "case") || !strcmp(str, "char") || !strcmp(str, "const") || !strcmp(str, "continue") || !strcmp(str, "default") || !strcmp(str, "do") || !strcmp(str, "double") || !strcmp(str, "else") || !strcmp(str,    "enum") || !strcmp(str, "extern") || !strcmp(str, "float") || !strcmp(str, "for") || !strcmp(str, "goto") || !strcmp(str, "if") || !strcmp(str, "int") || !strcmp(str, "long") || !strcmp(str, "register") || !strcmp(str, "return") || !strcmp(str, "short") || !strcmp(str, "signed") || !strcmp(str, "sizeof") || !strcmp(str, "static") || !strcmp(str, "struct") || !strcmp(str, "switch") || !strcmp(str, "typedef") || !strcmp(str, "union") || !strcmp(str, "unsigned") || !strcmp(str, "void") || !strcmp(str, "volatile") || !strcmp(str, "while")){	
		return true;
	}
	return false;
}

bool integerCheck(char* str) {
	int i, len = strlen(str);
	if(len == 0){
		return false;
	}
	for(i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' || (str[i] == '-' && i > 0)){
			return false;
	    }
    }
	return true;
}

bool realNumberCheck(char* str) {
	int i, len = strlen(str);
	bool hasDecimal = false;

	if(len == 0){
		return false;
	}
	for(i = 0; i < len; i++) {
		if (str[i] != '0' && str[i] != '1' && str[i] != '2' && str[i] != '3' && str[i] != '4' && str[i] != '5' && str[i] != '6' && str[i] != '7' && str[i] != '8' && str[i] != '9' && str[i] != '.' || (str[i] == '-' && i > 0)){
		    return false;
	    }
		if (str[i] == '.'){
			hasDecimal = true;
		}
	}
	return hasDecimal;
}

bool charCheck(char* str) {
	if(str[0] == '\'' && str[strlen(str) - 1] == '\'') {
		return true;
	}
	return false;
}

bool strCheck(char* str) {
	if(str[0] == '\"' && str[strlen(str) - 1] == '\"') {
		return true;
	}
	return false;
}

bool identifierCheck(char* str) { 
	if(str[0] == '0' || str[0] == '1' || str[0] == '2' || str[0] == '3' || str[0] == '4' || str[0] == '5' || str[0] == '6' || str[0] == '7' || str[0] == '8' || str[0] == '9' || isDelimiter(str[0]) == true){
		return false;
    }    
    return true;
}

char* substr(char* str, int start, int end) {
	char* sub = malloc(sizeof(char) * (end - start + 2));
	int i;
	for(i = 0; i < (end - start + 1); i++) {
		sub[i] = str[start + i];
	}
	sub[i] = '\0';
	return sub;
}

bool preprocessorCheck(char str[]) {
	int i = 0;
	while(str[i] == ' ') i++;
	if(str[i] == '#'){
		printf("Line %d : ",line);
		printf("< %s , PREPROCESSOR DIRECTIVE >\n", str);
		return true;
	}
	return false;
}

void parse(char str[]) {
	if(preprocessorCheck(str) || !strcmp(str, "\n")) return;
	int start = 0, end = 0, len = strlen(str);
	char* lexeme;
	while (start <= end && end < len) {
        //Character
		if(str[start] == '\'') {
			end++;
			while(str[end] != '\''){
                end++;
            }
			end++;
		}
        //String
        else if(str[start] == '\"') {
			end++;
			while(str[end] != '\"'){
                end++;
            }
			end++;
		}
        //Single line Comment
        else if(str[start] == '/' && str[start + 1] == '/') {
			printf("Line %d : ",line);
			printf("< %s , SINGLE LINE COMMENT >\n", substr(str, start, strlen(str) - 1));
			end++;
			start = end;
			return;
		}
        //Multiline comment
        else if(str[start] == '/' && str[start + 1] == '*') {
			isComment = true;
			end += 2;
			while((end + 1) < len) {
				if(str[end] == '*' && str[end + 1] == '/') {
					end++;
					printf("Line %d : ",line);
					printf("< %s , MULTILINE COMMENT > \n", substr(str, start, end));
					isComment = false;
					break;
				}
				else{
					end++;
                }
			}

			if(isComment) { 
				printf("Line %d : ",line);
                printf("< %s , MULTILINE COMMENT >\n", substr(str, start, len - 1)); 
                return; 
            }
			end++;
			start = end;
		 } 
         else if(str[start] == '*' && str[start + 1] == '/') {
			isComment = false;
			printf("Line %d : ",line);
			printf("< %s , MULTILINE COMMENT >\n", substr(str, 0, start + 1));
			start += 2;
			end = start;
		}

		if(!isDelimiter(str[end])) {
			end++;
			if(end == len)
				goto L1;
		} else {
		L1:
			if(start == end) {
				if(isOperator(str[end]) && end + 1 < len && isOperator(str[end + 1])) {
					end++;
				}
			} else {
				end--;
			}		
			
			lexeme = substr(str, start, end);
			
			if(isComment) {
				
			} else if(operatorCheck(lexeme)) {
				printf("Line %d : ",line);
				printf("< %s , OPERATOR >\n", lexeme);
			} else if(separatorCheck(lexeme)) {
				printf("Line %d : ",line);
				printf("< %s , DELIMETER >\n", lexeme);
			} else if(keywordCheck(lexeme)) {
				printf("Line %d : ",line);
				printf("< %s , KEYWORD >\n", lexeme);
			} else if(integerCheck(lexeme)) {
				printf("Line %d : ",line);
				printf("< %s , INTEGER LITERAL >\n", lexeme);
			} else if(realNumberCheck(lexeme)) {
				printf("Line %d : ",line);
				printf("< %s , FLOAT LITERAL >\n", lexeme);
			} else if(charCheck(lexeme)) {
				printf("Line %d : ",line);
				printf("< %s , CHARACTER LITERAL >\n", lexeme);
			} else if(strCheck(lexeme)) {
				printf("Line %d : ",line);
				printf("< %s , STRING LITERAL >\n", lexeme);
			} else if(identifierCheck(lexeme)) {
				printf("Line %d : ",line);
				printf("< %s , IDENTIFIER >\n", lexeme);
			} else if(strcmp(lexeme, " ") && strcmp(lexeme, "\t") && strcmp(lexeme, "\n")) {
				printf("Line %d : ",line);
				printf("< %s , INVALID TOKEN >\n", lexeme);
			}
			
			end++;
			start = end;
		}
	}
		
	if(isComment) {
		printf("Line %d : ",line);
		printf("%s is a multiline comment\n", str);
	}
}

void main() {
	char filename[20];
	printf("Enter Input Filename: ");
	scanf("%s", filename);
	
	FILE *fp = fopen(filename, "r");
	
	char str[1000];
	
	while(fgets(str, 1000, fp)) {
		str[strlen(str) - 1] = '\0';
		parse(str);
        line++;
	}
}