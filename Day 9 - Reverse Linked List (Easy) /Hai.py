# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        trav = head
        arr = []
        while (trav):
            arr.append(trav.val)
            trav = trav.next
        newhead = head
        for i in range(len(arr)-1, -1, -1):
            newhead.val = arr[i]
            newhead = newhead.next

        return head
