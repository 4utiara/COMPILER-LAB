%{
#include<stdio.h>

 int valid=1;
 void yyerror(const char* s);
 int yylex();
%}
%token identifier

%%
start:identifier;
%%

void yyerror(const char*s){
       printf("\n%s\n",s);
       valid=0;
      }

int main(){


    printf("\nEnter a name to tested for identifier :");
    yyparse();
    if(valid){
        printf("\nIt is a valid identifier!\n");
    }
    
    return 0;}

