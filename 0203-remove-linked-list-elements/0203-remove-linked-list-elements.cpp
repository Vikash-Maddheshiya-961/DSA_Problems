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
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return head;
        if(head->next == NULL){
            if(head->val == val) return NULL;
            return head;
        }
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(curr != NULL){
            if(curr -> val == val){
                if(prev == NULL){
                    head = head->next;
                    ListNode *temp = curr;
                    curr = head;
                    temp->next = NULL;
                }
                else{
                    prev->next = curr -> next;
                    ListNode *temp = curr;
                    curr = curr->next;
                    temp -> next = NULL;
                }
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
        return head;
    }
};