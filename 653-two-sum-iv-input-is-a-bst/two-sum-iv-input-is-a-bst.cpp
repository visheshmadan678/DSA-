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
    void inorder(TreeNode *root){
        if(!root)return;
        inorder(root->left);
        nums.push_back(root->val); // push the roots value into the nums
        inorder(root->right);
    }
    bool findTarget(TreeNode* root, int target) {
        inorder(root);
        int i=0; int j = nums.size()-1;

        while(i<j){
            if(nums[i]+nums[j]<target){
                i++;
            }
            else if(nums[i]+nums[j]>target){
                j--;
            }
            else if(nums[i]+nums[j]==target){
                return true;
            }
        }

        return false;
    }
};