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
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=0;
        // int area=0;
        vector<int> h(m,0);

        if(matrix.empty()) return 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    h[j]+=1;
                }
                else{
                    h[j]=0;
                }
            }
            int area=largestRectangleArea(h);
            ans=max(area,ans);
        }
        return ans;
    }
    
};