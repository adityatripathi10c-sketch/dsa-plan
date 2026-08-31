class Solution {
public:
    bool isValid(string s) {
        string st = ""; // Using a string as a stack for efficiency
        
        for (char c : s) {
            if (c == 'c') {
                int n = st.length();
                // Check if the stack has at least 2 characters and they are 'a' and 'b'
                if (n >= 2 && st[n - 1] == 'b' && st[n - 2] == 'a') {
                    st.pop_back(); // Remove 'b'
                    st.pop_back(); // Remove 'a'
                } else {
                    return false; // Invalid pattern preceding 'c'
                }
            } else {
                st.push_back(c); // Push 'a' or 'b'
            }
        }
        
        return st.empty();
    }
};
