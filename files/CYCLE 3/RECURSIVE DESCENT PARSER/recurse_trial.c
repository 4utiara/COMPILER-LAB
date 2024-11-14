#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char input[10];
int error=0,i,j,k;


void E();
void EPrime();
void T();
void TPrime();
void F();


void main(){

    printf("\nEnter the expression");
    fgets(input,sizeof(input),stdin);
    input[strcspn(input,"\n")]='\0';
    E();
    if(strlen(input)==i && error==0){
         printf("\nValid ");
         }
    else{
          printf("\nInvalid");}
          
    }
void E(){
    T();
    EPrime();
    }
void EPrime(){
      if(input[i]=='+'|| input[i]=='-'){
          i++;
          T();
          EPrime();}}
void T(){
    F();
    TPrime();}
void TPrime(){
     if(input[i]=='*' || input[i]=='/'){
         i++;
         F();
         TPrime();
         }
         }
void F(){
    if(isalnum(input[i])){
     i++;}
    else if (input[i]=='('){
       i++;
       E();
       if(input[i]==')')
           i++;
       else
          error=1;}
    else 
        {
        error=1;
        }
}        
              
    
    
