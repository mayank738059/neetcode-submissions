class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        unordered_map<int,int> mpp;
        if(hand.size()%groupSize!=0) return false;
        for(auto it:hand) mpp[it]++;
        sort(hand.begin(),hand.end());
        for(int num:hand){
            if(mpp[num]>0){
                for(int i=num;i<num+groupSize;i++){
                    if(mpp[i]==0) return false;
                    mpp[i]--;
                }
            }
        }
        return true;
    }
};
