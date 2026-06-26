class Solution {
public:
    int solve(int i,int n,vector<int> &dp){
        if(i==n) return 1;
        if(i>n) return 0;
        if(dp[i]!=-1) return dp[i];
        int ones=solve(i+1,n,dp);
        int twos=solve(i+2,n,dp);
        return dp[i]= ones+twos;
    }
    int climbStairs(int n) {
        if(n<=2) return n;
        vector<int> dp(n+1,0);
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }
};
