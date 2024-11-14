%{
#include <stdio.h>
#include <stdlib.h>

int number_1;
int number_2;
%}

number_sequence [0-9]+

%%

{number_sequence}[02468] {
    printf("Even number [%d]\n", yyleng);
    return atoi(yytext);
}

{number_sequence}[13579] {
    printf("Odd number [%d]\n", yyleng);
    return atoi(yytext);
}

%%

int yywrap(void) {
    return 1;
}

int main() {
    printf("Input an even number and an odd number:\n");
    number_1 = yylex();
    number_2 = yylex();

    // Difference should be odd for correct input
    int diff = number_1 - number_2;
    if (diff % 2 != 0) {
        printf("Your inputs were checked for correctness.\nResult: Correct\n");
    } else {
        printf("Your inputs were checked for correctness.\nResult: You do not know how to read.\n");
    }
    return 0;
}

