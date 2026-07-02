class Solution {
   public:
    int jump(vector<int>& nums) {
        int jumps = 0, currentEnd = 0, farthest = 0;

        // Traverse through the array (excluding the last element)
        for (int i = 0; i < nums.size() - 1; ++i) {
            // Update the farthest index that can be reached so far
            farthest = max(farthest, i + nums[i]);

            // When we reach the end of the current jump range
            if (i == currentEnd) {
                // We need to make a jump
                jumps++;

                // Move the current end to the farthest index we can reach
                currentEnd = farthest;
            }
        }
        return jumps;
    }
};
