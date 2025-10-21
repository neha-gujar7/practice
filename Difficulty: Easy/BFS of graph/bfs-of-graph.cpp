class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        
         int n = adj.size();          // number of vertices
        vector<int> bfs;             // stores BFS traversal
        vector<int> vis(n,0);       // visited array
        queue<int> q;
        vis[0]=1;
       
        q.push(0);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto& i: adj[node]){
                if(!vis[i]){
                    vis[i]=1;
                    q.push(i);
                    
                }
            }
        }
        return bfs;
       
    }
};