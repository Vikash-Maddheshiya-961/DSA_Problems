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
    ListNode* deleteMiddle(ListNode* head) {
        if(head -> next == NULL) return NULL;
        int n = 0;
        ListNode* ptr = head;
        while(ptr != NULL){
            n++;
            ptr = ptr -> next;
        }
        int idx = n / 2;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(idx!=0){
            prev = curr;
            curr = curr -> next;
            idx--;
        }

        prev->next = curr-> next;
        curr->next = NULL;

        return head;
    }
};