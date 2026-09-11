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
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL) return head;

        ListNode* prev = head;
        ListNode* curr = head->next;
        head = curr;

        while(curr!=NULL){
            ListNode *nxt = curr -> next;
            curr->next = prev;
            if(nxt == NULL){
                prev -> next = NULL;
                break;
            }

            if(nxt -> next == NULL){
                prev->next = nxt;
                break;
            }

            prev->next = nxt -> next;
            curr = nxt -> next;
            prev = nxt;
        }

        return head;
    }
};