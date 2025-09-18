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
        stack<TreeNode*> st;
        vector<int> res;
        while(root!=NULL || st.empty()!=true){
            while(root!=NULL){
                st.push(root);
                st.push(root);
                root = root->left;
            }
            root = st.top();
            st.pop();
            if(st.empty()!=true && root == st.top()){
                root = root->right;
            }else{
                res.push_back(root->val);
                root = NULL;
            }
        }
        return res;
    }
};