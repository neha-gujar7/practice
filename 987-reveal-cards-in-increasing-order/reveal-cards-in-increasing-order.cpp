class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(), deck.end());
        int n = deck.size();
        vector<int> v(n);
        queue<int> q;
        for (int i = 0; i < n; i++) {
            q.push(i);
        }
        for (int i = 0; i < n; i++) {
            v[q.front()] = deck[i];
             q.pop();
            if (!q.empty()) {
                q.push(q.front());
                q.pop();
            }
        }
        return v;
    }
};