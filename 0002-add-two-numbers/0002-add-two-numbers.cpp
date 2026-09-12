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
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* head = NULL;
        ListNode* ptr = NULL;
        int carry = 0;

        while(ptr1 || ptr2 || carry != 0){
            int sum = carry;

            if(ptr1){
                sum += ptr1 -> val;
                ptr1 = ptr1 -> next;
            }

            if(ptr2){
                sum += ptr2 -> val;
                ptr2 = ptr2 -> next;
            }

            int fraction = sum % 10;
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