// <ll> <impl>
class Solution {
public:
    ListNode* reverseList(ListNode* h) {
        ListNode* pr = NULL;
        while(h) {
            pr = new ListNode(h->val,pr);
            h = h->next;
        }
        return pr;
    }
    void print(ListNode *p) {
        ListNode *t=p;
        while(t) {
            cout<<t->val<<' ';
            t=t->next;
        }
        cout<<'\n';
    }
    void reorderList(ListNode* head) {
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *half = reverseList(slow->next);
        slow->next = NULL;
        ListNode *t, *i = head;
        while(i && half) { 
            t=i->next;
            i->next = half;
            half=half->next;
            i=i->next;
            i->next=t;
            i=i->next;
        }
    }
};