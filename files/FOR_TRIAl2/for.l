%{
#include "y.tab.h"  // Include Yacc-generated token definitions
%}

%%
"for"           return FOR;          // Match the 'for' keyword
[0-9]+          { yylval = atoi(yytext); return NUM; }  // Match numbers and convert to integer
[a-zA-Z][a-zA-Z0-9]*  { yylval = strdup(yytext); return ID; }  // Match identifiers
"<="            return LE;           // Match the <= operator
">="            return GE;           // Match the >= operator
"=="            return EQ;           // Match the == operator
"!="            return NE;           // Match the != operator
"||"            return OR;           // Match the logical OR operator
"&&"            return AND;          // Match the logical AND operator
[ \t\n]         ;                    // Ignore whitespace characters
.               return yytext[0];    // Return any other character as its ASCII value
%%

int yywrap() {
    return 1;
}

