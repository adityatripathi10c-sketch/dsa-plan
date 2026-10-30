class Solution {
private:
    void backtrack(int start,int target,vector<int>&current,vector<int>&candidates,vector<vector<int>>&ans){
        if(target==0){
            ans.push_back(current);
            return;
        }
        for(int i=start;i<candidates.size();i++){
            if(i>start&&candidates[i]==candidates[i-1])continue;
            if(candidates[i]>target)break;
            current.push_back(candidates[i]);
            backtrack(i+1,target-candidates[i],current,candidates,ans);
            current.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int>current;
        vector<vector<int>>ans;
        backtrack(0,target,current,candidates,ans);
        return ans;
    }
};