class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> fq;
        int n = nums.size();
        int j = 0;
        int i = 0;
        long long ans = 0;
        while (j < n) {
            k -= fq[nums[j++]]++;
            while (k <= 0)
                k += --fq[nums[i++]];
            ans += i;
        }
        return ans;
    }
};