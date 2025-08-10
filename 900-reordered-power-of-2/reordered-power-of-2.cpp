class Solution {
public:
    bool reorderedPowerOf2(int n) {
        set<string> ans;

        for(int i=0;i<31;i++){
            int power=1<<i;
            string s=to_string(power);
            sort(s.begin(),s.end());
            ans.insert(s);
        }


        string num_str=to_string(n);
        sort(num_str.begin(),num_str.end());

        return ans.count(num_str)>0;

        
    }
};