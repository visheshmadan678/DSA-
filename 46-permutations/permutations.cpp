class Solution {
public:
vector<vector<int>>answer;

void recursion(vector<int>&nums,vector<int>&visited,vector<int>&ds){
	if(ds.size()==nums.size()){
		answer.push_back(ds);
		return;
	}

	for(int i=0;i<nums.size();i++){
		if(!visited[i]){
		ds.push_back(nums[i]);
		visited[i] = 1; // marks as visited 
		recursion(nums,visited,ds);
		visited[i] = 0;
		ds.pop_back();
		}
	}

}
    vector<vector<int>> permute(vector<int>& nums) {
	vector<int>visited(nums.size(),0); ///none is visited 
	vector<int>ds;

	recursion(nums,visited,ds);

	return answer;        
    }
};