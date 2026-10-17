class Solution {

public:
    int digit_sum(int x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x = x / 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        struct Element {
            int digitsum;
            int val;
            int idx;
        };
        vector<Element> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = {digit_sum(nums[i]), nums[i], i};
        }
        sort(arr.begin(), arr.end(), [](const Element& a, const Element& b) {
            if (a.digitsum != b.digitsum) {
                return a.digitsum < b.digitsum;
            }
            return a.val < b.val;
        });
        vector<bool> visited(n, false);
        int totalswaps = 0;
        for (int i = 0; i < n; i++) {

            if (visited[i] || arr[i].idx == i) {
                continue;
            }

            int cycle = 0;
            int curr = i;
            while (!visited[curr]) {
                visited[curr] = true;
                cycle++;
                curr = arr[curr].idx;
            }
            if (cycle > 1) {
                totalswaps += (cycle - 1);
            }
        }
        return totalswaps;
    }
};