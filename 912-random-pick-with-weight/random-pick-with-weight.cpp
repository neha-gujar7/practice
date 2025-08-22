// class Solution {
// public:
//     Solution(vector<int>& w) {
        
//     }
    
//     int pickIndex() {
        
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
 class Solution {
public:
    vector<int> prefix;
    int total;

    Solution(vector<int>& w) {
        int sum = 0;
        for(int x : w){
            sum += x;
            prefix.push_back(sum); // directly push prefix sums
        }
        total = sum;
    }
    
    int pickIndex() {
        int randNum = rand() % total + 1; // random from [1, total]
        
        // binary search manually
        int l = 0, r = prefix.size()-1;
        while(l < r){
            int mid = (l + r) / 2;
            if(prefix[mid] < randNum)
                l = mid + 1;
            else
                r = mid;
        }
        return l; // index found
    }
};
