int removeDuplicates(int* nums, int numsSize) {
    int left = 0, right = 0;

    while(right < numsSize){
        /* Search for the first non-dup */
        if (nums[left] == nums[right]){
            right += 1;
            continue;
        }

        /* Non-dupe has been found */
        nums[left + 1] = nums[right];
        left += 1;
    }

    return left + 1;
}
