class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        int cur = 0;
        vector<long long> mx(n);
        for (int i = n - 1; i >= 0; i--) {
            mx[i] = cur;
            cur = max(cur, nums[i]);
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                long long a = nums[i];
                long long b = nums[j];
                long long c = mx[j];
                ans = max(ans, (a - b) * c);
            }
        }
        return ans; 
    }
};