class Solution {
public:
    
    int maximumScore(vector<int>& a, int k) {
        int m = 1e9+7, n = size(a), res = 1; vector<int> sc(n), sl, sr, l(n, -1), r(n, n);
        for(int i = 0; i < n; ++i) {
            int x = a[i], c = 0; for (int p = 2; p * p <= x; p++) 
                if (x % p == 0) { c++; while (x % p == 0) x /= p; }
            sc[i] = c + (x > 1);
        }
        for (int i = 0, j; i < size(a); i++) {
            for (j = size(a) - 1 - i; size(sl) && sc[sl.back()] < sc[i]; sl.pop_back());
            for (; size(sr) && sc[sr.back()] <= sc[j]; sr.pop_back());
            if (size(sl)) l[i] = sl.back(); sl.push_back(i);
            if (size(sr)) r[j] = sr.back(); sr.push_back(j);
        }
        vector<int> idx(size(a)); iota(begin(idx), end(idx), 0);
        sort(begin(idx), end(idx), [&](int i, int j) { return a[i] > a[j]; });
        for (int i : idx) {
            long range = 1LL * (i - l[i]) * (r[i] - i);
            long x = 1LL * a[i],  e = min(1L * k, range);
            for (; e; e /= 2, x = (x * x) % m) if (e & 1) res = (res * x) % m;
            if ((k -= range) < 1) break;
        }
        return res;
    }
};