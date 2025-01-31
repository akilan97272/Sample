#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAX_TOKEN_SIZE 100


const char* keywords[] = {
    "int", "return", "if", "else", "while", "for", "void", "char", "float"
};


bool isKeyword(const char* word) {
    int i; 
    for (i = 0; i < sizeof(keywords) / sizeof(keywords[0]); i++) {
        if (strcmp(word, keywords[i]) == 0) {
            return true;
        }
    }
    return false;
}


void printToken(const char* token) {
	
    if (isKeyword(token)) {
        printf("\nKeyword: %s\n", token);
    } else if (isdigit(token[0])) {
        printf("\nNumber: %s\n", token);
    } else {
        printf("ID: %s\n", token);
    }
}

int main() {
    FILE *file; 
    char ch;
    char currentToken[MAX_TOKEN_SIZE];
    int tokenIndex = 0;
    int lines = 0, words = 0, characters = 0;
    bool inWord = false;


	file = fopen("example.txt", "r"); 
	    if (file == NULL) {
        perror("Error opening file");
        return 1; 
    }

    printf("Reading from file input.txt...\n");

    while ((ch = fgetc(file)) != EOF) {
        characters++;
        if (ch == '\n') {
            lines++;
        }

 
        if (ch == ' ' || ch == '\n' || ch == '\t') {
            if (inWord) {
                currentToken[tokenIndex] = '\0';  
                if (tokenIndex > 0) {
                    words++;
                    printToken(currentToken);
                }
                tokenIndex = 0;  
                inWord = false;
            }
        } 
        
        else if (isalpha(ch) || isdigit(ch) || ch == '_') {
            currentToken[tokenIndex++] = ch;
            inWord = true;
        } 
        
        else {
            if (tokenIndex > 0) {
                currentToken[tokenIndex] = '\0';
                words++;
                printToken(currentToken);
                tokenIndex = 0;
            }
            printf("\n");
            printf("Operator: %c\n", ch);
        }
    }

   
    if (inWord) {
        currentToken[tokenIndex] = '\0';
        words++;
        printToken(currentToken);
    }

   
    printf("\nLines of Code: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);
    fclose(file);
    return 0;
}

