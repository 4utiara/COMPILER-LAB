
EXPERIMENT - 1
EPSILON(ε) - CLOSURE OF STATES OF NFA
AIM
To write a C program to find ε – closure of all states of any given NFA with ε transition.
ALGORITHM
1. Start.
2. Declare necessary headers.
3. Create an empty 2D array ‘states’ to store the states of the NFA.
4. Read the number of states ‘n’
.
5. Enter all the states and store them in ‘states[]’
.
6. Open the transition table file ‘input.txt’. The file contains transitions in the format: ‘state1
input_symbol state2’ (where ‘input_symbol’ can be ‘ε’).
7. For each state in ‘states[]’:
a. Set ‘i = 0’ as an index for ‘result[]’
.
b. Initialize a copy of the current state to ‘copy’
.
c. Create an empty array ‘result[]’ to store the epsilon closure for the current state.
d. Add the current state itself to its epsilon closure
e. For each transition in the file (‘state1’
,
‘input’
,
‘state2’):
i. If ‘state1’ matches the current state and the ‘input’ is ‘ε’ (epsilon
transition):
ii. iii. Add ‘state2’ to the current state's epsilon closure (‘result[]’).
Update the current state to ‘state2’ and repeat, adding all states reachable
by epsilon transitions.
f. g. Call display function to print the set of states in ‘result[]’
.
Use ‘rewind()’ to reset the file pointer to the beginning of the file so that it can be
read again for the next state.
8. Close the file.
9. Stop.