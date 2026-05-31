class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;
        for(auto it : nums){
            mpp[it]++;
        }
        typedef pair<int, int> P;
        priority_queue<P,vector<P>,greater<P>> pq;
        for(auto it:mpp){
            int value=it.first;
            int freq=it.second;
            pq.push({freq,value});
            if(pq.size()>k) pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){ ans.push_back(pq.top().second); pq.pop();}
        return ans;
    }
};