
class Solution {
public:
    long long minimumMaxValue(int n, int index, int value) {
        if (value == 1) return -1;

        long long p = value;

        // Find the smallest prime factor of value
        for (long long i = 2; i * i <= value; i++) {
            if (value % i == 0) {
                p = i;
                break;
            }
        }

        long long left = index;
        long long right = n - 1 - index;

        // Check whether the left side is possible
        if (value - p < 2 * left) {
            return -1;
        }

        long long ans = value;

        // Calculate the minimum possible maximum
        if (right > 0) {
            if (value % 2 == 0) {
                ans = value + 2 * right;
            } else {
                ans = value + p + 2 * (right - 1);
            }
        }

        return ans;
    }
};
