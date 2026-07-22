class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            // 🎯 Target found!
            if (nums[mid] == target) {
                return true;
            }

            // 1️⃣ Handle duplicates when boundaries and middle match
            if (nums[left] == nums[mid] && nums[mid] == nums[right]) {
                left++;
                right--;
                continue; // Skip to next iteration to recalculate mid
            }

            // 2️⃣ Check if the left half is sorted
            if (nums[left] <= nums[mid]) {
                if (target >= nums[left] && target < nums[mid]) {
                    right = mid - 1; // Search left
                } else {
                    left = mid + 1;  // Search right
                }
            } 
            // 3️⃣ Otherwise, the right half must be sorted
            else {
                if (target > nums[mid] && target <= nums[right]) {
                    left = mid + 1;  // Search right
                } else {
                    right = mid - 1; // Search left
                }
            }
        }

        return false;
    }
};