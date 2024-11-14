#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char line[100];

int is_operator(char c){
    switch (c){
        case '+':
        case  '-':
        case '*':
        case '/':
        case '=':
           printf("\nOperator %c:",c);
           return 1;}
    return 0;}
    
int is_delimiter(char c){
     switch(c){
        case'{':
        case'}':
        case'(':
        case')':
        case';':
        case',':
        case'[':
        case']':
        
           printf("\nDelimiter %c\n",c);
           return 1;}
        return 0;}

int is_keyword(char buffer[]){

     char keyword[32][10]={
                     "int","float","char","double","void",
                      "if","else","switch","case","for","while","do","goto",
                      "signed","unsigned","short","long","typedef","register","static","const","volatile",
                      "auto","extern",
                      "return",
                      "struct","union","sizeof",
                      "break","continue","default",
                      "enum"};
                      
       for(int i=0;i<32;i++){
               if(strcmp(keyword[i],buffer)==0){
                       return 1;}}
        return 0;}
        
void main(){
    
     FILE *f=fopen("input.txt","r");
     while(fgets(line,sizeof(line),f)){
            
           int flag1=0;
           for(int i=0;i<strlen(line);i++){
               if(line[i]=='\' && line[i+1]=='\'){
                    flag1=1;
                    break;}
              }
             if(flag1){
                continue;}
                 
            
            int flag2=0;
            for(int i=0;i<strlen(line);i++){
                if(line[i]=='\' && line[i+1]=='*'){
                
                
                     while(fgets(line,sizeof(line),f)){
                        if(line[j]=='*' && line[j+1]=='/'){
                              flag2=1;}
                              
              if(flag2){
                  break;}
                  
    
         }}}
         if(flag2)
             continue;
         printf("\n%s\n",line);
         char token[100];
         
          int index=0;
          strcpy(token,"");
          
          for(int i=0;i<strlen(line);i++){
              // Case 1
              if(is_operator(line[i])|| is_delimiter(line[i])|| line[i]=='\t' || line[i]=='\n' || line[i]==' '){
              
              if(strcmp(token,"")!=0){
                  if(is_keyword(line[i]){
                      printf("\n%s- Keyword",token);
                      }
                  else{
                      printf("%s -Identifier",token);
                      }
                     strcpy(token," ");
                     index=0;
                     }}
                else{
                    token[index++]=line[i];
                    token[index]='\0';
                    }
               }
    
    }
 fclose(f);}
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
          
