#include<stdio.h>
#include <string.h>

void main(){
char stack[20],ip[20],opt[10][10][1],ter[10];
int top=0, row,col,i,j,k,t,n;

for(i=0;i<10;i++){
    stack[i]='\0';
    ip[i]='\0';
    for(j=0;j<10;j++){
    opt[i][j][1]='\0';} 
 }
 
 printf("\n Enter no of terminals :");
 scanf("%d",&n);
 printf("Enter the terminals;");

   scanf("%s",ter);
   printf("\n\n");
   printf("\nNter the operator precdence values");
   for(i=0;i<n;i++){
     for(j=0;j<n;j++){
          printf("\nEnter the value of %c %c",ter[i],ter[j]);
          scanf("%s",opt[i][j]);
          }}
   printf("\nOPERATOR------------PRECEDENCE TABLE______________");
   
   for(i=0;i<n;i++){
     printf("\t%c",ter[i]);
     }
   for(j=0;j<n;j++){
       printf("\n%c",ter[j]);
       printf("\t\t");
       for(i=0;i<n;i++){
             printf("\t%c",opt[j][i][0]);
             }}


stack[top]='$';
printf("\nNter the inpiut string, pls end with $:");
scanf("%s",ip);

int l=strlen(ip);

i=0;
while(i<= strlen(ip)){

    for(k=0;k<n;k++){
         if(stack[top]==ter[k]){
               col=k;
               }
         if(ip[k]==ter[k]){
         
                row=k;
                }
         }
 if((stack[top]=='$') && (ip[i]=='$')){
                printf("String accepted");
                break;}
else if ( opt[col][row][1]=='<' || opt[col][row][1]=='='){
              
              
              stack[++top]=opt[col][row][0];
              stack[++top]=ip[i];
              printf("Shift %c ",ip[i]);
              i++;}
else {

   if(opt[col][row][1]=='>'){

              
              
          while(stack[top]!='<'){
                   
              --top;}
              top--;
              printf("Reduce");}
   
   else{
     printf("\nString not accepted ");
     break;}
    } 
     
     
for(k=0;k<=top;k++){
    printf("%c",stack[k]);
    }
printf("\t\t\t");
for(k=0;k<=strlen(ip);k++){
    printf("%c",ip[k]);
    
    }
}
getchar();}
              
        
        
        
        
        
        
        
        
        
        
        












