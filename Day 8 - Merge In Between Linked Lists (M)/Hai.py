# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        trav = list1
        for i in range (a-1):
            trav = trav.next

        skip = trav
        for i in range (a, b+2):
            skip = skip.next
            
        trav.next = list2

        while(trav.next):
            trav = trav.next

        trav.next = skip
        
        return list1
