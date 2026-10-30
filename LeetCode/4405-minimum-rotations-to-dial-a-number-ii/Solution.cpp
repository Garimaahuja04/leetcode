class Solution {
public:
    int minRotations(int n, string s) {
        auto dist = [](int a, int b) {
            int d = abs(a - b);
            return min(d, 10 - d);
        };

        int total = dist(0, s[0] - '0');

        for (int i = 1; i < n; i++) {
            total += dist(s[i - 1] - '0', s[i] - '0');
        }

        int ans = total;

        for (int k = 0; k < n; k++) {
            int oldCost;
            int newCost;

            if (k == 0) {
                oldCost = dist(0, s[0] - '0');
                newCost = dist(0, s[n - 1] - '0');
            } else {
                oldCost = dist(s[k - 1] - '0', s[k] - '0');
                newCost = dist(s[k - 1] - '0', s[n - 1] - '0');
            }

            int cost = total - oldCost + newCost;
            ans = min(ans, cost);
        }

        return ans;
    }
};