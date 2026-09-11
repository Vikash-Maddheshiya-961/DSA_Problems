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
    ListNode* oddEvenList(ListNode* head) {
        if(head == NULL || head->next == NULL || head -> next -> next == NULL) return head;

        ListNode *h1 = head;
        ListNode *h2 = head->next;

        ListNode *p1 = h1;
        ListNode *p2 = h2;

        while(p1 != NULL && p2!=NULL){
            p1 -> next = p2 -> next;
            if(p1 -> next == NULL){
                break;
            }
            p1 = p1 -> next;
            p2 -> next = p1 -> next;
            p2 = p2->next;
        }
        p1 -> next = h2;

        return h1;
    }
};