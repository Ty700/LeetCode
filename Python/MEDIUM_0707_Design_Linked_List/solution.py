# 707. Design Linked List

# Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
# A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
# If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

# Implement the MyLinkedList class:

#     MyLinkedList() Initializes the MyLinkedList object.
#     int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
#     void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
#     void addAtTail(int val) Append a node of value val as the last element of the linked list.
#     void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
#     void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.

# Example 1:

# Input
# ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
# [[], [1], [3], [1, 2], [1], [1], [1]]
# Output
# [null, null, null, null, 2, null, 3]

# Explanation
# MyLinkedList myLinkedList = new MyLinkedList();
# myLinkedList.addAtHead(1);
# myLinkedList.addAtTail(3);
# myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
# myLinkedList.get(1);              // return 2
# myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
# myLinkedList.get(1);              // return 3

class Node():
    def __init__(self, val):
        self.next = None
        self.val = val

class MyLinkedList(object):

    def __init__(self):
        self.head = None
        self.length = 0

    def get(self, index):
        """
        :type index: int
        :rtype: int
        """
        if index < 0 or index >= self.length:
            return -1
        
        trav = self.head
        for _ in range(index):
            trav = trav.next
        
        return trav.val

    def addAtHead(self, val):
        """
        :type val: int
        :rtype: None
        """
        new_node = Node(val)

        if not self.head:
            self.head = new_node
        else:
            new_node.next = self.head
            self.head = new_node
        
        self.length += 1

    def addAtTail(self, val):
        """
        :type val: int
        :rtype: None
        """

        if self.length == 0:
            self.addAtHead(val)

        else:
            new_node = Node(val)
            trav = self.head
            while trav.next:
                trav = trav.next

            trav.next = new_node
            self.length += 1

    def addAtIndex(self, index, val):
        """
        :type index: int
        :type val: int
        :rtype: None
        """        
        if index == 0:
           self.addAtHead(val)
        
        elif index == self.length:
            self.addAtTail(val)

        elif index > 0 and index < self.length:
            new_node = Node(val)
            trav = self.head
            for _ in range(index - 1):
                trav = trav.next
            
            new_node.next = trav.next
            trav.next = new_node
            self.length += 1
        else:
            return

        

    def deleteAtIndex(self, index):
        """
        :type index: int
        :rtype: None
        """
        if index < 0 or index >= self.length:
            return

        if index == 0:
            self.head = self.head.next
            
        else:
            trav = self.head
            for _ in range(index - 1):
                trav = trav.next

            trav.next = trav.next.next

        self.length -= 1

# Your MyLinkedList object will be instantiated and called as such:
# obj = MyLinkedList()
# param_1 = obj.get(index)
# obj.addAtHead(val)
# obj.addAtTail(val)
# obj.addAtIndex(index,val)
# obj.deleteAtIndex(index)
