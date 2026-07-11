class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int,char>> pq;

        if(a > 0) pq.push({a, 'a'});
        if(b > 0) pq.push({b, 'b'});
        if(c > 0) pq.push({c, 'c'});

        string s;

        while(!pq.empty()) {

            auto [fq1, ch1] = pq.top();
            pq.pop();

            if(s.size() >= 2 &&
               s[s.size()-1] == ch1 &&
               s[s.size()-2] == ch1) {

                if(pq.empty()) break;

                auto [fq2, ch2] = pq.top();
                pq.pop();

                s += ch2;
                fq2--;

                if(fq2 > 0)
                    pq.push({fq2, ch2});

                pq.push({fq1, ch1});
            }
            else {
                s += ch1;
                fq1--;

                if(fq1 > 0)
                    pq.push({fq1, ch1});
            }
        }

        return s;
    }
};