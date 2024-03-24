/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* next = NULL;

    /* Thoughts:
        Three Pointers
            - One tracking prev node
            - One tracking current node which will be head
            - One tracking next node

            - set current's next node to prev
                - this breaks a link to the next node in the list
                    so save current node's next first
            - move previous to current node
            - move current node to next node
            - repeat until current node is null
            - previous node will be first pointer of the list
    */
    while(head != NULL){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}