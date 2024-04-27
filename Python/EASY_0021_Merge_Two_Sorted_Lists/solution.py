# You are given the heads of two sorted linked lists list1 and list2.

#      Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

#       Return the head of the merged linked list.

         

#       Example 1:

#       Input: list1 = [1,2,4], list2 = [1,3,4]
#       Output: [1,1,2,3,4,4]

#       Example 2:

#       Input: list1 = [], list2 = []
#       Output: []

#       Example 3:

#       Input: list1 = [], list2 = [0]
#       Output: [0]

# Definition for singly-linked list.
# class ListNode(object):
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution(object):
    def mergeTwoLists(self, list1, list2):
        """
        :type list1: Optional[ListNode]
        :type list2: Optional[ListNode]
        :rtype: Optional[ListNode]
        """
        head = None
        curr = None

        while(list1 != None or list2 != None):
            # Init head or create a new node
            if(head == None):
                new_node = ListNode()
                curr = new_node
                head = curr
            else:
                new_node = ListNode()
                curr.next = new_node
                curr = new_node

            # Merge logic
            if(list1 == None):
                curr.val = list2.val
                list2 = list2.next
                continue
            
            if(list2 == None):
                curr.val = list1.val
                list1 = list1.next
                continue

            if(list1.val <= list2.val):
                curr.val = list1.val
                list1 = list1.next
            else:
                curr.val = list2.val
                list2 = list2.next
        else:
            return head
