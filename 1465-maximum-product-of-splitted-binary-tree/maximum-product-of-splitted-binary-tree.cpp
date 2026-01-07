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
    long long ans = LLONG_MIN; long long total_sum; int MOD = 1e9 + 7;
    long long dfs(TreeNode *root){
        if(!root)return 0;
        long long curr_sum  = root->val;
        curr_sum += dfs(root->left);
        curr_sum += dfs(root->right);
        ans = max(ans, curr_sum * (total_sum - curr_sum)); // find the answer also 
        return curr_sum;
    }

    long long total(TreeNode *root){
        if(!root)return 0;
        long long curr_sum = root->val;
        curr_sum += dfs(root->left);
        curr_sum += dfs(root->right);
        return curr_sum;
    }
    int maxProduct(TreeNode* root) {
        total_sum = total(root);
        dfs(root); // make a call to the dfs
        return ans % MOD;
    }
};