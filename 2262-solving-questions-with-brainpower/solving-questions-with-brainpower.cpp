class Solution {
public:
    long long solve(int ind, vector<vector<int>>& q, vector<long long>& dp) {
        int n = q.size();
        if (ind >= n)
            return 0;
        if (dp[ind] != -1)
            return dp[ind];

        long long pick = q[ind][0] + solve(ind + q[ind][1] + 1, q, dp);
        long long notpick = solve(ind + 1, q, dp);

        return dp[ind] = max(pick, notpick);
    }

    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, -1);
        
        dp[n - 1] = questions[n - 1][0];

        for (int ind = n - 2; ind >= 0; ind--) {
            long long pick = questions[ind][0];
            int index = questions[ind][1] + 1;
            if (ind + index < n)
                pick += dp[ind + index];
            long long notpick = dp[ind + 1];
            dp[ind] = max(pick, notpick);
        }

        return dp[0];   
    }
};