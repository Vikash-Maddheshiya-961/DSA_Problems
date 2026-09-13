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

        ListNode* head1 = NULL;
        ListNode* tail1 = NULL;
        ListNode* head2 = NULL;
        ListNode* tail2 = NULL;

        ListNode* ptr = head;

        while(ptr){
            if(ptr-> val < x){
                ListNode* temp = ptr;
                ptr = ptr->next;
                if(head1 == NULL){
                    head1 = temp;
                    tail1 = head1;
                    tail1->next = NULL;
                }
                else{
                    tail1->next = temp;
                    tail1 = tail1->next;
                    tail1 -> next = NULL;
                }
            }
            else{
                ListNode* temp = ptr;
                ptr = ptr->next;
                if(head2 == NULL){
                    head2 = temp;
                    tail2 = head2;
                    tail2->next = NULL;
                }
                else{
                    tail2 -> next = temp;
                    tail2 = tail2 -> next;
                    tail2 -> next = NULL;
                }
            }
        }

        if(head1){
            tail1 -> next = head2;
            return head1;
        }

        return head2;
    }
};