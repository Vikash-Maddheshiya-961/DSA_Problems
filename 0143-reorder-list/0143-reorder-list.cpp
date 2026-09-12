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
    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;
        
        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL && fast->next!=NULL){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast) break;
        }

        ListNode* pointer = head;

        while(pointer->next != slow){
            pointer = pointer->next;
        }
        pointer-> next = NULL;

        ListNode* prev = NULL;
        ListNode* curr = slow;

        while(curr!=NULL){
            ListNode* nxt = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }

        ListNode* ptr1 = head;
        ListNode* ptr2 = prev;

        while(ptr1 != NULL && ptr2 != NULL){
            ListNode *temp = ptr1->next;
            ptr1->next = ptr2;
            ptr1 = temp;
            temp = ptr2->next;
            ptr2->next = ptr1;
            ptr2 = temp;
        }

        if(ptr2!=NULL){
            ptr1 = head;
            while(ptr1 -> next != NULL) ptr1 = ptr1 -> next;
            ptr1 -> next = ptr2;
        }
        
        return;
    }
};