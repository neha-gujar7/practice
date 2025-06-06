class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0, sum2 = 0;
        for (char ch : s) sum1 += ch;
        for (char ch : t) sum2 += ch;
        return (char)(sum2 - sum1);  // ✅ Correct fix
    }
};
