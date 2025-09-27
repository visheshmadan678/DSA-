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
    vector<TreeNode *>ans;
    void dfs(TreeNode *root,unordered_map<int,int>&mp,TreeNode *parent){
        if(!root)return;
        if(mp.find(root->val)!=mp.end()){
            //if map has the value it means it should be deleted 
            if(parent->left){
                if(parent->left->val == root->val){
                    parent->left = nullptr; //delete the parent child connection
                }
            }
            if(parent->right){
                if(parent->right->val == root->val)parent->right = nullptr;
            }
            if(root->left){if(mp.find(root->left->val)==mp.end())ans.push_back(root->left);}
            if(root->right){if(mp.find(root->right->val)==mp.end())ans.push_back(root->right);}          
        }
        dfs(root->right,mp,root);
        dfs(root->left,mp,root);
        return;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int,int>mp;
        for(auto &it:to_delete){
            mp[it] = 1; // insert into the map
        }
       dfs(root,mp,root);
        if(mp.find(root->val)!=mp.end()){
            return ans;
        }
        else{
            ans.push_back(root);
        }
        return ans;
    }
};