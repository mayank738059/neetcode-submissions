class Solution {
public:
    int solve(int i,vector<int> &nums){
        if(i<0) return 0;
        if(i==0) return nums[0];
        int rob=nums[i]+solve(i-2,nums);
        int notrob=solve(i-1,nums);
        return max(rob,notrob);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        for(int i=1;i<n;i++){
            int rob=nums[i];
            if(i>1) rob+=+dp[i-2];
            int notrob=dp[i-1];
            dp[i]= max(rob,notrob);
        }
        return dp[n-1];
    }
};
