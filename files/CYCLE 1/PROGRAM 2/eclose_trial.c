#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node{

   int st;
   struct node* link;
   };
void findclosure(int,int);
void inserttable(int,char,int);
int findalpha(char);
void print(int);


static int noalpha,nostate,noalpha,notransition,r,s,buffer[20];
char alphabet[20],c;
struct node* transition[20][20]={NULL};
static int eclosure[20][20]={0};


void main(){
   int i,j,k,m,t,n;
   printf("\nEnter no of alphabets");
   scanf("%d",&noalpha);
   getchar();
   printf("\nEnter the alphabets");
   for(i=0;i<noalpha;i++){
      alphabet[i]=getchar();
      getchar();
      }
      
   printf("\nENter no of states :");
   scanf("%d",&nostate);
   printf("\nEnter no of transitions:");
   scanf("%d",&notransition);
   printf("\nENter transition");
   
        for(j=0;j<notransition;j++){
        scanf("%d %c %d",&r,&c,&s);
        inserttable(r,c,s);
        }
   for(i=1;i<=nostate;i++){   
         c=0;
        for(j=0;j<20;j++){
            buffer[j]=0;
            eclosure[i][j]=0;
            
            }
            findclosure(i,i);
            printf("\nEpsilon closure of q%d===",i);
            print(i);
            
            }
}

void findclosure(int x,int sta){
 
     struct node* temp;
     int i;
     if(buffer[x]){
          return;}
     eclosure[sta][c++]=x;
     buffer[x]=1;
     if(alphabet[noalpha-1]=='e' && transition[x][noalpha-1]!=NULL){
                   
                    temp=transition[x][noalpha-1];
                    while(temp!=NULL){
                        findclosure(temp->st,sta);
                        temp=temp->link;
                       }
                       
                     }
          }
void inserttable(int r,char c,int s){
         
         
       struct node* temp;
       int j;
       j=findalpha(c);
       if(j==999){
           printf("Error input alphabet");
           exit(0);}
       temp=(struct node*) malloc(sizeof(struct node));
       temp->st=s;
       temp->link= transition[r][j];
       transition[r][j]=temp;
     }
     
int findalpha(char c){

     for(int i=0;i<noalpha;i++){
            if (alphabet[i]==c){
                return i;}}
     return 999;}
     
void print(int i){
      int j;
     printf("\n {");
     for(int j=0;eclosure[i][j]!=0;j++){
     printf(" q%d",eclosure[i][j]);
     printf("}");}}
     
       
         
                       
                              
       
   
