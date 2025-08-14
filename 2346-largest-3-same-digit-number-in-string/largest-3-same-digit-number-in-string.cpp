class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        vector<int> digits;

        for (char c : num) {
            digits.push_back(c - '0'); // convert char digit to int
        }

         vector<int> v;
        for (int i = 1; i < n - 1; i++) {
            if(digits[i-1] ==digits[i] && digits[i] ==digits[i+1] ){
                 v.push_back((100*digits[i-1])+(10*digits[i])+digits[i+1]);
            }
           
        }
         if (v.empty()) return "";

        int maxi=INT_MIN;
        for(int i=0;i<v.size();i++){
            maxi=max(maxi,v[i]);
        }
        string ans=to_string(maxi);
         while (ans.size() < 3) ans = "0" + ans;

        return ans;
    }
};