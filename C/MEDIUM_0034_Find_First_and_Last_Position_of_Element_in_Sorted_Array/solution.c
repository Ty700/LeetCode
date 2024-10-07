/*
34. Find First and Last Position of Element in Sorted Array

Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

You must write an algorithm with O(log n) runtime complexity.

Example 1:
    Input: nums = [5,7,7,8,8,10], target = 8
    Output: [3,4]

Example 2:
    Input: nums = [5,7,7,8,8,10], target = 6
    Output: [-1,-1]

Example 3:
    Input: nums = [], target = 0
    Output: [-1,-1]
 

Constraints:
    0 <= nums.length <= 10^5
    -10^9 <= nums[i] <= 10^9
    nums is a non-decreasing array.
    -10^9 <= target <= 10^9

*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void findLow(int* nums, int numsSize, int target, int* ret){
    int low = 0; 
    int high = numsSize - 1;

    while(low <= high){
        unsigned int mid = (low + high) / 2;
        if(nums[mid] == target){
            high = mid - 1;
            *ret = mid;
        } else if(nums[mid] > target){
            high = mid - 1; 
        } else {
            low = mid + 1;
        }
    }
}

void findHigh(int* nums, int numsSize, int target, int low, int* ret){
    int high = numsSize - 1;
    
    while(low <= high){
        unsigned int mid = (high + low) / 2;
        
        if(nums[mid] == target){
            low = mid + 1;
            *ret = mid;
        } else if(nums[mid] > target){
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
}

int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    int* res = calloc(2, sizeof(int));
    *returnSize = 2;
    res[0] = res[1] = -1;

    findLow(nums, numsSize, target, &res[0]);

    if(res[0] == -1){
        return res;
    }

    findHigh(nums, numsSize, target, res[0], &res[1]);

    return res;
}   
