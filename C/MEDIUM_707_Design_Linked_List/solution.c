/*

Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

Implement the MyLinkedList class:

MyLinkedList() Initializes the MyLinkedList object.
int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
void addAtTail(int val) Append a node of value val as the last element of the linked list.
void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

Example 1:

Input
["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
[[], [1], [3], [1, 2], [1], [1], [1]]
Output
[null, null, null, null, 2, null, 3]

Explanation
MyLinkedList myLinkedList = new MyLinkedList();
myLinkedList.addAtHead(1);
myLinkedList.addAtTail(3);
myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
myLinkedList.get(1);              // return 2
myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
myLinkedList.get(1);              // return 3
 

Constraints:

0 <= index, val <= 1000
Please do not use the built-in LinkedList library.
At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

*/


typedef struct MyLinkedList{
    int val;
    struct MyLinkedList* next;
    struct MyLinkedList* prev;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* new_node = calloc(1, sizeof(*new_node));
    return new_node;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    MyLinkedList* current = obj->next;
    int i = 0;
    while(current != NULL && i < index){
        current = current->next;
        i++;
    }

    if(current == NULL){
        return -1;
    }

    return current->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    MyLinkedList* new_head = myLinkedListCreate();
    new_head->val = val;

    new_head->next = obj->next; //new_head next = first real node
    new_head->prev = obj; //new_head prev points to head

    //If there is a real node, set it's prev to new_head
    if(obj->next != NULL){
        obj->next->prev = new_head;
    }
    //Sets new_head to be first real node
    obj->next = new_head;
    
    return;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    MyLinkedList* tail = obj;

    //Go to end of list O(N)
    while(tail->next != NULL){
        tail = tail->next;
    }

    //Create new node to append to the list
    MyLinkedList* new_tail = myLinkedListCreate();
    new_tail->val = val;

    //Set old tail's next to the new tail
    tail->next = new_tail;

    new_tail->prev = tail;
    new_tail->next = NULL;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {

    MyLinkedList* current = obj;

    //Move to one before index
    for(int i = 0; current != NULL && i < index; i++){
        current = current->next;
    }
    
    //Invalid index
    if(current == NULL){
        return;
    }

    //Create new node to add
    MyLinkedList* new_node = myLinkedListCreate();
    new_node->val = val;

    //Set new node's next to current next
    new_node->next = current->next;
    //Set new node's prev to current
    new_node->prev = current;
    //Node is now inbetween next and current

    //If there is a current next, set it's prev to new_node
    if(current->next != NULL){
        current->next->prev = new_node;
    } 
    
    //Set current's new next to be new node
    current->next = new_node;
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    MyLinkedList* current = obj->next;

    //Move to index
    for(int i = 0; current != NULL && i < index; i++){
        current = current->next;
    }

    //Invalid index
    if(current == NULL){
        return;
    }

    //If node is not head
    if(current->prev != NULL){
        current->prev->next = current->next;
    }

    //If node is not tail
    if(current->next != NULL){
        current->next->prev = current->prev;
    }
    free(current);
}

void myLinkedListFree(MyLinkedList* obj) {
    MyLinkedList* current = obj;

    while(current != NULL){
        MyLinkedList* next = current->next;
        free(current);
        current = next;
    }
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/
