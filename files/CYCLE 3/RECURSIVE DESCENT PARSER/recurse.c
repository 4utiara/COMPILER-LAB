#include <stdio.h>
#include <string.h>
#include <ctype.h>

char input[10];
int i, error;

void E();
void T();
void Eprime();
void Tprime();
void F();

void main() {
  i = 0;
  error = 0;
  printf("\nE  → T E'"); 
  printf("\n E' → '+' T E' | '-' T E' | ε");
  printf("\nT  → F T'");
  printf("\nT' → '*' F T' | '/' F T' | ε");
  printf("\nF  → id | num | '(' E ')'");
  printf("\n----------------------------\n");
  printf("Enter an arithmetic expression: ");
  fgets(input,sizeof(input),stdin);
  input[strcspn(input, "\n")] = '\0';  // Replace newline with null terminator

  E();
  if (strlen(input) == i && error == 0)
    printf("\nAccepted..!!!\n");
  else 
    printf("\nRejected..!!!\n");
}

void E() {
  T();       // Process a term
  Eprime();  // Check for + or - operators
}

void Eprime() {
  if (input[i] == '+' || input[i] == '-') {  // Accept + or -
    i++;
    T();
    Eprime();
  }
}

void T() {
  F();       // Process a factor
  Tprime();  // Check for * or / operators
}

void Tprime() {
  if (input[i] == '*' || input[i] == '/') {  // Accept * or /
    i++;
    F();
    Tprime();
  }
}

void F() {
  if (isalnum(input[i])) {  // Recognize a number or variable (id)
    i++;
  } else if (input[i] == '(') {  // Recognize parentheses
    i++;
    E();
    if (input[i] == ')')
      i++;
    else
      error = 1;  // Missing closing parenthesis
  } else {
    error = 1;  // Invalid character
  }
}
