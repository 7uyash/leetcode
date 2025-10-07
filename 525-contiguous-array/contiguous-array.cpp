class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> preSumMap;
        preSumMap[0] = -1;
        
        int maxLength = 0;
        int preSum = 0;
        
        for (int i = 0; i < nums.size(); ++i) {
            preSum += (nums[i] == 0) ? -1 : 1;
            
            if (preSumMap.find(preSum) != preSumMap.end()) {
                int length = i - preSumMap[preSum];
                maxLength = max(maxLength, length);
            } else {
                preSumMap[preSum] = i;
            }
        }
        
        return maxLength;
    }
};