class Solution {
public:
    long long countSubarrays(vector<int>& a, int mn, int mx) {
        int n = a.size();
        long count = 0;
        for (int i = 0, mni = -1, mxi = -1, s = -1; i < n; ++i) {
            const int ai = a[i];
            if (ai == mn) mni = i; // min index
            if (ai == mx) mxi = i; // min index
            else if (ai < mn || ai > mx) s = i; // split index
            count += max(min(mni, mxi) - s, 0);
        }
        return count;
    }
};