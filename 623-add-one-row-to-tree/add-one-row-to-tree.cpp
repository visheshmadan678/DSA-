/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
// bye bye chat gpt
class Solution {
public:
    void dfs(TreeNode* root, int value, int depth, int target_depth) {
        if (!root)
            return;
        if (depth == target_depth - 1) {
            // then i have to perform the operation
            TreeNode* new_node = new TreeNode(value); // make new tree node
            TreeNode* temp = root->left;
            root->left = new_node; // change the new left
            new_node->left = temp; // link changed

            TreeNode* new_node2 = new TreeNode(value); // make new tree node
            TreeNode* temp2 = root->right;
            root->right = new_node2;  // change the new left
            new_node2->right = temp2; // link changed
        }
        dfs(root->left, value, depth + 1, target_depth);
        dfs(root->right, value, depth + 1, target_depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode *new_node = new TreeNode(val);
            new_node->left = root;
            return new_node;
        }
        dfs(root, val, 1, depth); // take the starting depth as one
        return root;
    }
};