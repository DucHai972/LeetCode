// <ll>
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = list1;
        ListNode* end = list1;
        while(a-- > 1) start=start->next;
        while(b-- > -1) end=end->next;
        start->next = list2;
        ListNode* end2 = list1;
        while(end2->next) end2=end2->next;
        end2->next=end;
        return list1;
    }
};
