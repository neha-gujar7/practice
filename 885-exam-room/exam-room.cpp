class ExamRoom {
public:
    int N;
    set<int> st;
    ExamRoom(int n) : N(n) {}
    int seat() {
        if (st.empty()) {
            st.insert(0);
            return 0;
        }
        int ans = 0, dist = *st.begin(); // distance from 0
        int prv = -1;
        for (int s : st) {
            if (prv != -1) {
                int d = (s - prv) / 2;
                if (d > dist) {
                    dist = d;
                    ans = prv + d;
                }
            }
            prv = s;
        }
        // check last seat
        if (N - 1 - *st.rbegin() > dist) {
            ans = N - 1;
        }
        st.insert(ans);
        return ans;
    }
    void leave(int p) {
        st.erase(p);
    }
};
