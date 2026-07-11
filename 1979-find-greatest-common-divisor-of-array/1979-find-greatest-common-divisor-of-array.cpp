class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max_val=nums[0];
        int min_val=nums[0];
        for(int i=0;i<=nums.size()-1;i++){
            if(max_val<nums[i]){
                max_val=nums[i];
            }
            if(min_val>nums[i]){
                min_val=nums[i];
            }
        }
        while(min_val!=0){
            int temp=min_val;
            min_val=max_val%min_val;
            max_val=temp;
        }
        return max_val;
    }
};