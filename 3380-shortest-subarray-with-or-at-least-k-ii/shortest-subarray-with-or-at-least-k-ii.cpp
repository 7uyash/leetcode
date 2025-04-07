class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0, j = 0, res = INT_MAX;
        int orValue = 0;
        if (target == 0)
            return 1;
        vector<int> mp(32, 0);
        // mp[i] = total number of setbits in ith position
        while (j < n) {
            orValue |= nums[j];
            for (int k{}; k < 32; k++) {
                mp[k] += ((nums[j] >> k) & 1);
            }
            while (orValue >= target && orValue != 0) {
                res = min(res, (j - i + 1));
                for (int k{}; k < 32; k++) {
                    mp[k] -= ((nums[i] >> k) & 1);
                }
                int newOrValue = 0;
                for (int k{}; k < 32; k++) {
                    if (mp[k] > 0)
                        newOrValue = (newOrValue | (1 << k));
                }
                orValue = newOrValue;
                i++;
            }
            j++;
        }
        return (res == INT_MAX) ? -1 : res;
    }
};