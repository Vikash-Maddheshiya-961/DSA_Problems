/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long  val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long  x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long  x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        long long maxi = 0;
        queue<pair<TreeNode*,long long>> q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            long long minidx = q.front().second;
            long long first,last;
            for(int i=0;i<size;i++){
                TreeNode* temp = q.front().first;
                long long curridx = q.front().second - minidx;
                q.pop();
                if(i == 0) first = curridx;
                if(i == size-1) last = curridx;
                if(temp->left) q.push({temp->left,2*curridx+1});
                if(temp->right)q.push({temp->right,2*curridx+2});
            }
            maxi = max(maxi,last-first+1);
        }

        return maxi;
    }
};