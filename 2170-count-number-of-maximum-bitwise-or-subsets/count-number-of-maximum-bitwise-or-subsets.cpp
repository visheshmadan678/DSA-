class Solution {
public:
vector<vector<int>>ans;
void recursion(int idx, vector<int>ds,vector<int>&nums){
	if(idx>=nums.size()){
		ans.push_back(ds);
		return;
	}

	ds.push_back(nums[idx]);
	recursion(idx+1,ds,nums);

	ds.pop_back();
	recursion(idx+1,ds,nums);

}
    int countMaxOrSubsets(vector<int>& nums) {
	vector<int>ds;
	recursion(0,ds,nums);

	vector<int>s;

	for(auto it:ans){
		int a = 0;
		for(auto j:it){
			a |= j;
		}
		s.push_back(a);
	}

	int maxi = *max_element(s.begin(),s.end());
	int cnt = 0;
	for(auto it:s)if(it==maxi)cnt++;

	return cnt;  
    }
};