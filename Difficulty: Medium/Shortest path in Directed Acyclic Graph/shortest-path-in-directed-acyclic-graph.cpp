// User function Template for C++
class Solution {
	public:
	void topodfs(int nod, vector<int>& vs, vector<pair<int, int>> ad[], stack<int>& st) {
		vs[nod] = 1;
		for (auto it: ad[nod]) {
			int v = it.first;
			if (!vs[v]) {
				topodfs(v, vs, ad, st);
			}
		}
		st.push(nod);
		
	}
	
	vector<int> shortestPath(int V, int E, vector<vector<int>> & edges) {
		// code heref
		vector<pair<int, int>> ad[V];
		
		for (int i = 0; i<E; i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			int wt = edges[i][2];
			
			ad[u].push_back({v, wt});
		}
		vector<int> vs(V, 0);
		
		stack<int>st;
		for (int i = 0; i<V; i++) {
			//  int v = it.first;
			if (!vs[i]) {
				topodfs(i, vs, ad, st);
			}
		}
		
		vector<int> dst(V, 1e9);
		vector<int> ans(V, -1);
		
// 		for (int i = 0; i<V; i++) {
// 			if (dst[i] != 1e9) {
// 				ans[i] = dst[i];
// 			}
// 		}
		
		dst[0] = 0;
		while (!st.empty()) {
			int x = st.top();
			st.pop();
			for (auto it:ad[x]) {
				int v = it.first;
				int wt = it.second;
				
				if (dst[x]+wt<dst[v] && dst[x] != 1e9) {
					dst[v] = dst[x]+wt;
				}
			}
		}
		for (int i = 0; i<V; i++)
			{
			if (dst[i] == 1e9)
				dst[i] = -1;
		}
		
		return dst;
		
	}
};
