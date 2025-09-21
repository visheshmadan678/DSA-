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
    //code by vishu badmos 
    //badmashi nhi mitar 
    int count = 0; // this is the global count i will increase it's value the if the condition matches in the future
    pair<int,int>dfs(TreeNode *root){
        if(!root)return {0,0};
        pair<int,int>p = {0,root->val};
        p.first +=1; // as i am standing on the current node 
        pair<int,int>a =  dfs(root->left);
        pair<int,int>b = dfs(root->right);
        p.second += a.second + b.second;
        p.first += a.first + b.first;
        if((p.second / p.first) == root->val)count++;
        return p;
    }
    int averageOfSubtree(TreeNode* root) {
        //for every root find the sum of the subtree and the count of the nodes present below it 
        pair<int,int>q = dfs(root);
        return count;
    }
};