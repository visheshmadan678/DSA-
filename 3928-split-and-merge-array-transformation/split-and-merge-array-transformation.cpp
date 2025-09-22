class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        queue<pair<vector<int>, int>> q; 
        set<vector<int>> visited; 
        
        q.push({nums1, 0});
        visited.insert(nums1);
        
        while (!q.empty()) {
            auto [curr, ops] = q.front();
            q.pop();
            
            if (curr == nums2) return ops;
            
            int n = curr.size();
            for (int L = 0; L < n; L++) {
                for (int R = L; R < n; R++) {
                    vector<int> sub(curr.begin() + L, curr.begin() + R + 1);
                    vector<int> rem;
                    for (int i = 0; i < n; i++) {
                        if (i < L || i > R) rem.push_back(curr[i]);
                    }
                    
                    for (int pos = 0; pos <= rem.size(); pos++) {
                        vector<int> next = rem;
                        next.insert(next.begin() + pos, sub.begin(), sub.end());
                        if (!visited.count(next)) {
                            visited.insert(next);
                            q.push({next, ops + 1});
                        }
                    }
                }
            }
        }
        
        return -1; 
    }
};
