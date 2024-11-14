#include<stdio.h>
#include<string.h>

void main() {
    char stack[20], ip[20], opt[10][10];  // Updated opt to 2D array of characters
    char ter[10];
    int i, j, k, n, top = 0, col, row;

    // Initialize stack and ip arrays
    for (i = 0; i < 10; i++) {
        stack[i] = '\0';
        ip[i] = '\0';
        for (j = 0; j < 10; j++) {
            opt[i][j] = '\0';  // Set all precedence values to null
        }
    }

    // Take input for terminals
    printf("Enter the no. of terminals :\n");
    scanf("%d", &n);
    printf("\nEnter the terminals :\n");
    scanf("%s", ter);

    // Take input for the precedence table values
    printf("\nEnter the table values:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("Enter the value for %c %c: ", ter[i], ter[j]);
            scanf(" %c", &opt[i][j]);  // Read precedence value as a character
        }
    }

    // Display the operator precedence table
    printf("\n**** OPERATOR PRECEDENCE TABLE ****\n");
    for (i = 0; i < n; i++) {
        printf("\t%c", ter[i]);
    }
    printf("\n");
    for (i = 0; i < n; i++) {
        printf("\n%c", ter[i]);
        for (j = 0; j < n; j++) {
            printf("\t%c", opt[i][j]);
        }
    }

    stack[top] = '$';  // Initialize stack with '$'
    printf("\nEnter the input string: ");
    scanf("%s", ip);  // Input the string to be processed

    // Display header for the action table
    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");
    printf("\n%s\t\t\t%s\t\t\t", stack, ip);

    i = 0;  // Initialize input pointer
    while (i <= strlen(ip)) {
        // Find the column and row for the precedence table
        for (k = 0; k < n; k++) {
            if (stack[top] == ter[k]) col = k;
            if (ip[i] == ter[k]) row = k;
        }

        // Check if the stack and input both have '$' (end of parsing)
        if ((stack[top] == '$') && (ip[i] == '$')) {
            printf("String is accepted\n");
            break;
        } 
        // Handle shift actions: if precedence is '<' or '='
        else if ((opt[col][row] == '<') || (opt[col][row] == '=')) {
            stack[++top] = ip[i];  // Shift character to the stack
            printf("Shift %c", ip[i]);
            i++;  // Move to next input character
        } 
        // Handle reduce actions: if precedence is '>'
        else {
            if (opt[col][row] == '>') {
                while (stack[top] != '<') {  // Pop until we encounter '<'
                    --top;
                }
                top = top - 1;  // Perform the reduction
                printf("Reduce");
            } 
            else {
                printf("\nString is not accepted");
                break;
            }
        }

        // Print the current state of the stack and input
        printf("\n");
        for (k = 0; k <= top; k++) {
            printf("%c", stack[k]);
        }
        printf("\t\t\t");
        for (k = i; k < strlen(ip); k++) {
            printf("%c", ip[k]);
        }
        printf("\t\t\t");
    }
}

