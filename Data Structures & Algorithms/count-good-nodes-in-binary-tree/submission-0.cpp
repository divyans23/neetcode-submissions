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
    int dfs(TreeNode*root,int maxSofar){
        if(root==nullptr){
            return 0;
        }
        int good_count=0;
        if(root->val >= maxSofar){
            good_count=1;
            maxSofar=root->val;
        }
        good_count+=dfs(root->left,maxSofar);
        good_count+=dfs(root->right,maxSofar);
        return good_count;
    }
    int goodNodes(TreeNode* root) {
        return dfs(root,root->val);
    }
};
