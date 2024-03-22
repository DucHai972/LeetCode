# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        trav = head
        arr = []
        while(trav):
            arr.append(trav.val)
            trav = trav.next
        j = len(arr)-1
        for i in range (int(len(arr)/2)):
            if arr[i] != arr[j]:
                return False
            j -= 1
        return True

        
