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
    int diameter = INT_MIN;
    int dfs(TreeNode *root){
        if(!root)return 0;
        if(!root->left && !root->right)return 0; // no more nodes are present here 
        int left = 0,right = 0;
        if(root->left)left = 1 + dfs(root->left); // i went in the left direction 
        if(root->right)right = 1 + dfs(root->right);
        diameter = max(diameter,left + right);
        //now i have to return the height actually and that is 
        return max(left,right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return diameter==INT_MIN?0:diameter;
    }
};