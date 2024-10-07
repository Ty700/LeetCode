/*

147. Insertion Sort List

Given the head of a singly linked list, sort the list using insertion sort, and return the sorted list's head.

Example 1:

Input: head = [4,2,1,3]
Output: [1,2,3,4]
Example 2:


Input: head = [-1,5,3,4,0]
Output: [-1,0,3,4,5]
 

Constraints:

The number of nodes in the list is in the range [1, 5000].
-5000 <= Node.val <= 5000

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

/* NOTE: Really inefficent way of doing it :/ 
    Had this been a doubly-linked list it would've been easier
    However it is not, and this method was the first that came to my mind
*/

struct ListNode* insertionSortList(struct ListNode* head) {
    int* list_arr = calloc(1, sizeof(int));
    int size_of_list_arr = 0;

    /*
     Converts the list into an array 
     Since I don't know the size of the list, I have to realloc for more space every time
    */
    struct ListNode* trav = head;

    while(trav != NULL){
        list_arr[size_of_list_arr++] = trav->val;
        list_arr = realloc(list_arr, (size_of_list_arr + 1) * sizeof(int));
        trav = trav->next;    
    }

    for(int i = 1; i < size_of_list_arr; i++){
        int j = i - 1;
        while(j >= 0 && list_arr[j + 1] < list_arr[j]){
            int temp = list_arr[j + 1];
            list_arr[j + 1] = list_arr[j];
            list_arr[j] = temp;
            j--;
        }
    }

    trav = head;

    for(int i = 0; i < size_of_list_arr; i++){
        trav->val = list_arr[i];
        trav = trav->next;
    }
    return head;
}
