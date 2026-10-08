class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // code here
		int n = matrix.size();
		int m = matrix[0].size();
		vector<pair<int, int>> v;
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
				if (matrix[i][j] == 0) {
					v.push_back({i, j});
				}
			}
		}
		
		for (int i = 0; i<n; i++) {
			for (int j = 0; j<m; j++) {
			    for(int k=0;k<v.size();k++){
			        if(v[k].first==i || v[k].second==j){
			             matrix[i][j]=0;
			        }
			    }
				
			}
		}
		
    }
};