class Solution {
public:
    vector<int> ans=vector<int>(3,0);
    int helper(int i,int count,int k,vector<int>& sumarr,vector<vector<int>> &dp){
        if(count==0) return 0;
        if(i>=sumarr.size()) return INT_MIN;
        if(dp[i][count]!=-1) return dp[i][count];

        int take=sumarr[i]+helper(i+k,count-1,k,sumarr,dp);
        int nottake=helper(i+1,count,k,sumarr,dp);

        return dp[i][count]=max(take,nottake);
    }
    void solve(int i,int count,int k,vector<int>& sumarr,vector<vector<int>> &dp){
        if(count==0) return;

        int take=sumarr[i]+helper(i+k,count-1,k,sumarr,dp);
        int nottake=helper(i+1,count,k,sumarr,dp);

        if(take>=nottake){
            ans[3-count]=i;
            solve(i+k,count-1,k,sumarr,dp);
        }else{
            solve(i+1,count,k,sumarr,dp);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> sumarr(n-k+1,0);
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        sumarr[0]=sum;
        for(int i=1;i<=n-k;i++){
            sum-=nums[i-1];
            sum+=nums[i+k-1];
            sumarr[i]=sum;
        }
        vector<vector<int>> dp(sumarr.size()+1,vector<int>(4,-1));
        
        solve(0,3,k,sumarr,dp);
        return ans;  
    }
};