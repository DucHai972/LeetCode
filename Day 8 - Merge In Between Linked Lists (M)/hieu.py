class Solution:
    def mergeInBetween(self, list1: ListNode, a: int, b: int, list2: ListNode) -> ListNode:
        p = list1
        for _ in range(a - 1):
            p = p.next
        q = p.next
        p.next = list2
        for _ in range(b - a + 1):
            q = q.next
        while list2.next:
            list2 = list2.next
        list2.next = q
        return list1
