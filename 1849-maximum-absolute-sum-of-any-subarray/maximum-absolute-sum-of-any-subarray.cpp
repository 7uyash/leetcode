class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0, minSum = 0;
        int currMax = 0, currMin = 0;
        
        for (int num : nums) {
            currMax += num;
            maxSum = max(maxSum, currMax);
            if (currMax < 0) currMax = 0;  // Reset for maximum subarray sum
            
            currMin += num;
            minSum = min(minSum, currMin);
            if (currMin > 0) currMin = 0;  // Reset for minimum subarray sum
        }
        
        return max(maxSum, abs(minSum));
    }
};