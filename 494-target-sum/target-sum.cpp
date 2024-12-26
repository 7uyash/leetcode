class Solution {
public:
    int solve(vector<int>& nums , int target ,int index , int sum){
       if(index == nums.size()){
        if(sum == target){
             return 1;
            }
           return 0;
        }
        int add;
        int sub;
        for(int i=0;i<2;i++){
            if(i==0){
                add =  solve(nums,target,index+1,sum+nums[index]);
            }
            else{
               sub = solve(nums,target,index+1,sum-nums[index]);
            }
        }
        return  add + sub;
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(nums,target,0,0);
        
    }
};