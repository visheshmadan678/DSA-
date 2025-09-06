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
    unordered_map<int,vector<int>>adjlist; // this to represent adjacency list 
    void dfs(TreeNode *parent){
        if(parent==nullptr)return; // if it's null then straightaway return 
        //har root par jakr dono child add krdo bus adjaceny list
        if(parent->right){
        adjlist[parent->val].push_back(parent->right->val);
        adjlist[parent->right->val].push_back(parent->val);
        }

        if(parent->left){
        adjlist[parent->val].push_back(parent->left->val);
        adjlist[parent->left->val].push_back(parent->val);
        }
        dfs(parent->left); // go left
        dfs(parent->right); // go right
    }
    int amountOfTime(TreeNode* root, int start) {
        dfs(root);

        int ans = 0;

        queue<int>qt;
        qt.push(start);
        set<int>st;

        while(!qt.empty()){
            int size = qt.size();
            for(int i=0;i<size;i++){
                int node = qt.front();
                st.insert(node); // to mark this node as done
                qt.pop();
                for(auto it:adjlist[node]){
                    if(!st.count(it))qt.push(it); // push all of those nodes into the queue
                }
            }
            ans++;
        }

        return ans-1;
    }
};