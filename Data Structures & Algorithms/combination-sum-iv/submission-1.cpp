class Solution {
public:
    int solve(vector<int>& nums, int target, vector<int>& dp) {
        if(target == 0) return 1;

        if(dp[target] != -1)
            return dp[target];

        int ans = 0;

        for(int x : nums) {
            if(x <= target) {
                ans += solve(nums, target - x, dp);
            }
        }

        return dp[target] = ans;
    }

    int combinationSum4(vector<int>& nums, int target) {
        vector<int> dp(target + 1, 0);
        dp[0]=1;
        for(int i=1;i<=target;i++){
            for(int x : nums) {
            if(x <= i) {
                dp[i] += dp[i-x];
            }
        }
        }
        return dp[target];
    }
};