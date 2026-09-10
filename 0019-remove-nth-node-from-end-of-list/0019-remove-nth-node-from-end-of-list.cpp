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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *p1 = head;
        ListNode *p2 = head;
        ListNode *prev = NULL;
        while(p1 != NULL && p2 != NULL){
            if(n == 0){
                prev = p1;
                p1 = p1 -> next;
            }
            else{
                n--;
            }
            p2 = p2 -> next;
        }

        if(p1 == head){
            head = head -> next;
            return head;
        }

        prev->next = p1->next;
        delete p1;

        return head;
    }
};