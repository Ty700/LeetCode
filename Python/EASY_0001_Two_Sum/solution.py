# Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# You can return the answer in any order.

# Example 1:

# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

# Example 2:

# Input: nums = [3,2,4], target = 6
# Output: [1,2]

# Example 3:

# Input: nums = [3,3], target = 6
# Output: [0,1]

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        # Will store the prev target - val
        # with val being the key, and its index being value
        prev_vals = {}
                    
        for index, val in enumerate(nums):
            search_val = target - val

            # If the value we are searching for to add to current val is in map
            # Then we know that the previous val + current val = target
            # thus return the value when searching the dict using the previous val as the key
            # as it's the index
            if search_val in prev_vals.keys():
                return [prev_vals[search_val], index]

            # If the search val is not in dictionary, we know that no value we've seen previously
            # added to the current val = the target
            # so store the val and index in the map with val being the key and index being value
            else:
                prev_vals[val] = index
            
        else:
            return [] # No solution
        
