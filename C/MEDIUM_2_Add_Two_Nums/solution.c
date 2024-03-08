/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* CreateNode(int value){
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = value;
    newNode->next = NULL;

    return newNode;
}

void InsertNode(struct ListNode** head, int value){
    //If empty list, init list
    if(*head == NULL){
        *head = CreateNode(value);
    } else {
        //Creates a traverse node
        struct ListNode* trav = *head;
        //Finds end of list
        while(trav->next != NULL){
            trav = trav->next;
        }
        //Creates a node at end of list
        trav->next = CreateNode(value);
    }
}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {

    struct ListNode* result = NULL;
    int32_t carry = 0;
    
    while(l1 || l2 || carry){

        if(l1 == NULL && l2 != NULL){
            InsertNode(&result, (l2->val + carry) % 10);
            carry = (l2->val + carry) / 10;
            l2 = l2->next;
        } else if(l2 == NULL && l1 != NULL){
            InsertNode(&result, (l1->val + carry) % 10);
            carry = (l1->val + carry) / 10; 
            l1 = l1->next;
        } else if(l1 == NULL && l2 == NULL && carry != 0){
            InsertNode(&result, carry);
            carry = 0;
        } else {
            int sum = l1->val + l2->val + carry;
            InsertNode(&result, sum % 10);
            carry = sum / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
    }

    return result;
}
