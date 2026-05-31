class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> st;
        int maxi=0;
        for(int i=0;i<n;i++){
            while(!st.empty() and heights[st.top()]>=heights[i]) {
                int element=heights[st.top()];
                st.pop();
                int nse=i,pse=st.empty()?-1:st.top();
                maxi=max(maxi,element*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int elm=heights[st.top()];
            st.pop();
            int nse=n,pse=st.empty()?-1:st.top();
            maxi=max(maxi,elm*(nse-pse-1));
        }
        return maxi;
    }
};