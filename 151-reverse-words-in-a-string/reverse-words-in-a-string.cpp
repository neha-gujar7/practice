class Solution {
public:
    string reverseWords(string s) {

        // reverseeeeeee the whole string
        reverse(s.begin(), s.end());

        string ans = "";
        int n = s.length();
        int i = 0;

        while (i < n) {

            // skip extra spaces
            while (i < n && s[i] == ' ')
                i++;

            if (i >= n)  break;
            string word = "";
            // each word
            while (i < n && s[i] != ' ') {
                word += s[i];
                i++;
            }
            //reverseeeeeeee
            reverse(word.begin(), word.end());

            // one space between wordss
            if (!ans.empty())
                ans += ' ';

            ans += word;
        }

        return ans;
    }
};