class MyCalendar {
public:
    map<int, int> mp;

    MyCalendar() {}

    bool book(int s, int e) {
        mp[s]++;
        mp[e]--;
        int cnt = 0;
        for (auto p : mp) {
            cnt += p.second;
            if (cnt > 1) {
                mp[s]--;
                mp[e]++;
                if (mp[s] == 0) mp.erase(s);
                if (mp[e] == 0) mp.erase(e);
                return false;
            }
        }
        return true;
    }
};
