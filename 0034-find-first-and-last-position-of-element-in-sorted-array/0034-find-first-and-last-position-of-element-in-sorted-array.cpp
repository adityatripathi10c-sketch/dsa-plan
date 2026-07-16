class Solution {
public:
    int findFirst(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int firstPos = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) {
            firstPos = mid;
            high = mid - 1; // Look left
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return firstPos;
}
    int findLast(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;
    int firstPos = -1;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        
        if (nums[mid] == target) {
            firstPos = mid;
            low = mid + 1; // Look left
        } else if (nums[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return firstPos;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.empty()){
            return {-1,-1};
        }
        int first=findFirst(nums,target);
        int last=findLast(nums,target);
        return {first,last};
    }
};