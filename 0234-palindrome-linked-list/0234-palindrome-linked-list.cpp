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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head->next == NULL) return true;
        
        ListNode *slow = head;
        ListNode *fast = head;

        while(fast != NULL && fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next;
        }

        ListNode *prev = NULL;
        ListNode *curr = slow;

        while(curr != NULL){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        // prev point to the head of reverse list

        ListNode *ptr1 = head;
        ListNode *ptr2 = prev;

        while(ptr2 != NULL){
            if(ptr1->val != ptr2->val){
                return false;
            }
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }

        return true;
    }
};