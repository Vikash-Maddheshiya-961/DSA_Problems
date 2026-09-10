/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = 0;
        ListNode *ptr = headA;

        while(ptr != NULL){
            len1++;
            ptr = ptr -> next;
        }

        int len2 = 0;
        ptr = headB;

        while(ptr != NULL){
            len2++;
            ptr = ptr -> next;
        }

        ListNode* ptr1 = headA;
        ListNode* ptr2 = headB;

        if(len1 > len2){
            while(len1 != len2){
                ptr1 = ptr1 -> next;
                len1--;
            }
        }

        if(len2 > len1){
            while(len1 != len2){
                ptr2 = ptr2 -> next;
                len2--;
            }
        }

        while(ptr1 != NULL && ptr2 != NULL){
            if(ptr1 == ptr2) return ptr1;
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }

        return NULL;
    }
};