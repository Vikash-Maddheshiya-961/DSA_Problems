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
    ListNode* reverselist(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(curr){
            ListNode *nxt = curr->next;
            curr -> next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverselist(l1);
        l2 = reverselist(l2);

        ListNode* head = NULL;
        ListNode* ptr = NULL;
        int carry = 0;
        int sum,fraction;
        while(l1 || l2 || carry != 0){
            sum = carry;

            if(l1){
                sum += l1 -> val;
                l1 = l1 -> next;
            }

            if(l2){
                sum += l2 -> val;
                l2 = l2 -> next;
            }

            fraction = sum % 10;
            carry = sum / 10;
            ListNode* temp = new ListNode(fraction);

            if(head == NULL){
                head = temp;
                ptr = head;
            }
            else{
                ptr -> next = temp;
                ptr = ptr->next;
            }
        }

        head = reverselist(head);
        return head;

    }
};