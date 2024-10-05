/*
217. Contains Duplicate

Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

Example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

Constraints:

    1 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9

*/

#define HASH_LEN 100007

struct HashNode{
    int val;
    struct HashNode* next;
};

struct HashNode* createNode(int val){
    struct HashNode* new_node = calloc(1, sizeof(struct HashNode));

    new_node->val = val;
    new_node->next = NULL;

    return new_node;
}

int hashIndex(int value){
    return (abs(value) % HASH_LEN);
}

void insertNode(struct HashNode* tbl[], int val){
    int val_hash_index = hashIndex(val);
    
    struct HashNode* trav = tbl[val_hash_index];

    struct HashNode* new_node = createNode(val);

    if(trav == NULL){
        tbl[val_hash_index] = new_node;
        return;
    }

    while(trav->next != NULL){
        trav = trav->next;
    }

    trav->next = new_node;
}

int findNode(struct HashNode* tbl[], int val){
    int val_hash_index = hashIndex(val);
    struct HashNode* head = tbl[val_hash_index];

    while(head != NULL){
        if (head->val == val){
            return 1;
        }
        head = head->next;
    }
    return 0;
}

bool containsDuplicate(int* nums, int numsSize) {
    struct HashNode** tbl = calloc(HASH_LEN, sizeof(struct HashNode*));

    for(int i = 0; i < numsSize; i++){
        if(findNode(tbl, nums[i])){
            return true;
        } else {
            insertNode(tbl, nums[i]);
        }
    }
    return false;
}
