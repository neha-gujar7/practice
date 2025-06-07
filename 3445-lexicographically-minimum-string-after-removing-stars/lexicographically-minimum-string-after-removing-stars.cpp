class Solution {
public:
    string clearStars(string s) {
        map<char, vector<int>> mp;
        string t = s;
        for(int i = 0; i < s.size(); i++){
            if(s[i] != '*') mp[s[i]].push_back(i);
            else{
                if(!mp.empty()){
                    int key = mp.begin()->first;
                    int value = mp.begin()->second.back();
                    t[value] = '.';
                    mp.begin()->second.pop_back();
                    if(mp.begin()->second.size() == 0){
                        mp.erase(key);
                    }
                }
                t[i] = '.';
            }
        }
        string result = "";
        for(int i = 0; i < t.size(); i++){
            if(t[i] != '.') result += t[i];
        }
        return result;
    }
};
