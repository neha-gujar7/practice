class DSU {
public:
    vector<int> p;

    DSU(int n) {
        p.resize(n);
        for (int i = 0; i < n; i++)
            p[i] = i;
    }

    int find(int x) {
        if (p[x] == x)
            return x;
        return p[x] = find(p[x]);
    }

    void unite(int a, int b) {
        int pa = find(a);
        int pb = find(b);

        if (pa == pb) return;

        if (pa < pb)
            p[pb] = pa;
        else
            p[pa] = pb;
    }

    void reset(int x) {
        p[x] = x;
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        sort(meetings.begin(), meetings.end(),
             [](vector<int>& a, vector<int>& b) {
                 return a[2] < b[2];
             });

        DSU d(n);

        // person 0 and firstPerson know the secret
        d.p[firstPerson] = 0;

        for (int i = 0; i < meetings.size(); i++) {
            int j = i;

            // unite all meetings at same time
            while (j < meetings.size() && meetings[i][2] == meetings[j][2]) {
                d.unite(meetings[j][0], meetings[j][1]);
                j++;
            }

            // reset those not connected to 0
            for (int k = i; k < j; k++) {
                int u = meetings[k][0];
                int v = meetings[k][1];

                if (d.find(u) != 0)
                    d.reset(u);
                if (d.find(v) != 0)
                    d.reset(v);
            }

            i = j - 1;
        }

        vector<int> res;
        for (int i = 0; i < n; i++) {
            if (d.find(i) == 0)
                res.push_back(i);
        }

        return res;
    }
};
