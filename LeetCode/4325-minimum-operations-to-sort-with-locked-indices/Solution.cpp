
class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();

        int lockedCount = 0;
        int validLocked = 0;
        int maxVal = 0;

        // Find locked positions that can safely remain locked
        for (int i = 0; i < n; i++) {
            if (locked[i] == 1) {
                lockedCount++;
            }

            maxVal = max(maxVal, nums[i]);

            if (maxVal == i + 1 && nums[i] == i + 1 && locked[i] == 1) {
                validLocked++;
            }
        }

        // Minimum number of unlock operations
        int unlocks = lockedCount - validLocked;

        if (unlocks > k) {
            return -1;
        }

        // Count inversions using Fenwick Tree
        vector<int> bit(n + 1, 0);

        auto update = [&](int i) {
            while (i <= n) {
                bit[i]++;
                i += i & -i;
            }
        };

        auto query = [&](int i) {
            int sum = 0;

            while (i > 0) {
                sum += bit[i];
                i -= i & -i;
            }

            return sum;
        };

        int swaps = 0;

        for (int i = n - 1; i >= 0; i--) {
            swaps += query(nums[i] - 1);
            update(nums[i]);
        }

        return swaps + unlocks;
    }
};
