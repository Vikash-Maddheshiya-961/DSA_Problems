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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;

        ListNode head1(0);
        ListNode head2(0);
        ListNode* tail1 = &head1;
        ListNode* tail2 = &head2;

        ListNode* ptr = head;

        while(ptr){
            if(ptr-> val < x){
                tail1 -> next = ptr;
                tail1 = tail1 -> next;
            }
            else{
                tail2 -> next = ptr;
                tail2 = tail2 -> next;
            }
            ptr = ptr -> next;
        }

        tail2 -> next = NULL;
        
        tail1 -> next = head2.next;

        return head1.next;
    }
};