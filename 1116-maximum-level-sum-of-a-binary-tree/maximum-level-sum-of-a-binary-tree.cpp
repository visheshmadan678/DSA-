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
    int maxLevelSum(TreeNode* root) {
        //i will make a bfs and calculate the sum at every level and keep it inside a map
        unordered_map<long long, long long>mp; long long level = 1;
        queue<TreeNode*>qt;
        qt.push(root); // insert the root inside the tree
        
        //make a bfs
        while(!qt.empty()){
            long long size = qt.size();
            long long sum = 0; // take  a sum variable for every level
            for(int i=0;i<size;i++){
                TreeNode *node = qt.front();  qt.pop();
                sum += node->val;
                if(node->left)qt.push(node->left);
                if(node->right)qt.push(node->right);
            }
            //when the iteration on the level is complete then update the map
            mp[level] = sum; 
            level++; // increae the level
        }


        //find the value from the map
        int ans =  INT_MAX; long long val = INT_MIN;

        for(auto &it:mp){
        
            long long curr_sum = it.second;
            int level  = it.first;
            if(curr_sum > val){
                ans = level;
                val = curr_sum;
            }
            else if(curr_sum == val){
                ans = min(ans,level);
            }
        }

        return ans; // return the answer in the end
    }
};