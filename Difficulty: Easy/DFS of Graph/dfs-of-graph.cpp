class Solution {
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        // vector<int> res(n,0);
        int n=adj.size();
         vector<int> vis(n,0);
         vector<int> res;
         solv(0,adj,res,vis);
         return res;
        
        
    }
    
    vector<int> solv(int i, vector<vector<int>>& adj, vector<int>& res, vector<int>& vis) {
        // Code here
        // vector<int> res(n,0);
        vis[i]=1;
        res.push_back(i);
        for(int u:adj[i]){
            if(!vis[u]){
                vis[u]=1;
                solv(u,adj,res,vis);
            }
        }
        return res;
        
        
    }
    
    
    
};