class Solution {
private:
    void backtrack(vector<bool>visited,vector<int>&nums,vector<int>&curr,vector<vector<int>>&ans){
        if(curr.size()==nums.size()){
            ans.push_back(curr);
            return;

        }
        for(int i=0;i<nums.size();i++){

        if(visited[i]){continue;}
        visited[i]=true;
        curr.push_back(nums[i]);
        backtrack(visited,nums,curr,ans);
        curr.pop_back();
        visited[i]=false;
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>curr;
        vector<bool>visited(nums.size(),false);
        backtrack(visited,nums,curr,ans);
        return ans;
    }
};