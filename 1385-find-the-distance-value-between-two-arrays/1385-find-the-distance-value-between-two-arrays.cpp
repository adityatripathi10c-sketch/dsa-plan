class Solution {
private:
    // Helper function: checks if any element in sorted arr2 lies in [x - d, x + d]
    bool hasInRange(const vector<int>& arr2, int x, int d) {
        int low = 0;
        int high = arr2.size() - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            // Target range ke andar element mil gaya
            if (arr2[mid] >= x - d && arr2[mid] <= x + d) {
                return true;
            } 
            else if (arr2[mid] < x - d) {
                low = mid + 1; // Range ke right side search karo
            } 
            else {
                high = mid - 1; // Range ke left side search karo
            }
        }

        return false;
    }

public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        // Step 1: arr2 ko sort karte hain taaki binary search laga sakein
        sort(arr2.begin(), arr2.end());

        int count = 0;

        // Step 2: arr1 ke har element ke liye binary search
        for (int x : arr1) {
            if (!hasInRange(arr2, x, d)) {
                count++;
            }
        }

        return count;
    }
};