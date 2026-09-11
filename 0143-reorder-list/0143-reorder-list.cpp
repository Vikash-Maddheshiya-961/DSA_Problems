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
    ListNode* reverse_list(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            ListNode *nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }

        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL || head->next->next == NULL) return;

        ListNode *prev = head;
        ListNode *curr = head->next;

        while(curr -> next != NULL){
            ListNode *ptr = reverse_list(curr);
            prev -> next = ptr;
            curr = ptr;
            prev = curr;
            curr = curr -> next;
        }

        return;
    }
};