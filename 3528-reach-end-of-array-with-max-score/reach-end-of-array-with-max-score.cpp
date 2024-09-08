class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n = nums.size();
        long long answer = 0;
        int lastIndex = 0; 
        int l = nums[0];
        
    
        for (int i = 1; i < n; i++) {
            if (nums[i] > l) { 
                answer += l * 1ll * (i - lastIndex);
                l = nums[i];
                lastIndex = i; 
            }
        }
        answer += l * 1ll * (n - 1 - lastIndex);
        return answer;
    }
};