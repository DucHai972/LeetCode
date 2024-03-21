class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        pre = pos = None
        cur = head
        while cur:
            pos = cur.next
            cur.next = pre
            pre = cur
            cur = pos
        return pre
