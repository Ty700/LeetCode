/**
 * 66. Plus One
 * You are given a large integer represented as an integer array digits, where each digits[i] is the ith digit of the integer. The digits are ordered from most significant to least significant in left-to-right order. The large integer does not contain any leading 0's.
 * 
 * Increment the large integer by one and return the resulting array of digits.
 *
 * Example 1:
 * 
 * Input: digits = [1,2,3]
 * Output: [1,2,4]
 * Explanation: The array represents the integer 123.
 *      Incrementing by one gives 123 + 1 = 124.
 *      Thus, the result should be [1,2,4].
 * Example 2:
 * 
 * Input: digits = [4,3,2,1]
 * Output: [4,3,2,2]
 * Explanation: The array represents the integer 4321.
 * Incrementing by one gives 4321 + 1 = 4322.
 * Thus, the result should be [4,3,2,2].
 * 
 * Example 3:
 * 
 * Input: digits = [9]
 * Output: [1,0]
 * Explanation: The array represents the integer 9.
 * Incrementing by one gives 9 + 1 = 10.
 * Thus, the result should be [1,0].
 *  
 * Constraints:
 * 
 * 1 <= digits.length <= 100
 * 0 <= digits[i] <= 9
 * digits does not contain any leading 0's.
 * Note: The returned array must be malloced, assume caller calls free().
 */
 
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    if(digits[digitsSize - 1] != 9){
        digits[digitsSize - 1] += 1;
        *returnSize = digitsSize;
        return digits;
    }

    int i = digitsSize - 1;

    while(digits[i] == 9 && i > 0){
        digits[i] = 0;
        --i;
    }

    if(i == 0 && digits[i] == 9){
        int* res = (int *)calloc(digitsSize + 1, sizeof(int));
        res[0] = 1;
        for(int i = 1; i < digitsSize + 1; i++){
            res[i] = 0;
        }
        *returnSize = digitsSize + 1;
        return res;
    }

    digits[i] += 1;
    *returnSize = digitsSize;
    return digits;
}
