class Solution {
	public:
	void bfs(int V, vector<int> ad[], vector<int>& topo) {
		vector<int> deg(V, 0);
		for (int i = 0; i<V; i++) {
			for (auto x:ad[i]) {
				deg[x]++;
			}
		}
		queue<int> q;
		for (int i = 0; i<V; i++) {
			if (deg[i] == 0) {
				q.push(i);
			}
		}
		
		while (!q.empty()) {
			int p = q.front();
			q.pop();
			topo.push_back(p);
			for (auto x:ad[p]) {
				deg[x]--;
				if (deg[x] == 0) {
					q.push(x);
				}
			}
		}
	}
	
	string findOrder(vector<string> &words) {
		// code here
		// need to conevrt to adj list.....
		
		int n = words.size();
		set<char> s;
		for (int i = 0; i<words.size(); i++) {
			for (int j = 0; j<words[i].size(); j++) {
				s.insert(words[i][j]);
			}
		}
		vector<int> ad[26];
		for (int i = 0; i<n - 1; i++) {
			string s1 = words[i];
			string s2 = words[i + 1];
			
			bool flag = false;
			
			for (int j = 0; j < min(s1.size(), s2.size()); j++) {
				
				if (s1[j] != s2[j]) {
					
					ad[s1[j]-'a'].push_back(s2[j]-'a');
					
					flag = true;
					break;
				}
			}
			
			if (flag == false && s1.size()>s2.size()) {
				return "";
			}
		}
		vector<int> topo;
		
		bfs(26, ad, topo);
		string ans;
		for (int i = 0; i<topo.size(); i++)
			{
			if (s.find(topo[i]+'a') != s.end()) {
				ans += (topo[i]+'a');
			}
			
		}
		
		// dont forget to compare with s.size, but not with n, take care of it :)
		if (ans.size() == s.size())
			return ans;
		return "";
		
	}
};
