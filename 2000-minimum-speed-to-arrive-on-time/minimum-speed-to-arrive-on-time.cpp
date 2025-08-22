class Solution {
public:
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size() - 1;
        if(hour <= n) return -1;

        auto arrive_t = [&](int speed) -> bool {
            double time = 0;
            for(int i = 0; i < n; ++i){
                time += (dist[i] - 1) / speed + 1;  // ceil trick
            }
            time += double(dist[n]) / speed;        // last train
            return time <= hour;
        };

        int l = 1, h = 1e7;
        while(l < h){
            int mid = (h + l) / 2;
            if(arrive_t(mid)) h = mid;
            else l = mid + 1;
        }
        return l;
    }
};
