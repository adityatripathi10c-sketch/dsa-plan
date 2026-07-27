class Solution {
public:
    int shipWithinDays(std::vector<int>& weights, int days) {
        // The minimum possible ship capacity must be at least the heaviest single package.
        int left = *std::max_element(weights.begin(), weights.end());
        // The maximum capacity needed is the sum of all packages (shipping everything in 1 day).
        int right = std::accumulate(weights.begin(), weights.end(), 0);
        
        int result = right;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            if (canShipWithCapacity(weights, days, mid)) {
                result = mid;       // 'mid' works, record it as a potential minimum
                right = mid - 1;    // Try to find a smaller feasible capacity
            } else {
                left = mid + 1;     // 'mid' is too small, increase capacity
            }
        }
        
        return result;
    }

private:
    bool canShipWithCapacity(const std::vector<int>& weights, int maxDays, int capacity) {
        int daysNeeded = 1;
        int currentWeight = 0;
        
        for (int weight : weights) {
            if (currentWeight + weight > capacity) {
                daysNeeded++;       // Move package to the next day
                currentWeight = 0;  // Reset current ship load
            }
            currentWeight += weight;
        }
        
        return daysNeeded <= maxDays;
    }
};
