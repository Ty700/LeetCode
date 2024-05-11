# 387. First Unique Character in a String

# Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

# Example 1:

# Input: s = "leetcode"
# Output: 0

# Example 2:

# Input: s = "loveleetcode"
# Output: 2

# Example 3:

# Input: s = "aabb"
# Output: -1

class Solution(object):
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        char_map = {}

        for char in s:
            if char not in char_map.keys():
                char_map[char] = 1
            else:
                char_map[char] += 1
        
        for index in range(len(s)):
            if char_map[s[index]] == 1:
                return index

        return -1
