class Solution {
  public:
    int minSteps(vector<int>& arr, int start, int end) {
        // code here
        if (start == end) return 0;
        vector<int> dst(1000,1e9);
        dst[start] = 0;
        queue<pair<int,int>> q;
        q.push({0,start});
        
        while(!q.empty()){
            auto x=q.front();
            q.pop();
            int stps=x.first;
            int num=x.second ;
            for(auto i:arr){
                int nxt = (num *i) % 1000;
               
                if(stps + 1 < dst[nxt]){
                     if(end == nxt) return stps+1;
                    dst[nxt]=stps+1;
                    q.push({dst[nxt],nxt});
                }
            }
        }
        
        return -1;
    }
};