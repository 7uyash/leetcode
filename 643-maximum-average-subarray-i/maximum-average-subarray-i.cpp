class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n = nums.size();
        double maxS = 0.0;
        double currentS = 0.0;

        for (int i = 0; i < k; i++) {
            currentS += nums[i];
        }
        maxS = currentS;

        for (int i = k; i < n; i++) {
            currentS += nums[i] - nums[i - k];
            maxS = max(maxS, currentS);
        }

        return maxS / k;
    }
};