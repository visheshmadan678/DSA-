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
    int moves = 0;
    //next time keep in mind most of the tree questions are made to be solved using dfs 
    //it's less chance that you have to make a graph of it and extract out the answer 
    int dfs(TreeNode *root){
        if(!root)return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        int extra  = abs(left) + abs(right); // this is the amount of moves
        moves += extra;
        return root->val + left + right -1;
    }
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return moves;
    }
};