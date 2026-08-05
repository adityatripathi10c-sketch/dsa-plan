class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int mapS[256] = {0};
        int mapT[256] = {0};

        for (int i = 0; i < s.length(); i++) {
            // 1️⃣ Mismatch check: If previous recorded positions don't match, return false
            if (mapS[s[i]] != mapT[t[i]]) {
                return false;
            }

            // 2️⃣ Update both maps with current position (using i + 1)
            mapS[s[i]] = i + 1;
            mapT[t[i]] = i + 1;
        }

        return true;
    }
};