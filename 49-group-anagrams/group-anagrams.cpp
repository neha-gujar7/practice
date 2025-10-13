class Solution {
public:
    bool ana(string s, string t) {
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        if (s == t)
            return true;
        return false;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(string s:strs){
           string key = s;
            sort(key.begin(), key.end());
            mp[key].push_back(s);
        }

        for(auto p:mp){
            res.push_back(p.second);
        }

return res;

    }
};