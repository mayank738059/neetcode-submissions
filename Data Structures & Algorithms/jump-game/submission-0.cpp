class Solution {
public:
    bool canJump(vector<int>& nums) {
        int cnt=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(cnt<i) return false;
            cnt=max(cnt,i+nums[i]);
        }
        return true;
    }
};
