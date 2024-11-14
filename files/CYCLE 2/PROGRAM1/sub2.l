%{
#include<stdio.h>
#include<stdlib.h>

char name[5];

int ignore_flag=0;

void updateflag(char* input){
     if(strstr(input,name)!=NULL){
          ignore_flag=1;}
     else{
     
        ignore_flag=0;}
        }
%} /* Avoid space before %} generates premature EOF error*/
 
%% 
.*\n {
 
    updateflag(yytext);
    if(!ignore_flag){
        printf("Valid String %s",yytext);}
     else{
        printf("Invalid string %s",yytext);}
        }
   
%%
int main(){
    printf("Enter a name that contains at least 4 characters:");
    scanf("%4s",name);
    printf("Ingnoring the string that contains %s",name);
    yylex();
    return 0;
}
