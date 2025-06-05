class Solution {
public:
    int find(int x, vector<int>& parent) {
        if (x != parent[x]) {
            parent[x] = find(parent[x], parent);
        }
        return parent[x];
    }

    void unite(int a, int b, vector<int>& parent) {
        int pa = find(a, parent);
        int pb = find(b, parent);
        if (pa == pb) return;
        // Always keep the smaller character as parent
        if (pa < pb) {
            parent[pb] = pa;
        } else {
            parent[pa] = pb;
        }
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector<int> parent(26);
        for (int i = 0; i < 26; ++i) {
            parent[i] = i;
        }

        for (int i = 0; i < s1.size(); ++i) {
            unite(s1[i] - 'a', s2[i] - 'a', parent);
        }

        int x = 0;
        for (int i = 0; i < baseStr.size(); i++) {
            baseStr[x] = find(baseStr[x] - 'a', parent) + 'a';
            x++;
        }

        return baseStr;
    }
};
