# You are given two non-empty linked lists representing two non-negative integers. 
# The digits are stored in reverse order, and each of their nodes contains a single digit.
# Add the two numbers and return the sum as a linked list.

# You may assume the two numbers do not contain any leading zero, except the number 0 itself.

# Example 1:

# Input: l1 = [2,4,3], l2 = [5,6,4]
# Output: [7,0,8]
# Explanation: 342 + 465 = 807.

# Example 2:

# Input: l1 = [0], l2 = [0]
# Output: [0]

# Example 3:

# Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
# Output: [8,9,9,9,0,0,0,1]


# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def addTwoNumbers(self, l1, l2):
        """
        :type l1: ListNode
        :type l2: ListNode
        :rtype: ListNode
        """
        
        carry = 0
        ret_head = ListNode()  
        curr_node = ret_head   

        while l1 is not None or l2 is not None or carry != 0:
            curr_val = carry
            if(l1 is not None):
                curr_val += l1.val
                l1 = l1.next
            if(l2 is not None):
                curr_val += l2.val
                l2 = l2.next
            
            carry = curr_val // 10
            curr_val %= 10

            curr_node.val = curr_val

            if(l1 is not None or l2 is not None or carry != 0):
                new_node = ListNode()
                curr_node.next = new_node
                curr_node = curr_node.next
        
        else:
            return ret_head


