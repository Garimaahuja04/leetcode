
class Solution {
public:
    long long countConsistent(vector<int>& nums) {

        int n = nums.size();

        vector<int> lg(n + 1, 0);

        for(int i = 2; i <= n; i++)
            lg[i] = lg[i / 2] + 1;

        int K = lg[n] + 1;

        vector<vector<int>> mn(K, vector<int>(n));
        vector<vector<int>> an(K, vector<int>(n));

        for(int i = 0; i < n; i++) {
            mn[0][i] = nums[i];
            an[0][i] = nums[i];
        }

        // Build Sparse Tables
        for(int k = 1; k < K; k++) {
            for(int i = 0; i + (1 << k) <= n; i++) {

                mn[k][i] = min(
                    mn[k-1][i],
                    mn[k-1][i + (1 << (k-1))]
                );

                an[k][i] =
                    an[k-1][i] &
                    an[k-1][i + (1 << (k-1))];
            }
        }

        // Range Minimum Query
        auto getMin = [&](int l, int r) {
            int k = lg[r - l + 1];

            return min(mn[k][l],
                       mn[k][r - (1 << k) + 1]);
        };

        // Range AND Query
        auto getAnd = [&](int l, int r) {
            int k = lg[r - l + 1];

            return an[k][l] &
                   an[k][r - (1 << k) + 1];
        };

        long long ans = 0;

        for(int i = 0; i < n; i++) {

            int x = nums[i];

            // Find leftmost valid boundary
            int low = 0, high = i;

            while(low < high) {
                int mid = low + (high - low) / 2;

                if(getMin(mid, i) >= x &&
                   (getAnd(mid, i) & x) == x) {
                    high = mid;
                }
                else {
                    low = mid + 1;
                }
            }

            int L = low;

            // Find rightmost valid boundary
            low = i;
            high = n - 1;

            while(low < high) {
                int mid = low + (high - low + 1) / 2;

                bool valid = true;

                if(mid > i) {
                    valid = (getMin(i + 1, mid) > x &&
                             (getAnd(i + 1, mid) & x) == x);
                }

                if(valid)
                    low = mid;
                else
                    high = mid - 1;
            }

            int R = low;

            ans += 1LL * (i - L + 1) * (R - i + 1);
        }

        return ans;
    }
};
