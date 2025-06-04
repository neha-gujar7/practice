class Solution {
public:
    string answerString(string word, int numFriends) {
        if(numFriends==1) return word;

        int wordLength = word.size();
        int ansLength = wordLength-(numFriends-1);

        char largst = 'a';
        for(char c:word) {
            largst = max(largst, c);
        }

        string ans = "";

        for(int i=0; i<wordLength; i++) {
            char c = word[i];
            if(c == largst) {
                string s = word.substr(i, ansLength);
                ans = max(ans, s);
            }
        }
        return ans;
    }
};