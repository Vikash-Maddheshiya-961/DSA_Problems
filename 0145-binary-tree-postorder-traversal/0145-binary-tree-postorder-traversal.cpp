/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        // using 1 stack
        vector<int> ans;
        if(!root) return ans;

        stack<TreeNode*> s;
        TreeNode* curr = root;

        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr -> left;
            }
            TreeNode* temp = s.top() -> right;
            if(temp == NULL){
                temp = s.top();
                s.pop();
                ans.push_back(temp->val);
                while(!s.empty() && temp == s.top()->right){
                    temp = s.top();
                    s.pop();
                    ans.push_back(temp->val);
                }
            }
            else{
                curr = temp;
            }
        }

        return ans;
    }
};