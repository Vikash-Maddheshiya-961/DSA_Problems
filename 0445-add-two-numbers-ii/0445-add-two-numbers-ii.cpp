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
    int length(ListNode* ptr){
        int n = 0;
        while(ptr){
            n++;
            ptr = ptr->next;
        }
        return n;
    }

    int carry;
    ListNode* solve(ListNode* l1, ListNode* l2,int len1, int len2){
        if(!l1 && !l2) return NULL;

        ListNode* temp = NULL;
        int val1 = 0, val2 = 0;

        if(len1 > len2){
            temp = solve(l1->next,l2,len1-1,len2);
            val1 = l1 -> val;
        }
        else if(len1 < len2){
            temp = solve(l1,l2->next,len1,len2-1);
            val2 = l2 -> val;
        }
        else{
            temp = solve(l1->next,l2->next,len1-1,len2-1);
            val1 = l1 -> val;
            val2 = l2 -> val;
        }

        int sum = val1 + val2 + carry;
        carry = sum / 10;

        ListNode* curr_node = new ListNode(sum % 10);
        curr_node -> next = temp;

        return curr_node;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int len1 = length(l1);
        int len2 = length(l2);
        carry = 0;
        
        ListNode* head = solve(l1,l2,len1,len2);

        if(carry > 0){
            ListNode* temp = new ListNode(carry);
            temp -> next = head;
            head = temp; 
        }

        return head;
    }
};