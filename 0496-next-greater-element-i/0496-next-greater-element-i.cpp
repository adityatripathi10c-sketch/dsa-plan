class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> nextGreaterMap;
        stack<int> st;

        // Step 1: nums2 par Monotonic Decreasing Stack chalate hain
        for (int num : nums2) {
            // Jab tak current num stack ke top se bada hai, top ko uska NGE mil gaya
            while (!st.empty() && num > st.top()) {
                nextGreaterMap[st.top()] = num;
                st.pop();
            }
            st.push(num);
        }

        // Step 2: nums1 ke elements ka answer map se lookup karte hain
        vector<int> result;
        for (int x : nums1) {
            if (nextGreaterMap.count(x)) {
                result.push_back(nextGreaterMap[x]);
            } else {
                result.push_back(-1); // Jin elements ka NGE nahi mila
            }
        }

        return result;
    }
};