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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            ListNode* ptr = lists[i];
            while(ptr != NULL){
                pq.push(ptr->val);
                ptr = ptr -> next;
            }
        }

        ListNode* head = new ListNode(0); // dummy Node
        ListNode* ptr = head;
        while(!pq.empty()){
            int val = pq.top();
            pq.pop();
            ListNode* temp = new ListNode(val); 
            ptr -> next = temp;
            ptr = temp;
        }

        return head -> next;
    }
};