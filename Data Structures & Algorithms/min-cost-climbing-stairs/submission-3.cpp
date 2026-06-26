class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        int prev=0,curr=0;

        curr = cost[0];

        for(int i = 1; i < n; i++) {
            int ones = cost[i] + curr;
            int twos = cost[i];

            if(i > 1)
                twos = cost[i] + prev;

            int temp = min(ones, twos);
            prev=curr;
            curr=temp;
        }

        return min(prev,curr);
    }
};