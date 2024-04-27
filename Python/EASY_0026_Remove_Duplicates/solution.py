class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        left = 0
        for right in nums:
            if nums[left] != right:
                left += 1
                nums[left] = right
        return left + 1
