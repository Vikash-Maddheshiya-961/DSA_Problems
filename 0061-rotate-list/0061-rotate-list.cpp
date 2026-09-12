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
        ListNode* temp = head;

        while(temp){
            n++;
            temp = temp->next;
        }

        if(k >= n) k = k % n;

        if(k == 0) return head;

        int move = n - k;
        temp = head;

        while(move > 1){
            temp = temp->next;
            move--;
        }

        ListNode *ptr = temp->next;
        temp->next = NULL;
        temp = ptr;

        while(ptr->next) ptr = ptr->next;

        ptr->next = head;
        head = temp;
        return head;
    }
};