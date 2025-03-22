class Solution {
    static void cooking(const vector<string>& a, const vector<vector<string>>& b, const unordered_set<string>& s, unordered_map<string, int>& r, int i) {
        for (const string& t : b[i]) {
            if (s.contains(t)) continue; // has ingredient
            int j = r.contains(t) ? r[t] : -2;
            if (j >= 0) {     // not cooked
                r[a[i]] = -2; // cooking
                cooking(a, b, s, r, j);
                j = r[t];
            }
            if (j == -1) continue; // cooked
            r[a[i]] = -2; // cant cooked or absent
            return;
        }
        r[a[i]] = -1;
    }

public:
    static vector<string> findAllRecipes(const vector<string>& a, const vector<vector<string>>& b, const vector<string>& c) {
        const int n = a.size();
        const unordered_set<string> s(c.cbegin(), c.cend());
        unordered_map<string, int> r; // -2 cooking or cant cooked, -1 cooked, 0..n-1 - index
        for (int i = 0; i < n; ++i) r[a[i]] = i; // r = 0..n-1
        vector<string> ans;
        for (int i = 0; i < n; ++i) {
            int j = r[a[i]];
            if (j >= 0) {
                cooking(a, b, s, r, i); // r = -1 || -2
                j = r[a[i]];
            }
            if (j == -1) ans.push_back(a[i]);
        }
        return ans;
    }
};