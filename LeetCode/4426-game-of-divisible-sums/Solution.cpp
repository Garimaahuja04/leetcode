
class Solution {
public:
    long long maxDifference(vector<int>& nums) {
        int n = nums.size();

        vector<long long> dp(n + 2, 0);

        for(int i = n - 1; i >= 0; i--) {

            long long sum = nums[i];

            long long ans1;

            if(sum % 3 == 0)
                ans1 = sum - dp[i + 1];
            else
                ans1 = sum + dp[i + 1];

            dp[i] = ans1;

            if(i + 1 < n) {
                sum += nums[i + 1];

                long long ans2;

                if(sum % 3 == 0)
                    ans2 = sum - dp[i + 2];
                else
                    ans2 = sum + dp[i + 2];

                dp[i] = max(dp[i], ans2);
            }
        }

        return dp[0];
    }
};
