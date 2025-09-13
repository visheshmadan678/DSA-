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
    TreeNode* reverseOddLevels(TreeNode* root) {
        queue<TreeNode*>qt;
        qt.push(root);
        bool flag = false;
        while(!qt.empty()){
            int size = qt.size();
            vector<TreeNode*>vec;
            for(int i=0;i<size;i++){
                TreeNode *temp = qt.front();
                qt.pop();
                vec.push_back(temp);
                if(temp->left)qt.push(temp->left);
                if(temp->right)qt.push(temp->right);
            }
            //when all the nodes are inserted inside the vec

            if(flag){
                for(int i=0;i<size/2;i++){
                int temp = vec[i]->val;
                vec[i]->val = vec[size-i-1]->val; 
                vec[size-i-1]->val = temp;
                }
                flag = false;
            }
            else flag = true;
        }

        return root;
    }
};