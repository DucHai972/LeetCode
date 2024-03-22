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
        ListNode *slow = head;
        stack<int> check;
        while(slow != NULL){
            check.push(slow->val);
            slow = slow->next;
        }
        while(head != NULL){
            int i = check.top();
            check.pop();
            if(head->val != i){
                return false;
            }
            head = head -> next;
        }
        return true;

    }
};
