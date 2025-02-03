class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int increasing=1;
        int decreasing=1;
        int ans=1;
        for(int i{1};i<n;i++){
            if(nums[i]>nums[i-1]){
                decreasing=1;
                increasing++;
            }else if(nums[i]<nums[i-1]){
                increasing=1;
                decreasing++;
            }else{
                increasing=1;
                decreasing=1;
            }
            ans=max(ans,max(increasing,decreasing));
        }
        return ans;
    
    }
};