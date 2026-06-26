class Solution {
   public:
    int solve(vector<int> nums) {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = nums[0];
        for (int i = 1; i < n; i++) {
            int rob = nums[i];
            if (i > 1) rob += +dp[i - 2];
            int notrob = dp[i - 1];
            dp[i] = max(rob, notrob);
        }
        return dp[n - 1];
    }
    int rob(vector<int>& nums) {
        vector<int> a,b;
        int n = nums.size();
        if(n == 1) return nums[0];
        for(int i=0;i<n;i++){
            if(i!=0) a.push_back(nums[i]);
            if(i!=n-1) b.push_back(nums[i]);
        }
        return max(solve(a),solve(b));
    }
};
