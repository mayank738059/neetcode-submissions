class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> suff(n),pref(n);
        int a=1,b=1;
        suff[n-1]=1;
        pref[0]=1;
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]*nums[i-1];
            suff[n-i-1]=suff[n-i]*nums[n-i];
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=suff[i]*pref[i];
        }
        return ans;
    }
};
