class Solution {
public:
    double myPow(double x, int n) {
        long long exp = n;

        // Make the exponent positive first without changing the base yet
        if (exp < 0) {
            exp = -exp;
        }

        double ans = 1.0;

        // Binary exponentiation loop using original x
        while (exp > 0) {
            if (exp % 2 == 1) {
                ans *= x;
            }
            x *= x;
            exp /= 2;
        }

        // Apply reciprocal once at the very end if original n was negative
        if (n < 0) {
            return 1.0 / ans;
        }

        return ans;
    }
};