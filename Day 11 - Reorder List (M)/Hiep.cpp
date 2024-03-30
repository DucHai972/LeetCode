# I had finished but I forgot to commit 
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
    ListNode *reverse(ListNode *head){
        ListNode *prev = NULL;
        ListNode *cur = head;
        while(cur != NULL){
            ListNode  *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
    void merge(ListNode *l1, ListNode *l2){
        while(l1 != NULL){
            ListNode *l1_next = l1->next;
            ListNode *l2_next = l2->next;

            l1-> next = l2;
            if(l1_next == NULL){
                break;
            }
            l2->next = l1_next;
            l1 = l1_next;
            l2 = l2_next;
        }
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL)return;
       ListNode *slow = head;
       ListNode *l1 = head;
       ListNode *fast = head;
       ListNode *prev = NULL;
       while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
       }
       prev->next = NULL;

       ListNode *l2 = reverse(slow);
       merge(l1, l2);

    }
};
