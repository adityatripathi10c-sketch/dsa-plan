class Solution {
private:
    set<vector<int>>result;
    void backtrack(int i,vector<int>&nums,vector<int>&current){
        if(i==nums.size()){
            result.insert(current);
            return;
        }
        current.push_back(nums[i]);
        backtrack(i+1,nums,current);
        current.pop_back();
        backtrack(i+1,nums,current);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int>current;
        sort(nums.begin(),nums.end());
        backtrack(0,nums,current);
        vector<vector<int>>v;
        for(auto i :result){
            v.push_back(i);
        }
        return v;
    }
};