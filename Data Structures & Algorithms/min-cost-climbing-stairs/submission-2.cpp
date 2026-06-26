class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int> dp(n);

        dp[0] = cost[0];

        for(int i = 1; i < n; i++) {
            int ones = cost[i] + dp[i-1];
            int twos = cost[i];

            if(i > 1)
                twos = cost[i] + dp[i-2];

            dp[i] = min(ones, twos);
        }

        return min(dp[n-1], dp[n-2]);
    }
};