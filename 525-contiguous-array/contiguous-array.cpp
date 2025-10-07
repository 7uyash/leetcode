class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSumMap;
        prefixSumMap[0] = -1;
        
        int maxLength = 0;
        int prefixSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            prefixSum += (nums[i] == 0) ? -1 : 1;
            
            if (prefixSumMap.find(prefixSum) != prefixSumMap.end()) {
                int length = i - prefixSumMap[prefixSum];
                maxLength = std::max(maxLength, length);
            } else {
                prefixSumMap[prefixSum] = i;
            }
        }
        
        return maxLength;
    }
};