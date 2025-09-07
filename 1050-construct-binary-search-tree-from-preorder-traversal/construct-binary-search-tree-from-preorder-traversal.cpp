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
    void addintobst(TreeNode *parent,TreeNode *root,TreeNode *new_node){
        if(!root){
            //it means i reached the very bottom part of the tree now i have to add this value 
            if(new_node->val>parent->val)parent->right = new_node;
            else parent->left = new_node;
            return;
         }
        if(new_node->val > root->val)addintobst(root,root->right,new_node); // then go to the left
        if(new_node->val < root->val)addintobst(root,root->left,new_node); // then go to the right
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        //so i have the preoder traversal array and i have to construct the tree from it 
        TreeNode *root = new TreeNode(preorder[0]); //make first element as my root;
        for(int i=1;i<preorder.size();i++){
            TreeNode *temp = new TreeNode(preorder[i]);
            addintobst(root,root,temp); // add this temp to the bst
        }
        return root;
    }
};