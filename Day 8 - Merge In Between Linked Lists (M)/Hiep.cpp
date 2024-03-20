/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* start = list1;
        ListNode* cur = list1;
        ListNode* temp = list1;
        a--;
        while(start->next != NULL && a-- > 0){
            start = start->next;
            temp = start;
        }
        ListNode* end = list1;

        while(end != NULL && b--){
            end = end->next;
            cur = end;
        }
        temp->next = list2;
        ListNode* temp2 = list2;
        while(temp2->next != NULL){
            temp2 = temp2 -> next;
        }
        temp2->next = cur->next;
        return list1;
    }
};
