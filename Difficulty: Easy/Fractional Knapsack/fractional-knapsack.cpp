class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int q=capacity;
        int n=wt.size();
        vector<pair<double, pair<int,int>>> v;
        for(int i=0;i<n;i++){
            
            v.push_back({(double) val[i]/wt[i],{val[i],wt[i]}});
        }
        double ans=0;
        sort(v.rbegin(),v.rend());
        for(int i=0;i<n;i++){
            if(capacity >= v[i].second.second){
                capacity-=v[i].second.second;
                ans+=v[i].second.first;
            }
            else if(capacity==0) break;
            else{
                double x= capacity *(double) v[i].second.first/v[i].second.second;
                // capacity -=x;
                ans+=x;
                break;
                
            }
        }
        // if(capacity==q) return q*(val)
        return ans;
    }
};
