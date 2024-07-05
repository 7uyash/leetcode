class Solution {
public:
int f(int x, vector<int>& nums){
    int count =0;
    for(int i = 0; i<x; i++){
        if(nums[i]==nums[x]){
            count +=1;
        }
    }
    return count;
}
    int numIdenticalPairs(vector<int>& nums) {
        int n= nums.size();
        int ans=0;
        for(int x=0; x<n; x++){
            ans+= f(x, nums);
        }
        return ans;

    }
};