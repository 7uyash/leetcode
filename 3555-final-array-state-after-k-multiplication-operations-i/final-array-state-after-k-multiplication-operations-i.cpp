class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        for (int i = 0; i < k; ++i) {  
            int minIndex = -1;  
            int minValue = std::numeric_limits<int>::max();  
 
            for (int j = 0; j < nums.size(); ++j) {  
                if (nums[j] < minValue) {  
                    minValue = nums[j];  
                    minIndex = j;  
                }  
            }   
            if (minIndex != -1) {  
                nums[minIndex] = minValue * multiplier;  
            }  
        }  
        
        return nums;
    }
};