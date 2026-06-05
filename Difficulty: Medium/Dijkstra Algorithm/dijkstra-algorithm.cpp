class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<pair<int,int>> ad[V];
        set<pair<int,int>> st;
        for(auto &i:edges){
            int u=i[0];
            int v=i[1];
            int wt=i[2];
            ad[u].push_back({v,wt});
                        ad[v].push_back({u,wt});
                        

        }
        vector<int> dst(V,1e9);
        dst[src]=0;
        st.insert({0,src});
        while(!st.empty()){
            auto it=*(st.begin());
            int dis=it.first;
            int nod=it.second;
            // pq.pop();
            st.erase(it);
            for(auto x:ad[nod]){
                int egwt=x.second ;
                int egnod=x.first;
                if(dis+egwt < dst[egnod]){
                    if(dst[egnod]!=1e9){
                        st.erase({dst[egnod],egnod});
                    }
                    dst[egnod]=dis+egwt;
                    st.insert({dst[egnod],egnod});
                }
            }
            
            
            
            
            
        }
        return dst;
        //tc-> O(E log V)
        //Space Complexity: O(V + E)
    }
};