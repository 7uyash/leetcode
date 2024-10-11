class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        long long totalSum = 0;
        for (const int& num : nums) {
            totalSum += num;
        }

        int remainder = totalSum % p;
        if (remainder == 0) return 0;

        unordered_map<int, int> modIndexMap;
        modIndexMap[0] = -1;

        long long cumulativeSum = 0;
        int shortestSubarrayLength = nums.size();

        for (int index = 0; index < nums.size(); ++index) {
            cumulativeSum += nums[index];
            int currentMod = cumulativeSum % p;
            int targetMod = (currentMod - remainder + p) % p;

            if (modIndexMap.find(targetMod) != modIndexMap.end()) {
                shortestSubarrayLength = min(shortestSubarrayLength, index - modIndexMap[targetMod]);
            }

            modIndexMap[currentMod] = index;
        }

        return (shortestSubarrayLength == nums.size()) ? -1 : shortestSubarrayLength;
    }
};