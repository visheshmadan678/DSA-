class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);

        bool null_seen = false;

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (!node) {
                null_seen = true; 
            } else {
                if (null_seen) {
                    return false;
                }
                q.push(node->left);
                q.push(node->right);
            }
        }

        return true;
    }
};
