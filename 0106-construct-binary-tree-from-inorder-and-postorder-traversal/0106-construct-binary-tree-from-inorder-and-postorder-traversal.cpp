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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        reverse(postorder.begin(),postorder.end());
        TreeNode* root = build_Tree(postorder,0,postorder.size()-1,inorder,0,inorder.size()-1,&mp);
        return root;
    }
    TreeNode* build_Tree(vector<int>& postorder,int poststr,int postend,vector<int>& inorder,int instr,int inend,unordered_map<int,int>* mp){
        if(poststr>postend || instr>inend) return NULL;

        TreeNode* root = new TreeNode(postorder[poststr]);
        int index = (*mp)[postorder[poststr]];
        int numsleft = inend-index;

        root->left = build_Tree(postorder,poststr+numsleft+1,postend,inorder,instr,index-1,mp);
        root->right = build_Tree(postorder,poststr+1,poststr+numsleft,inorder,index+1,inend,mp);

        return root;
    }
}; 