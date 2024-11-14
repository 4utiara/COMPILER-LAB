%{
#include<stdio.h>
#include<stdlib.h>

int number_1;
int number_2;
%}


number_sequence [0-9]+
%%
{number_sequence}[02468] {
     printf("Even number [%d]\n",yyleng);
     return atoi(yytext);
     }

{number_sequence}[13579] {
       printf("Odd bumner[%d]\n",yyleng);
       return atoi(yytext);
       }
%%

int yywrap(void){
    return 1;}


int main(){
     printf("Input an even number and an odd number :\n");
     number_1=yylex();
     number_2=yylex();
     
     int diff=number_1-number_2;
     if( diff%2 !=0){
          printf("Your inputs were checked for correctness .\nResult Coorect \n");}
          
     else{
          printf("Your inputs were checked for correctness. \n Result: You do not know how to rerad \n");
          
         }
     return 0;
     }

   
