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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root = build_tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,&mp);
        return root;
    }
    TreeNode* build_tree(vector<int>& preorder,int prestr,int preend,vector<int>& inorder,int instr,int inend,unordered_map<int,int>* mp){
        if(prestr>preend || instr>inend) return NULL;
        TreeNode* root = new TreeNode(preorder[prestr]);
        
        int index = (*mp)[preorder[prestr]];
        int numsleft = index-instr;

        root->left = build_tree(preorder,prestr+1,prestr+numsleft,inorder,instr,index-1,mp);
        root->right = build_tree(preorder,prestr+numsleft+1,preend,inorder,index+1,inend,mp);

        return root;
    }
};