class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //using index as the frequency of elements
        int n=nums.size();
        map<int,int> mpp;
        for(auto it:nums) mpp[it]++;
        vector<vector<int>> bucket(n+1);
        //index is frequency, value as elements
        for(auto it:mpp){
            int e=it.first;
            int freq=it.second;
            bucket[freq].push_back(e);
        }
        vector<int> ans;
        for(int  i=n;i>=0;i--){
            if(bucket[i].size()==0) continue;
            while(bucket[i].size()>0 and k>0){
                ans.push_back(bucket[i].back());
                bucket[i].pop_back();
                k--;
            }
        }
        return ans;
    }
};
