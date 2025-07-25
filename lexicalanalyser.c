#include <stdio.h>
#include <ctype.h>
#include <string.h>

char keywords[][10] = {"int", "float", "if", "else", "while", "for", "return","auto", "break" ,"case", "const",
     "continue", "default", "do", "double", "enum", "extern", "goto", "long", "register", "short", "signed", 
     "sizeof", "static", "struct", "switch", "typedef", "union", "unsigned", "void", "volatile", "char"  };
char operators[] = "+-*/=%";

//function to identify keyword
int isKeyword(char *word) {
    for (int i = 0; i < 32; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

//function to identify operator
int isOperator(char ch) {
    for (int i = 0; i < strlen(operators); i++) {
        if (ch == operators[i])
            return 1;
    }
    return 0;
}

int main() {
    FILE *fp;
    char ch, buffer[100];
    int i = 0;

    fp = fopen("cprog.c", "r");

    if (fp == NULL) {
        printf("Error: Cannot open file.\n");
        return 1;
    }

    while ((ch = fgetc(fp)) != EOF) {
        if (isalnum(ch) || ch == '_') {
            buffer[i++] = ch;
        } else {
            buffer[i] = '\0'; // End of token

            if (i > 0) {
                if (isKeyword(buffer))
                    printf("[Keyword]    %s\n", buffer);
                else if (isdigit(buffer[0]))
                    printf("[Number]     %s\n", buffer);
                else
                    printf("[Identifier] %s\n", buffer);
                i = 0;
            }
            else if (isspace(ch) || ch == ';' || ch == ',' || ch == '(' || ch == ')') {
            buffer[i] = '\0';
            i = 0;

            
            }
        }
    }

    fclose(fp);
    return 0;
}