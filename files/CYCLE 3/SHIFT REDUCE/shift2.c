#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_INPUT 20
#define MAX_STACK 20

void check();
char stack[MAX_STACK],input[MAX_INPUT],action[20];
int len,top=-1;

int main(){
 printf("\nThe GRAMMAR is E => E+E|E*E|(E)|id");
   printf("\nEnter the input string :");
   scanf("%s",input);
   len=strlen(input);
   int i;
   printf("\nStack\t\tInput\t\tAction\t\n\n");
   for(i=0;i<len;i++){
       if(input[i]=='i' && input[i+1]=='d'){
            stack[++top]='i';
            stack[++top]='d';
            stack[top+1]='\0';
            printf("$%s\t\t%s\t\tShift->id\n",stack,input+i+2);
            check();
            i++;
            }
        else {
              stack[++top]=input[i];
              stack[top+1]='\0';
              printf("$%s\t\t%s\t\tShift->%c\n",stack,input+i+1,input[i]);
              check();}}
              
      if(top==0 && stack[top]=='E')
      {
        printf("\nThe input string is valid ");}
      else {
              printf("\nInput string is not valid ");}
       
       
       
       return 0;}
void check(){
   int i,j,handle_size;
   char* handle;
   while(1){
        if(top>=1 && stack[top-1]=='i' && stack[top]=='d'){
              handle="id";
              handle_size=2;
              }
        else if(top>=2 && stack[top-2]=='E' && stack[top-1]=='+' && stack[top]=='E'){
              handle="E+E";
              handle_size=3;
              }         
              
       else if(top>=2 && stack[top-2]=='E' && stack[top-1]=='*' && stack[top]=='E'){
              handle="E*E";
              handle_size=3;
              }         
               else if(top>=2 && stack[top-2]=='(' && stack[top-1]=='E' && stack[top]==')'){
              handle="(E)";
              handle_size=3;
              }         
               else {return;}
               
               
               
               
              top=top-(handle_size-1);
              stack[top]='E';
              stack[top+1]='\0';
              printf("$%s\t\t%s$\t\tREDUCE->%s\n",stack,input+strlen(input),handle);
              }}
