#include <vector>
#include <algorithm>
#include <climits>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        // 1. Locate the position of 0
        int idx0 = 0;
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) {
                idx0 = i;
                break;
            }
        }

        // 2. Check if circularly sorted clockwise
        bool is_clockwise = true;
        for (int k = 0; k < n; ++k) {
            if (nums[(idx0 + k) % n] != k) {
                is_clockwise = false;
                break;
            }
        }

        // 3. Check if circularly sorted counter-clockwise
        bool is_counter = true;
        for (int k = 0; k < n; ++k) {
            if (nums[(idx0 - k + n) % n] != k) {
                is_counter = false;
                break;
            }
        }

        if (!is_clockwise && !is_counter) {
            return -1;
        }

        int ans = INT_MAX;

        // Case A: Clockwise configuration
        if (is_clockwise) {
            int cost1 = idx0;
            int cost2 = (idx0 == 0) ? 0 : (2 + (n - idx0) % n);
            ans = std::min({ans, cost1, cost2});
        }

        // Case B: Counter-clockwise configuration
        if (is_counter) {
            int cost3 = 1 + (n - 1 - idx0);
            int cost4 = (idx0 + 1) % n + 1;
            ans = std::min({ans, cost3, cost4});
        }

        return ans;
    }
};