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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*,TreeNode*>parent;
        queue<TreeNode*>bfs;
        bfs.push(root);
        parent[root]=nullptr;
        while(!bfs.empty()){
            TreeNode* node=bfs.front();
            bfs.pop();
            if(node->left){
                parent[node->left]=node;
                bfs.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                bfs.push(node->right);
            }
        }
        unordered_set<TreeNode*>ancestor;
        while(p !=nullptr){
            ancestor.insert(p);
            p=parent[p];
        }
        while(q != nullptr){
            if(ancestor.count(q)){
                return q;
            }
            q=parent[q];
        }
        return nullptr;
    }
};
