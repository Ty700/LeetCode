/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

    Open brackets must be closed by the same type of brackets.
    Open brackets must be closed in the correct order.
    Every close bracket has a corresponding open bracket of the same type.
    
Example 1:

Input: s = "()"
Output: true

Example 2:

Input: s = "()[]{}"
Output: true

Example 3:

Input: s = "(]"
Output: false

Thoughts:

    Why tf are they importing a library for bool?????
        Embedded Sys mind hates this. Just define bool to be int, 1 => true, 0 => false
    
    If opening
        push to stack
    else
        switch to figure out ending ')' || '}' || ']'
            Once found, peek at top of stack
            
            if stack top is matching opening
                pop off stack
                keep going
      
            else return false
        

*/

bool isValid(char* s) {

    //Worst case is each character is opening, still have to account for it
    int len = strlen(s);
    char* stack = calloc(len, sizeof(*stack));
    int top = -1;

    for(int i = 0; i < len; i++){        
        if(s[i] == '(' || s[i] == '[' || s[i] == '{'){
            stack[++top] = s[i];
        } else {
            if (top == -1 || 
                (s[i] == ')' && stack[top] != '(') ||
                (s[i] == ']' && stack[top] != '[') ||
                (s[i] == '}' && stack[top] != '{'))
                {
                return false;
                }
            top--;
        }
    }
    return (top == -1);
}