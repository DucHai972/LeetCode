// <ll>
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
    bool isPalindrome(ListNode* head) {
        int n = 1;
        ListNode *fast = head, *slow = head, *pre = NULL, *t;
        while(fast->next && fast->next->next) {
            t = slow->next;
            fast = fast->next->next;
            n+=2;

            slow->next = pre;
            pre = slow;
            slow = t;
        }
        if(fast->next) n++;
        ListNode *half = slow -> next;
        slow->next = pre;
        if(n%2) 
            slow = slow->next;
        while(slow && half) {
            // cout<<slow->val<<' '<<half->val;
            if(slow->val != half->val) return 0;
            slow=slow->next;
            half=half->next;
        }
        return 1;
    }
};