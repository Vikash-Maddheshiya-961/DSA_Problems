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
    pair<ListNode*,ListNode*> reverselist(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return {prev,head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1 || !head->next) return head;
        ListNode* curr = head;
        ListNode* prev= NULL;
        ListNode* tail = NULL;
        while(curr){
            ListNode* temp = curr;
            int count = 0;
            while(count != k && curr){
                count++;
                prev = curr;
                curr = curr->next;
            }
            if(count != k){
                tail -> next = temp;
                break;
            }
            prev -> next = NULL;
            prev = NULL;
            if(temp == head){
                pair<ListNode*,ListNode*> p = reverselist(temp);
                head = p.first;
                tail = p.second;
            }
            else{
                pair<ListNode*,ListNode*> p = reverselist(temp);
                tail -> next = p.first;
                tail = p.second;
            }
        }
        return head;
    }
};