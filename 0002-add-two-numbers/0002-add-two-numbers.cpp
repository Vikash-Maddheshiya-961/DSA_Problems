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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
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

        return head;
    }
};