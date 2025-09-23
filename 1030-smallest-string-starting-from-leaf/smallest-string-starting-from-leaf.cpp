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
    vector<string>ans;
    void dfs(TreeNode *root,string str){
        if(!root)return;
        if(root->left == nullptr && root->right == nullptr){
            str.push_back(char('a'+root->val));
            reverse(str.begin(),str.end());
            ans.push_back(str);
            return;
        }else{
        dfs(root->left,str + char('a'+root->val));
        dfs(root->right,str + char('a'+root->val));
        }
        return;
    }
    string smallestFromLeaf(TreeNode* root) {
        dfs(root,"");
        sort(ans.begin(),ans.end());
        for(auto &it:ans)cout<<it<<" ";
        return ans[0];
    }
};