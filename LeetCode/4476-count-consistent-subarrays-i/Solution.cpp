
class Solution {
public:
    int countConsistent(vector<int>& nums) {

        int n = nums.size();
        int ans = 0;

        for(int i = 0; i < n; i++) {

            int AND = nums[i];
            int mini = nums[i];

            for(int j = i; j < n; j++) {

                AND = AND & nums[j];
                mini = min(mini, nums[j]);

                if(AND == mini) {
                    ans++;
                }
            }
        }

        return ans;
    }
};
