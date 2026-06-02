class Solution {
	public:
// we cant use topo sort, because in undirected graph, most of 
	vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
		// code here
		vector<pair<int, int>> ad[V];
		int e = edges.size();
		queue<int> q;
			q.push(src);
		for (auto i: edges) {
			ad[i[0]].push_back({i[1], 1});
			ad[i[1]].push_back({i[0], 1});
			
		}
		
		vector<int> vs(V, 0);
		
// 		stack<int>st;
	
		
		vector<int> dst(V, -1);
		dst[src]=0;
	
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for(auto it:ad[x]){
			    int v=it.first;
			    if(dst[v]==-1){
			        dst[v]=dst[x]+1;
			        q.push(v);
			    }
			}
		}
		
// 		for (int i = 0; i<V; i++) {
// 			if (dst[i] == 1e9)
// 				dst[i] = -1;
// 		}
		return dst;
		
	}
};
