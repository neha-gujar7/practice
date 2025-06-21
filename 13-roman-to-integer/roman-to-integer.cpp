class Solution {
public:
    int romanToInt(string s) {
        map<char, int> mp;
        mp['I'] = 1;
        mp['V'] = 5;
        mp['X'] = 10;
        mp['L'] = 50;
        mp['C'] = 100;
        mp['D'] = 500;
        mp['M'] = 1000;

        int res = 0;
        int i = 0;
        int length = s.length();
        while(i<length ){
            if( i+1<length && mp[s[i]]<mp[s[i+1]]){
                res+=mp[s[i+1]]-mp[s[i]];
                i+=2;
            }
            else{
                res+=mp[s[i]];               
                i++;
            }
            
        }
return res;
        // while(i < length) {
        //     if(i + 1 < length && mp[s[i]] < mp[s[i + 1]]) {
        //         result += mp[s[i + 1]] - mp[s[i]];
        //         i += 2;
        //     } else {
        //         result += mp[s[i]];
        //         i++;
        //     }
        // }

        // return result;
    }
};
