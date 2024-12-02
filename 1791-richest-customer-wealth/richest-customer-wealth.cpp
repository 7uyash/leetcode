class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxW = 0;
        for(const auto& account : accounts){
            int wealth = accumulate(account.begin(), account.end(), 0);
                maxW = max(maxW, wealth);
            

        }
        return maxW;
    }
};