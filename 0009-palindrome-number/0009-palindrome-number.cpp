class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int reverse = 0, original = x;

        while (x > 0){
            int digit = x % 10;
            if (reverse > INT_MAX / 10 or (reverse == INT_MAX / 10 and digit == 7)){
                return false;
            }
            reverse *= 10;
            reverse += digit;
            x /= 10;
        }

        return reverse == original;
    }
};