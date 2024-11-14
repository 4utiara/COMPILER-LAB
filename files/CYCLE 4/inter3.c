#include <stdio.h>
#include <string.h>

void gen_code_for_operator(char *inp, char operator, char *reg)
{
    int i = 0, j = 0;
    char temp[100];
    while (inp[i] != '\0')
    {
        if (inp[i] == operator)
        {
            printf("%c\t%c\t%c\t%c\n", operator, *reg, inp[i - 1], inp[i + 1]);
            temp[j - 1] = *reg; // Ensure j-1 is valid and doesn't overwrite
            i += 2; // Skip to the character after the operand
            (*reg)--; // Move to the next register (decrement)
            continue;
        }
        temp[j] = inp[i]; // Copy character to temp
        i++;
        j++;
    }
    temp[j] = '\0'; // Ensure temp is null-terminated
    strcpy(inp, temp); // Copy modified temp back to inp
}

void gen_code(char *inp)
{
    char reg = 'Z'; // Start from the last register
    gen_code_for_operator(inp, '/', &reg);
    gen_code_for_operator(inp, '*', &reg);
    gen_code_for_operator(inp, '+', &reg);
    gen_code_for_operator(inp, '-', &reg);
    gen_code_for_operator(inp, '=', &reg);
}

int main()
{
    char inp[100];
    printf("Enter expression:\n\n");
    scanf("%s", inp);
    printf("Op  \tDestn\tArg1\tArg2\n");
    gen_code(inp);
    return 0;
}
/*OUTPUT
Enter expression:

p+q/s-t*e+r
Op  	Destn	Arg1	Arg2
/	Z	q	s
*	Y	t	e
+	X	p	Z
+	W	Y	r
-	V	X	W
*/
