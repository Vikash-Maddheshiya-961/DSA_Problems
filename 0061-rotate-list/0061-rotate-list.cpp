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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || !k) return head;
        int n = 0;
        ListNode* ptr = head;
        while(ptr){
            n++;
            ptr = ptr->next;
        }

        if(k >= n) k = k%n;

        if(k == 0) return head;
        
        // reverse whole list
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr){
            ListNode* nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }

        head = prev;

        // reverse first part
        prev = NULL;
        curr = head;

        while(curr && k){
            ListNode* nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
            k--;
        }
        head = prev;
        // reversing second part
        prev = NULL;
        while(curr){
            ListNode* nxt = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        
        curr = head;
        while(curr->next){
            curr = curr->next;
        }

        curr -> next  = prev;

        return head;
    }
};