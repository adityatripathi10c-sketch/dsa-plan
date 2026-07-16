class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int arraysum=0;
        int actualsum=(n*(n+1))/2;
        for(int i=0;i<n;i++){
            arraysum=arraysum+nums[i];
        }
        return actualsum-arraysum;
    }
};