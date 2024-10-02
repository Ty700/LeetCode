/*
* 
* Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
* 
* You may assume that each input would have exactly one solution, and you may not use the same element twice.
* 
* You can return the answer in any order.
* 
*  
* 
* Example 1:
* 
* Input: nums = [2,7,11,15], target = 9
* Output: [0,1]
* Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
* 
* Example 2:
* 
* Input: nums = [3,2,4], target = 6
* Output: [1,2]
* 
* Example 3:
* 
* Input: nums = [3,3], target = 6
* Output: [0,1]
* 
*  
* 
* Constraints:
*
*    2 <= nums.length <= 104
*    -109 <= nums[i] <= 109
*    -109 <= target <= 109
*    Only one valid answer exists.
* 
* Note: The returned array must be malloced, assume caller calls free().
*/

int find_comp(int* comps, int comp_to_find, int comps_size){

    for(int i = 0; i < comps_size; i++){
        if (comps[i] == comp_to_find){
            return i;
        }

        if(comps[i] == INT_MAX){
            break;
        }
    }

    printf("\n");
    return -1;
}

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    int* comps = malloc(numsSize * sizeof(int));
    int* res = malloc(2 * sizeof(int));

    if(!res){
        printf("Error allocating memory for res!\n");
    }

    res[0] = INT_MAX;
    res[1] = INT_MAX;

    for(int i = 0; i < numsSize; i++){
        comps[i] = INT_MAX;
    }

    for(int i = 0; i < numsSize; i++){
        int comp_to_find = target - nums[i];
        int comp_index = find_comp(comps, comp_to_find, numsSize);

        /* Comp has not been seen yet */
        if (comp_index == -1){
            comps[i] = nums[i];
        } else {
        /* Comp has been found */
            res[0] = i;
            res[1] = comp_index;
            break;
        }
    }


    free(comps);
    *returnSize = 2;
    return res;
}