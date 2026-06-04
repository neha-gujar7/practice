class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<pair<int,int>> ad[V];
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            ad[u].push_back({v,wt});
                        ad[v].push_back({u,wt});
                        

        }
        vector<int> dst(V,1e9);
        dst[src]=0;
        pq.push({0,src});
        while(!pq.empty()){
            int dis=pq.top().first;
            int nod=pq.top().second;
            pq.pop();
            for(auto it:ad[nod]){
                int adnod=it.first;
                int egwt=it.second;
                if(dis+egwt < dst[adnod] ){
                    dst[adnod]=dis+egwt;
                    pq.push({dst[adnod],adnod});
                }
                
            }
            
        }
        return dst;
    }
};