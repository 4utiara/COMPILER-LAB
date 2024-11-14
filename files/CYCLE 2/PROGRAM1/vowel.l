%{
#include <stdio.h>
%}

%%
[aAeEiIoOuU]  {  // Matches any vowel, both lowercase and uppercase
    printf("Vowel found: %s\n", yytext);
}

.|\n  { /* This rule matches any character that is not a vowel (including newlines) */
    // Do nothing
}
%%

int main() {
    printf("Enter text to check for vowels (Ctrl+D to end input):\n");
    yylex();  // Start scanning for tokens
    return 0;
}

