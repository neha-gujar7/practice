class Solution {
public:
    int maxCandies(vector<int>& st, vector<int>& can, vector<vector<int>>& ky, vector<vector<int>>& box, vector<int>& ini) {
        // st = status
        // can = candies
        // ky = keys
        // box = containedBoxes
        // ini = initialBoxes

        int tot = 0; // cnt
        queue<int> q;

        for (auto b : ini) {
            q.push(b);
        }

        while (!q.empty()) {
            int n = q.size(); // sz
            vector<int> cur;  // curr
            vector<int> blk;  // inserted ....blk=blocked

            while (n--) {
                int b = q.front(); // box
                q.pop();
                cur.push_back(b);

                if (st[b]) {
                    tot += can[b];
                    for (auto k : ky[b]) { // k = key
                        st[k] = 1;
                    }
                    for (auto x : box[b]) { // x = other
                        q.push(x);
                    }
                } else {
                    q.push(b);
                    blk.push_back(b);
                }
            }

            if (cur == blk) {
                break;
            }
        }

        return tot;
    }
};
