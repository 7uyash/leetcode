class Solution {
public:
    int dp[201][20001];

    bool solve(vector<int>& nums, int i, int x) {
        if (x == 0)
            return true;

        if (i >= nums.size())
            return false;

        if (dp[i][x] != -1)
            return dp[i][x];

        bool take = false;
        if (nums[i] <= x)
            take = solve(nums, i + 1, x - nums[i]);

        bool not_take = solve(nums, i + 1, x);

        return dp[i][x] = (take || not_take);
    }

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        memset(dp, -1, sizeof(dp));

        for (auto& n : nums)
            sum += n;

        if (sum % 2 != 0)
            return false;

        return solve(nums, 0, sum / 2);
    }
};