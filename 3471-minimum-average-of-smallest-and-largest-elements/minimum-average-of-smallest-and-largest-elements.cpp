class Solution {  
public:  
    double minimumAverage(std::vector<int>& nums) {  
        sort(nums.begin(), nums.end());  
        int n = nums.size();  
        double minAvg = numeric_limits<double>::max();  

        for (int i = 0; i < n / 2; ++i) {  
            double average = (nums[i] + nums[n - 1 - i]) / 2.0;  
            minAvg = std::min(minAvg, average);  
        }  

        return minAvg;  
    }  
};