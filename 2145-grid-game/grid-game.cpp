class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long ans = 1e18, suf = 0, pre = 0;

        for(auto i : grid[0])suf += i;

        for(int i = 0;i < grid[0].size() ;i++){
            suf -= grid[0][i];

            if(i)
                pre += grid[1][i - 1];

            ans = min(ans, max(pre, suf));
        }

        return ans;
    }
};