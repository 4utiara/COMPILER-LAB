#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void geni(char *inp,char operator,char *reg){
      int i=0,j=0;
      char temp[100];
      
      while(inp[i]!='\0'){
           if(inp[i]==operator){  printf("\n%c\t\t%c\t\t%c\t\t%c\n",operator,*reg,inp[i-1],inp[i+1]);
                temp[j-1]=*reg;
                i+=2;
                (*reg)--;
                continue;
                }
                
                
                temp[j]=inp[i];
                i++;j++;}
                
                
                temp[j]='\0';
                strcpy(inp,temp);
                

}





void gencode(char *inp){
    char reg='Z';
    geni(inp, '/', &reg);
    geni(inp, '*', &reg);
    geni(inp, '+', &reg);
    geni(inp, '-', &reg);
    geni(inp, '=', &reg);

}



int main(){
   char inp[100];
   
   printf("\nEnter the expression:");
   scanf("%s",inp);
   printf("\nOperator\t\tRegister\t\tArg1\t\tArg2\n");
   gencode(inp);
   return 0;}
