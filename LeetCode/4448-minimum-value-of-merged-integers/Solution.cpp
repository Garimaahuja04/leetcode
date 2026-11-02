
class Solution {
public:
    int minMergedInteger(vector<int>& nums) {
        int ans = INT_MAX;

        for (int i = 0; i < nums.size(); i += 2) {
            int first = nums[i];
            int second = nums[i + 1];

            int temp = second;
            while (temp > 0) {
                first *= 10;
                temp /= 10;
            }

            int merged = first + second;
            ans = min(ans, merged);
        }

        return ans;
    }
};
