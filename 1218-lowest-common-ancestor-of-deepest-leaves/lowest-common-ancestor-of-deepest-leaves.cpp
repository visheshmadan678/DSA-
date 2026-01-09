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
    pair<TreeNode*,long long> dfs(TreeNode *root, long long depth){
        if(!root)return {nullptr,0};
        pair<TreeNode*,long long>left = dfs(root->left,1 + depth); // the left answer
        pair<TreeNode*,long long>right = dfs(root->right,1 + depth); // the right answer

        if(left.first && right.first){
            if(left.second == right.second){
                return {root,left.second}; // return this root with the answer
            }
            else if(left.second > right.second){
                return {left.first,left.second};
            }
            else{
                return {right.first,right.second};
            }
        }

        if(left.first){
            //if only left is present
            return {left.first, left.second};
        }

        if(right.first){
            return {right.first,right.second};
        }

        return {root,depth}; // if both left and right are not present return root with current depth
    }
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return dfs(root,0).first;
    }
};