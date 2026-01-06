class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
    vector<int> res;
    vector<int> vis(n, 0);
    queue<int> q;
    
    q.push(0);
    vis[0]=1;
    
    
    while(!q.empty()){
        int node=q.front();
        q.pop();
        res.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                vis[it]=1;
                q.push(it);
            }
        }
    }
    return res;
    
        
    }
    
    
};