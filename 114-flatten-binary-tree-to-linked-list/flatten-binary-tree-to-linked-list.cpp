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
    vector<int>nums;
    void preorder(TreeNode *root){
        if(!root)return;
        nums.push_back(root->val);
        preorder(root->left);
        preorder(root->right);
    }
    void flatten(TreeNode* root) {
        if(!root)return;
        TreeNode *temp_root = root;
        preorder(temp_root);

        TreeNode *new_head = root;  // this is the new head
        new_head->val = nums[0];
        new_head->left = nullptr;


        for(int i=1;i<nums.size();i++){
            new_head->right = new TreeNode(nums[i]);
            new_head = new_head->right;
        }  

    }
};