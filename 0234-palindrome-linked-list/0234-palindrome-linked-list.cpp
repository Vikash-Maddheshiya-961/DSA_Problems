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
    bool is_palindrome(vector<int> &arr){
        int n = arr.size();
        int i=0,j=n-1;

        while(i < j){
            if(arr[i] != arr[j]) return false;
            i++;
            j--;
        }

        return true;
    }
    bool isPalindrome(ListNode* head) {
        vector<int> arr;

        ListNode *ptr = head;

        while(ptr != NULL){
            arr.push_back(ptr->val);
            ptr = ptr -> next;
        }

        return is_palindrome(arr);
    }
};