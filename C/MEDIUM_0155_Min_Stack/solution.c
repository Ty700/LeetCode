/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

    MinStack() initializes the stack object.
    void push(int val) pushes the element val onto the stack.
    void pop() removes the element on the top of the stack.
    int top() gets the top element of the stack.
    int getMin() retrieves the minimum element in the stack.

You must implement a solution with O(1) time complexity for each function.

 

Example 1:

Input
["MinStack","push","push","push","getMin","pop","top","getMin"]
[[],[-2],[0],[-3],[],[],[],[]]

Output
[null,null,null,null,-3,null,0,-2]

Explanation
MinStack minStack = new MinStack();
minStack.push(-2);
minStack.push(0);
minStack.push(-3);
minStack.getMin(); // return -3
minStack.pop();
minStack.top();    // return 0
minStack.getMin(); // return -2

 

Constraints:

    -2^31 <= val <= 2^31 - 1
    Methods pop, top and getMin operations will always be called on non-empty stacks.
    At most 3 * 104 calls will be made to push, pop, top, and getMin.

*/


typedef struct {
    int top;
    //Using a linked list is prob the better idea here to save memory
    //On average saves < 1MB
    int stack[30000][2]; //[new push val][min seen thus far]
} MinStack;

MinStack* minStackCreate() {
    MinStack* new_stack = calloc(1, sizeof(*new_stack));
    new_stack->top = -1;
    return new_stack;
}

void minStackPush(MinStack* obj, int val) {
    obj->stack[++obj->top][0] = val;
    if(obj->top == 0){
        obj->stack[obj->top][1] = val;
    } else {
        obj->stack[obj->top][1] = (obj->stack[obj->top - 1][1] > val) ? val : obj->stack[obj->top - 1][1];
    }
}

void minStackPop(MinStack* obj) {
    if(obj->top > -1){
        --obj->top;
    } else {
        return;
    }
}

int minStackTop(MinStack* obj) {
    return obj->stack[obj->top][0];
}

int minStackGetMin(MinStack* obj) {
    return obj->stack[obj->top][1];
}

void minStackFree(MinStack* obj) {
    if(obj == NULL){
        return;
    }
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);
 
 * minStackPop(obj);
 
 * int param_3 = minStackTop(obj);
 
 * int param_4 = minStackGetMin(obj);
 
 * minStackFree(obj);
*/