/*

You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

Example 1:
Input: list1 = [1,2,4], list2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:

Input: list1 = [], list2 = []
Output: []
Example 3:

Input: list1 = [], list2 = [0]
Output: [0]
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    if(list1 == NULL && list2 != NULL){
        return list2;
    }

    if(list1 != NULL && list2 == NULL){
        return list1;
    }
    
    if(list1 == NULL && list2 == NULL){
        return NULL;
    }

    struct ListNode* head = calloc(1, sizeof(*head));

    struct ListNode* current = head;

    while(list1 != NULL || list2 != NULL){
        struct ListNode* new_node = calloc(1, sizeof(*head));

        if(list1 == NULL){
            current->val = list2->val;
            list2 = list2->next;
        } else if (list2 == NULL){
            current->val = list1->val;
            list1 = list1->next;
        } else if(list1->val < list2->val){
            current->val = list1->val;
            list1 = list1->next;
        } else {
            current->val = list2->val;
            list2 = list2->next;
        }

        if(list1 == NULL && list2 == NULL){
            current->next = NULL;
        } else {
            current->next = new_node;
            current = current->next;
        }

    }

    return head;
}
