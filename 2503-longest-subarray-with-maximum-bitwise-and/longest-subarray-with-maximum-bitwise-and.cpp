class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal =  *max_element(nums.begin(), nums.end());

        int longestLength =  0;
        int currentLength = 0;
        for(int num : nums){
            if(num==maxVal){
                currentLength++;
            }else{
                longestLength = max(longestLength, currentLength);
                currentLength = 0;
            }
        }
        longestLength = max(longestLength, currentLength);
        return longestLength;
    }
};