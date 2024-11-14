#include <stdio.h>
#include <string.h>

void main() {
    char stack[20], ip[20], opt[10][10], ter[10];
    int i, j, k, n, top = 0, col, row;

    // Initialize stack and input strings
    for(i = 0; i < 20; i++) {
        stack[i] = '\0';
        ip[i] = '\0';
    }

    printf("Enter the no. of terminals:\n");
    scanf("%d", &n);
    
    printf("\nEnter the terminals:\n");
    scanf("%s", ter);
    
    printf("\nEnter the table values:\n");
   // Input for the precedence table values
printf("\nEnter the table values:\n");
for(i=0;i<n;i++) {
    for(j=0;j<n;j++) {
        printf("Enter the value for %c %c: ", ter[i], ter[j]);
        scanf(" %c", &opt[i][j][0]);  // Modified line with space before %c
        // Check if the input is empty
        if (opt[i][j][0] == '\0') {
            printf("No precedence defined for %c %c\n", ter[i], ter[j]);
        }
    }
}


    // Display the operator precedence table
    printf("\n**** OPERATOR PRECEDENCE TABLE ****\n");
    printf("\t");
    for(i = 0; i < n; i++) {
        printf("%c\t", ter[i]);
    }
    printf("\n");

    for(i = 0; i < n; i++) {
        printf("%c\t", ter[i]);
        for(j = 0; j < n; j++) {
            printf("%c\t", opt[i][j]);
        }
        printf("\n");
    }

    // Initialize stack and input string
    stack[top] = '$';
    printf("\nEnter the input string:\n");
    scanf("%s", ip);
    
    i = 0;  // Input string index
    printf("\nSTACK\t\t\tINPUT STRING\t\t\tACTION\n");

    printf("%s\t\t\t%s\t\t\t", stack, ip);

    // Parse the input string using the operator precedence table
    while(i <= strlen(ip)) {
        for(k = 0; k < n; k++) {
            if(stack[top] == ter[k]) col = k;
            if(ip[i] == ter[k]) row = k;
        }

        if((stack[top] == '$') && (ip[i] == '$')) {
            printf("String is accepted\n");
            break;
        } else if ((opt[col][row] == '<') || (opt[col][row] == '=')) {
            // Shift operation
            stack[++top] = ip[i++];
            stack[top + 1] = '\0';  // Null terminate the stack string
            printf("Shift %c", ip[i-1]);
        } else if (opt[col][row] == '>') {
            // Reduce operation
            while(stack[top] != '<') {
                --top;
            }
            top = top - 1;  // Perform the reduction
            printf("Reduce");
        } else {
            printf("\nString is not accepted\n");
            break;
        }

        // Display the stack and input
        printf("\n");
        for(k = 0; k <= top; k++) {
            printf("%c", stack[k]);
        }
        printf("\t\t\t");

        for(k = i; k < strlen(ip); k++) {
            printf("%c", ip[k]);
        }
        printf("\t\t\t");
    }
}

