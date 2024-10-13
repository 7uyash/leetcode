class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
         priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;  
        int maxNum = numeric_limits<int>::min();  
        int rangeStart = 0, rangeEnd = numeric_limits<int>::max();  
        vector<int> index(nums.size(), 0);  
        
        for (int i = 0; i < nums.size(); ++i) {  
            minHeap.push({nums[i][0], i});  
            maxNum = max(maxNum, nums[i][0]);  
        }  
        
        while (minHeap.size() == nums.size()) {  
            auto [minNum, listIndex] = minHeap.top();  
            minHeap.pop();  
            if (maxNum - minNum < rangeEnd - rangeStart) {  
                rangeStart = minNum;  
                rangeEnd = maxNum;  
            }  
            if (++index[listIndex] < nums[listIndex].size()) {  
                minHeap.push({nums[listIndex][index[listIndex]], listIndex});  
                maxNum = max(maxNum, nums[listIndex][index[listIndex]]);  
            }  
        }  
        
        return {rangeStart, rangeEnd};
    }
};