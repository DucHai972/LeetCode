class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        ListNode* t = head;
        stack<ListNode*> st;
        while(t) {
            while(!st.empty() && t->val > st.top()->val) 
                st.pop();
            if(st.empty())
                head = t;
            else
                st.top()->next=t;
            st.push(t);
            t = t->next;
        }
        return head;
    }
};