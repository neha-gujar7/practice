class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> nsl(n, -1);
        vector<int> nsr(n, n);
        stack<pair<int, int>> st;
        for (int i = 0; i < n; i++) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nsl[i] = st.top().second;
            }
  
            st.push({heights[i], i});
        }

        while (!st.empty()) {
            st.pop();
        }
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top().first >= heights[i]) {
                st.pop();
            }
            if (!st.empty()) {
                nsr[i] = st.top().second;
            }

          
            st.push({heights[i], i});
        }

        int maxi = 0;
        for (int i = 0; i < n; i++) {
            // int maxi=0;
            int wid = nsr[i] - nsl[i] - 1;
            int area = wid * heights[i];
            maxi = max(maxi, area);
        }
        return maxi;
    }
};