%{
#include<stdio.h>
#include<string.h>
int ignore_flag=0;
 char name[100];
void update_ignore_flag(char* input){
     
     if(strstr(input,name)!=NULL){
          ignore_flag=1;}
     else{
          ignore_flag=0;}
          }
%}

%%

.*\n {update_ignore_flag(yytext);
   if(!ignore_flag){
       printf("\nValid string:%s",yytext);}
   else{
       printf("\nInvalid string :%s",yytext);}}
%%

int main(){
  
    printf("\nNEter a name at 4 long ");
    scanf("%4s",name);
    
    printf("\nIngnore %s",name);
    yylex();
 return 0;   
}
